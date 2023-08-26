#include "ThreadPool.h"

ThreadPool::ThreadPool(int numberOfWorkers)
{
    m_threads.reserve(numberOfWorkers);

    for (uint32_t i = 0; i < numberOfWorkers; ++i)
    {
        m_threads.emplace_back(&ThreadPool::run, this);
    }
}


void ThreadPool::Wait(int64_t task_id)
{
    std::unique_lock<std::mutex> lock(m_completedTasksMutex);

    m_taskCompletedNotification.wait(lock, [this, task_id]()->bool {
        return m_completedTasksIds.find(task_id) != m_completedTasksIds.end();
        });
}

void ThreadPool::WaitAll()
{
    std::unique_lock<std::mutex> lock(m_tasksMutex);

    m_taskCompletedNotification.wait(lock, [this]()->bool {
        std::lock_guard<std::mutex> task_lock(m_completedTasksMutex);
        return m_incomingTasks.empty() && m_nextTaskIndex == m_completedTasksIds.size();
        });
}

bool ThreadPool::Done(int64_t task_id)
{
    std::lock_guard<std::mutex> lock(m_completedTasksMutex);

    if (m_completedTasksIds.find(task_id) != m_completedTasksIds.end()) {
        return true;
    }

    return false;
}

ThreadPool::~ThreadPool()
{
    //WaitAll();

    m_quit = true;

    for (uint32_t i = 0; i < m_threads.size(); ++i)
    {
        newTaskAddedNotification.notify_all();
        m_threads[i].join();
    }
}

void ThreadPool::run()
{
    while (!m_quit)
    {
        std::unique_lock<std::mutex> lock(m_tasksMutex);

        newTaskAddedNotification.wait(lock, [this]()->bool { return !m_incomingTasks.empty() || m_quit; });

        if (!m_incomingTasks.empty()) 
        {
            auto elem = std::move(m_incomingTasks.front());
            m_incomingTasks.pop();
            lock.unlock();

            elem.first.get();

            std::lock_guard<std::mutex> lock(m_completedTasksMutex);

            m_completedTasksIds.insert(elem.second);

            m_taskCompletedNotification.notify_all();
        }
    }
}