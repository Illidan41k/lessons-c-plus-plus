#include "Casts.h"
#include <iostream>




void TestCasts()
{
	/*bool a = true;
	char c = 13;
	int d = 22;

	std::cout << a + d + c << std::endl;

	*/

	int a = 3;

	auto b = a + static_cast<int>(4.25);

	std::cout << typeid(b).name() << std::endl;
}
