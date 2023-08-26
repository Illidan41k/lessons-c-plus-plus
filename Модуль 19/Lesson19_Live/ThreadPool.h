#pragma once
#include <queue>
#include <mutex>
#include <future>
#include <unordered_set>

class ThreadPool
{

public:
	ThreadPool(int numberOfWorkers);
	
	template <typename Func, typename ...Args>
	int64_t add_task(const Func& taskFunction, Args&&... args);

	void Wait(int64_t task_id);
	void WaitAll();
	bool Done(int64_t task_id);

	~ThreadPool();


private:
	void run();
	std::vector<std::thread> m_threads;

	std::queue<std::pair<std::future<void>, int64_t>> m_incomingTasks;
	std::mutex m_tasksMutex;

	std::condition_variable m_taskCompletedNotification;
	std::condition_variable newTaskAddedNotification;

	std::atomic<int64_t> m_nextTaskIndex = 0;
	std::unordered_set<int64_t> m_completedTasksIds;
	std::mutex m_completedTasksMutex;

	std::atomic<bool> m_quit{ false };
};


template<typename Func, typename ...Args>
inline int64_t ThreadPool::add_task(const Func& taskFunction, Args && ...args)
{
	int64_t task_idx = m_nextTaskIndex++;

	std::lock_guard<std::mutex> lock(m_tasksMutex);
	m_incomingTasks.emplace(std::async(std::launch::deferred, taskFunction, args...), task_idx);

	newTaskAddedNotification.notify_one();
	return task_idx;
}
