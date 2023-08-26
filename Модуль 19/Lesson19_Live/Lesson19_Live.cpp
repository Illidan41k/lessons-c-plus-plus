#include <vector>
#include <iostream>

#include "ThreadPool.h"
#include "RegularExpressions.h"

#include "FactoryProduction.h"
#include "Singleton.h"

#include "FuturePromiseUsage.h"

void sum(int& ans, std::vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		ans += arr[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		std::cout << std::this_thread::get_id() << ": " << ans << std::endl;
	}
}

int sum1( std::vector<int>& arr)
{
	int ans{0};

	for (int i = 0; i < arr.size(); ++i)
	{
		ans += arr[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		std::cout << std::this_thread::get_id() << ": " << ans << std::endl;
	}

	return ans;
}


int main()
{
	//RegularExpressions regEx;
	//regEx.DoIt();
	//regEx.Iterators();
	//regEx.Experiments();
	//regEx.Symbols();
	//regEx.AvailableValues();
	//regEx.PatternSearch();
	//regEx.MetaSymbols();
	//regEx.EmailValidation();
	//regEx.RandomFeatures();


	//Factory factory;
	//std::thread master(&Factory::Master, std::ref(factory));

	//std::thread adjuster(&Factory::Adjuster, std::ref(factory));

	//master.detach();
	//adjuster.detach();

	//system("pause");

	//for (;;)
	//{
	//	factory.AskNewOrder();
	//	system("pause");
	//}


	//std::vector<int> values{ 10,20,30,5,666 };
	//std::promise<int> result;
	//std::future<int> resultFuture = result.get_future();

	//std::thread calculationThread(CalculateSum, values, std::move(result));

	//std::cout << "finally!!  " << resultFuture.get() << std::endl;
	//calculationThread.join();


	//std::vector<int> list{ 13, 14, 15, 16, 188 };
	//auto futureVar = std::async(std::launch::async, [&]() { return sum1(list); } );
	////do a lot of useful work
	//std::cout << futureVar.get() << std::endl;

	//std::cout << std::thread::hardware_concurrency() << std::endl;
	//ThreadPool tasksManager(2);

	//std::vector<int> s1 = { 1, 2,4,8,9,10 };
	//std::vector<int> s2 = { 4, 5, 3, 6, 9, 11, 25 };
	//std::vector<int> s3 = { 8, 9, 10, 12,5,6,7 };

	//std::vector<int> answers{ 0,0,0 };
	//std::vector<int64_t> task_ids{};
	//std::vector<bool> answersReceived{ false, false, false };

	//task_ids.push_back(tasksManager.add_task(sum, std::ref(answers[0]), std::ref(s1)));
	//task_ids.push_back(tasksManager.add_task(sum, std::ref(answers[1]), std::ref(s2)));
	//task_ids.push_back(tasksManager.add_task(sum, std::ref(answers[2]), std::ref(s3)));

	//while (true)
	//{
	//	for (size_t i = 0; i < answers.size(); i++)
	//	{
	//		if (tasksManager.Done(task_ids[i]) && !answersReceived[i])
	//		{
	//			std::cout << std::endl << "======================" << std::endl;
	//			std::cout << i + 1 << " task done! [" << answers[i] << "]" << std::endl;
	//			std::cout << "======================" << std::endl << std::endl;
	//			answersReceived[i] = true;
	//		}
	//	}

	//}

	//std::thread t1(ThreadOne);
	//std::thread t2(ThreadTwo);
	//t1.join();
	//t2.join();

	//
}

