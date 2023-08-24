#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <atomic>
#include <shared_mutex>
#include "Creep.h"
#include "Tower.h"
#include "SomeProblems.h"


void function1()
{
	while (1)
	{
		std::cout << "first thread" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(600));
	}

}

void function2()
{

	while (1)
	{
		std::cout << "second thread" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(600));

	}
}


std::atomic<int> g_atomicValue;


void f1()
{
	for (int i = 0; i < 1000; i++)
	{
		g_atomicValue++;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void helper()
{
	while (1)
	{
		system("pause");
		std::cout << "helper view: " << g_atomicValue << std::endl;
	}
}


int main()
{
	//for (int i = 0; i < 10; i++)
	//{
	//	std::thread newThread(f1);
	//	newThread.detach();
	//}

	//std::thread helpThread(helper);
	//helpThread.join();
	//system("pause");
	//std::cout << g_atomicValue << std::endl;
	//system("pause");


	//std::thread thread1(function1);
	//std::thread thread2(function2);

	//thread1.join();
	//thread2.detach();

	//std::shared_ptr<std::vector<Creep>> creeps = std::make_shared< std::vector<Creep>>();

	//std::thread thread1(Tower("minigun", 10, 15, 6, 0.5, creeps));
	//std::thread thread2(Tower("cannon", 5, 20, 8, 2.3, creeps));

	//thread1.detach();
	//thread2.detach();

	//system("pause");

	//creeps->push_back(Creep(1000, 11, 14));
	//creeps->emplace_back(Creep(1000, 8, 16));

	//system("pause");


	//std::mutex mutex;
	//bool success = mutex.try_lock();
	//std::unique_lock<std::mutex> lock(mutex);
	//lock.unlock();

	//std::shared_mutex mutex;
	//mutex.lock();
	//mutex.lock_shared();
	//bool success = mutex.try_lock_shared();

	//std::timed_mutex mutex;
	//bool success = mutex.try_lock_for(std::chrono::milliseconds(100));
	//success = mutex.try_lock_until(
	//	std::chrono::steady_clock::now() + std::chrono::seconds(10));

	//std::this_thread::yield();
	//std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::seconds(10));

	std::mutex m1, m2;
	std::lock(m1, m2); 

	{
		std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
		//do smth
	}
	{
		std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);

		//do smth else
	}

	//std::unique_lock<std::mutex> lock1(m1, std::defer_lock);
	//std::unique_lock<std::mutex> lock2(m2, std::defer_lock);

	//std::lock(m1, m2);

}

