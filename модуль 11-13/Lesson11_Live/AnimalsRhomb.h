#pragma once
#include <iostream>


class Animal
{
public:
	Animal()
	{
		std::cout << "Animal " << std::endl;
	}
};

class Waterfowl : virtual public Animal
{
public:
	Waterfowl()
	{
		std::cout << "Waterfowl " << std::endl;
	}
};

class Ground : virtual public Animal
{
public:
	Ground()
	{
		std::cout << "Ground " << std::endl;
	}
};

class Salamander : public Ground, public Waterfowl
{
public:
	Salamander()
	{
		std::cout << "Salamander" << std::endl;
	}
};