#pragma once
#include <functional>

void RepeatSomething(const std::function<int(int)>& function, int howManyTimes);


void RepeatSomething1(int (*function)(int), int howManyTimes);


class ReallyHugeClass
{

};