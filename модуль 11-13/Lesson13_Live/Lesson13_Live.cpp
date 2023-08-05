#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

#include "lambdaHandlers.h"
#include "Spells.h"
#include "exceptions.h"

template<typename T>
void Show(const std::vector<T> vector)
{
	for (const auto& element : vector)
	{
		std::cout << element << "  ";
	}

	std::cout << std::endl;
}

int Multiply(int digit)
{
	return digit * 2;
}


int main()
{
	//std::vector<int> list{ 23,22,10,13,44,51 };
	//std::vector<int> result;

	//result.resize(list.size());

	//auto ourLambda = [](int digit) {return digit * 2; };

	//std::transform(list.begin(), list.end(), result.begin(), ourLambda);

	//Show(list);
	//Show(result);


	//int (*lambda)(int) = [/*hahaha*/](int a) { return a + 101; };

	//auto someLambda = [](int a) { return a + 10; };

	//std::function<int(int)> sameLambda = [](int a) { return a + 3; };

	//RepeatSomething(someLambda, 5);


	//auto genericPrintlambda{
	//	[](auto value)
	//	{
	//	  static int myCalls = 0;
	//	  std::cout << typeid(value).name() << "-";
	//	  std::cout << myCalls++ << ": " << value << std::endl;
	//	}
	//};

	//genericPrintlambda(43);
	//genericPrintlambda(42);
	//genericPrintlambda(48);
	//genericPrintlambda(2.4);
	//genericPrintlambda("qwerty");
	//genericPrintlambda(2.4);
	//genericPrintlambda("qwerty");
	//genericPrintlambda(12);
	//genericPrintlambda(3.3);


	//std::vector<int> digits{ 10,12,25,31,40};


	//auto neighbours{ std::adjacent_find(digits.begin(), digits.end(),
	//                                    [](const auto& a, const auto& b)
	//                                    {
	//                                      return (a == b);
	//                                    }) };

	//if (neighbours != digits.end())
	//{
	//    std::cout << *neighbours << ", " << *std::next(neighbours) << std::endl;
	//}

	//auto divide = [](int x, int y, bool round) -> double{
	//	if (round)
	//		return x / y;
	//	else
	//		return double(x) / y;
	//};
	//std::cout << divide(48, 5, false) << std::endl;



	//std::vector<int> list{ 23,22,10,13,44,51 };
	//std::vector<int> result;
	//result.resize(list.size());
	//int coeff = 10;

	//std::transform(list.begin(), list.end(), result.begin(), 
	//	[&coeff](int argument) 
	//	{
	//		coeff--;
	//		return argument * coeff; 
	//	}
	//);
	//Show(list);
	//Show(result);
	//std::cout << coeff << std::endl;

	//int var1{ 91 };
	//int var2{ 21 };

	//ReallyHugeClass object{};

	//auto lambda = [var1, var2, &object]() {};

	//auto lambda1 = [=]() {};
	//auto lambda2 = [&]() {};

	//auto lambda3 = [=, &object]() {};
	//auto lambda4 = [&, var1]() {};
	//auto lambda5 = [=, &]() {};


	//AutoAttack autoAttack{};
	//Target target{};
	//target.Status();

	//autoAttack.AddEffect([](Target& target)
	//	{
	//		target.DoDamage(208);
	//	});

	//autoAttack.AddEffect([](Target& target)
	//	{
	//		target.SetDebuf("poison");
	//		target.SetDebuf("fire!");
	//	});

	//autoAttack.Attack(target);
	//target.Status();

	//target.Clear();

	//Support support{};
	//autoAttack.AddEffect(support.GetAmplification());

	//autoAttack.Attack(target);
	//target.Status();

	//////////////////////////////exceptions/////////////////////////////////////


	//try
	//{
	//	//some code
	//	if (false)
	//	{
	//		throw 32;
	//	}
	//	else
	//	{
	//		throw 32.8;
	//	}
	//	//some more code
	//}
	//catch (const int &ex)
	//{
	//	std::cerr << "I caught int " << ex << std::endl;
	//}
	//catch (const float& ex)
	//{
	//	std::cerr << "I caught double " << ex << std::endl;
	//}

	//std::cout << Divide(23.f, 2.f)<<std::endl;

	//try
	//{
	//	std::cout << Divide(23.f, 0.f);
	//}
	//catch (const char* ex)
	//{
	//	std::cerr << ex << std::endl;
	//}


	//
	//try
	//{
	//	std::cout << Divide(23.f, 0.f);
	//}
	//catch (const std::exception& ex)
	//{
	//	std::cerr << ex.what() << std::endl;
	//}
	//catch (...)
	//{
	//	std::cerr << "we catch SOMETHING!" << std::endl;
	//}

	//try
	//{
	//	BestFunction();
	//}
	//catch (...)
	//{
	//	std::cerr << "we catch IT!" << std::endl;
	//}

	//try
	//{
	//	Divide(10.f, 0.0f);
	//}
	//catch (DivizionException& ex)
	//{
	//	std::cerr << ex.getError();
	//}

	//try
	//{
	//	Divide(60.f, 0.1f);
	//	//code
	//	//code
	//}
	//catch (DivizionException& ex)
	//{
	//	std::cerr << ex.getError();
	//}
	//catch (FloatDivizionException& ex)
	//{
	//	std::cerr << "float:" << ex.getError();
	//}


	//try
	//{
	//	std::string str;
	//	str.resize(-1); 
	//}
	//catch (std::exception& ex)
	//{
	//	std::cerr << "Caught: " << ex.what() << std::endl;
	//}

	//try
	//{
	//	std::string str;
	//	str.resize(3648182794128361923);
	//	//str.resize(-1);
	//}
	//catch (std::bad_alloc& ex)
	//{
	//	std::cerr << "Caught: " << ex.what() << std::endl;
	//	std::cerr << "Try to make str shorter.... " << std::endl;
	//}
	//catch (std::exception& ex)
	//{
	//	std::cerr << "Caught: " << ex.what() << std::endl;
	//	std::cerr << "IDK what happening -_- " << std::endl;
	//}

	//try
	//{
	//	throw std::exception("some problems...");
	//}
	//catch (std::exception& ex)
	//{
	//	std::cerr << "Caught: " << ex.what() << std::endl;
	//}


	try
	{
		Divide(60.f, 0.1f);
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what();
	}

	try
	{
		//open file
		//work with loaded file   -> exception
		//close file
	}
	catch (const std::exception&)
	{
		std::cerr << "error" << std::endl;
		//close file
	}


}

//1) невозможно обработать на месте
//2) происходит редко
//3) нет адекватного способа сообщить об ошибке по-другому
//4) КРИТИКА

/*
[список захвата](параметры)
mutable
constexpr
-> тип возврата
{
	тело
}
*/


