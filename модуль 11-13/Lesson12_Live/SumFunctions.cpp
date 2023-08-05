#include "SumFunctions.h"

int CalculateSum(int a, int b)
{
	auto sum = a + b;
	std::cout << "int: " << sum << std::endl;
	return sum;
}

double CalculateSum(double a, double b)
{
	auto sum = a + b;
	std::cout << "double: " << sum << std::endl;
	return sum;
}

Something CalculateSum(Something a, Something b)
{
	auto sum = a + b;
	std::cout << "Something: " << sum << std::endl;
	return sum;
}
