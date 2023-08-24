#include "TestUnsafeClass.h"
#include <exception>
#include <iostream>
#include "OurSmartPointer.h"


//void TestUnsafeClass::UnsafeMethod(bool isThereSmthBad)
//{
//	Big* a = new Big{};
//
//	std::cout << sizeof(*a) << std::endl;
//
//	if (isThereSmthBad)
//	{
//		throw std::bad_exception();
//	}
//
//	delete a;
//}

void TestUnsafeClass::UnsafeMethod(bool isThereSmthBad)
{

	OurSmartPointer<Big> a(new Big{});

	OurSmartPointer<Big> b = a;

	std::cout << sizeof(*a) << std::endl;

	if (isThereSmthBad)
	{
		throw std::bad_exception();
	}
}


Big::Big()
{
	std::cout << "allocated" << std::endl;
}

Big::~Big()
{
	std::cout << "deleted" << std::endl;
}

//Big::Big(const Big& other)
//{
//	std::cout << "allocated" << std::endl;
//}