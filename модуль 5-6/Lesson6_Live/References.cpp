#include "References.h"
#include <iostream>

using std::cout;
using std::endl;

void SimpleRefExample()
{
	int value = 23;
	int& reference = value;

	cout << value << "reference: " << reference << endl;

	value = 25; 
	cout << value << "reference: " << reference << endl;

	reference = 28;
	cout << value << "reference: " << reference << endl;

	reference += 100;
	cout << value << "reference: " << reference << endl;


	cout << "=================" << endl;

	cout << &value << endl;
	cout << &reference << endl;
}

void ConstAndNotConst()
{
	int a = 30;
	int& ref1 = a; 

	const int b = 8;
	//int& ref2 = b; // error
	const int& ref2 = b; 

	cout << a << endl;
	cout << ref1 << endl;
	cout << b << endl;
	cout << ref2 << endl;

	//int& ref3 = 4; //error
}


void ChangeValue(const long& value)
{
	cout << value << endl;
	//value += 1000;
}

void TestParameters()
{
	long a = 25;
	long& ref = a;

	cout << a << endl;

	ChangeValue(a);
	cout << a << endl;

	ChangeValue(ref);
	cout << a << endl;
}


namespace NS1
{
	namespace NS2
	{
		int a = 22;
	}
	
}

void SimplifyAccess()
{
	//Finger& finger = _factory.production.worker.hand.finger;
	// finger.bend()
	//_factory.production.worker.hand.finger.bend()
	using NS1::NS2::a;
	a = 29;
	cout << NS1::NS2::a;
}

void TestRefs()
{
	//SimpleRefExample();
	//ConstAndNotConst();

	TestParameters();

	//SimplifyAccess();
}
