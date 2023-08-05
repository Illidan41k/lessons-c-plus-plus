#include "lambdaHandlers.h"
#include <iostream>

void RepeatSomething(const std::function<int(int)>& function, int howManyTimes)
{
	for (int i = 0; i < howManyTimes; i++)
	{
		std::cout << function(i) << std::endl;
	}
}

void RepeatSomething1(int(*function)(int), int howManyTimes)
{
	for (int i = 0; i < howManyTimes; i++)
	{
		std::cout << function(i) << std::endl;
	}
}
