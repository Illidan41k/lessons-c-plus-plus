#include <iostream>
#include <chrono>
#include <utility>

#include "TestUnsafeClass.h"
#include "OurString.h"
#include "RvaluesFunctions.h"



int main()
{
	//TestUnsafeClass instance{};

	//for (size_t i = 1; i < 10000000; i += 100000)
	//{
	//	try
	//	{
	//		instance.UnsafeMethod(true);
	//	}
	//	catch (const std::exception& ex)
	//	{
	//		std::cout << ex.what() << std::endl;
	//	}

	//	system("pause");
	//}

	//int a = 333;
	////int& lValueReference = 666; //error -_-
	//int& lValueReference = a; 

	//int&& rValueReference = 7;
	////int&& rValueReference = a;//error -_-
	
	//int a = 256;
	//RvaluesFunctions object{};
	//object.Call(a);
	//object.Call(665);

	
	
	//int average = 0;

	//for (size_t i = 0; i < 500; i++)
	//{

	//	OurString str1;
	//	OurString str2;

	//	auto start = std::chrono::steady_clock::now();
	//	str1 = OurString();
	//	auto end = std::chrono::steady_clock::now();
	//	auto diff = end - start;

	//	average += std::chrono::duration<double, std::micro>(diff).count();
	//	
	//}

	//std::cout << average/500 << " microsec" << std::endl;
	


	OurString str100;
	OurString str200;
	str200 = str100;
	
	str200 = std::move(str100);

	
	int sum = 0;
	std::string str1{"qwerttr"};
	std::string str2{"dsfsdfsdf"};

	for (size_t i = 0; i < 500; i++)
	{

		auto start = std::chrono::steady_clock::now();
		//Swap(str1, str2);
		//BadSwap(str1, str2);
		auto end = std::chrono::steady_clock::now();
		auto diff = end - start;

		sum += std::chrono::duration<double, std::micro>(diff).count();

	}

	std::cout << sum << " microsec" << std::endl;
	
}

