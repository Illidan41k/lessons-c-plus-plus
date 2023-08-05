#pragma once
#include <iostream>

class Something
{
public:
	friend Something operator+(const Something& one, const Something& other)
	{
		Something newInstance{};
		newInstance.m_member = one.m_member + other.m_member;

		return newInstance;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Something& object)
	{
		stream << object.m_member;
		return stream;
	}

private:
	int m_member{ 33 };
};


int CalculateSum(int a, int b);
double CalculateSum(double a, double b);
Something CalculateSum(Something a, Something b);



template<typename T>
T CalculateSumSmart(T a, T b)
{
	auto sum = a + b;
	std::cout << typeid(a).name() <<": " << sum << std::endl;
	return sum;
}