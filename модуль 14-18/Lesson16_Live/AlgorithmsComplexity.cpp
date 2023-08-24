#include "AlgorithmsComplexity.h"

void Const()
{
	int n = 10;

	int tempResult = n + 5;

	int result = tempResult * 5;
}

void Linear()
{
	int n = 10;
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result += n;
	}
}

void Quadratic()
{
	int n = 10;
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result += n;
		}
	}
}

void Logarithmic()
{
	int n = 10;

	int a = 0, i = n;

	while (i >= 1) {
		a = a + 1;
		i /= 2;
	}
}

void Combined()
{
	int n = 10;
	int result = 0, result2= 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result+=j;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j+=2)
		{
			result += j;
			result += j+1;
		}
	}
}