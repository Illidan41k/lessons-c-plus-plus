#include "Order.h"
#include <iostream>


void CheckOperationsOrder()
{

	int b = 25;
	int c = 20;
	b += c += b; // 1) c = c + b 2) b = b + c 
	
	std::cout << b << "   " << c << std::endl;

	int a = 10;
	PrintIncremented(a++); //

	a = 10;
	PrintIncremented(++a);

	bool areSignsSimilar = 3 < 2 == 5 > 3;
	std::cout << areSignsSimilar << std::endl << std::endl;
}

void PrintIncremented(int value)
{
	std::cout << "value now is " << value << std::endl << std::endl;
}
