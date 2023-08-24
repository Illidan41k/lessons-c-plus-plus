#pragma once
#include <iostream>
#include <utility>

class RvaluesFunctions
{
public:
	void Call(const int& lvalue) 
	{
		std::cout << "l-value handling" << std::endl;
	}

	void Call(int&& rvalue)
	{
		std::cout << "r-value handling" << std::endl;
	}
};


template<class T>
void Swap(T& x, T& y)
{
	T tmp{ std::move(x) }; 
	x = std::move(y); 
	y = std::move(tmp); 
}

template<class T>
void BadSwap(T& x, T& y)
{
	T tmp{ x }; 
	x = y; 
	y = tmp; 
}