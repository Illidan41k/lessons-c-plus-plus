#include "SomeFeatures.h"
#include <iostream>
#include <vector>

void ThernaryEqualization()
{
	int a=1, b=15;

	(a == 0 ? a : b) = 666;

	std::cout << a << "   " << b << std::endl;
}

void Iota()
{
	std::vector<int> values{};
	values.resize(9);
	std::iota(values.begin(), values.end(), 7);

	for (const auto& it : values)
	{
		std::cout << it << "  ";
	}
	std::cout << std::endl;
}
