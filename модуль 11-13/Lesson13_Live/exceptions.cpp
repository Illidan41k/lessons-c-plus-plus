#include "exceptions.h"

//float Divide(float divisible, float divider)
//{
//	if (divider == 0.f)
//	{
//		throw "division by zero";
//	}
//
//	return divisible / divider;
//}


int BestFunction()
{
	try
	{
		throw "qwerety";
	}
	catch (...)
	{
		throw "qwerety";
	}
	return 0;
}


//float Divide(float divisible, float divider)
//{
//	if (divider == 0.f)
//	{
//		throw FloatDivizionException("divizion by zero!");
//	}
//
//	if (divisible > 45.f)
//	{
//		throw FloatDivizionException("that too large. i can't. sorry. use calculator instead");
//	}
//
//	return divisible / divider;
//}

float Divide(float divisible, float divider)
{
	if (divider == 0.f)
	{
		//throw BestDivizionException("divizion by zero!");
	}

	if (divisible > 45.f)
	{
		//throw BestDivizionException("that too large. i can't. sorry. use calculator instead");
	}

	return divisible / divider;
}