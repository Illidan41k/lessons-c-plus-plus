#include <iostream>
#include <algorithm>
#include <iterator>
#include <time.h>
#include "TestVector.h"

using std::vector;
using std::cout;
using std::endl;

void PrintByTypeValue(vector<long> testVector)
{
	cout << endl << __FUNCTION__ << endl;

	for (long i : testVector)
	{
		cout << i << endl;
	}
}

void PrintByAutoValue(vector<long> testVector)
{
	cout << endl << __FUNCTION__ << endl;

	for (auto i : testVector)
	{
		cout << i << endl;
	}
}

void ChangeAndPrintByAutoValue(vector<long> testVector)
{
	cout << endl << __FUNCTION__ << endl;

	for (auto &i : testVector)
	{
		i += 1000;
		cout << i << endl;
	}

	for (auto i : testVector)
	{
		cout << i << endl;
	}
}

void PrintByIterator(vector<long> testVector)
{
	cout << endl << __FUNCTION__ << endl;

	for (std::vector<long>::const_iterator i = testVector.begin(); i != testVector.end(); ++i)
	{
		cout << *i << endl;
	}
		
}

void PrintByOstrem(vector<long> testVector)
{
	cout << endl << __FUNCTION__ << endl;

	std::ostream_iterator<long> coutIterator(std::cout, "__");
	
	std::copy(testVector.begin(), testVector.end(), coutIterator);
}

void PrintVectorData(const vector<long>& testVector)
{
	cout << "size is " << testVector.size() << "  ";
	cout << "capacity is " << testVector.capacity() << endl;
}

void TestCapacity()
{
	vector<long> testVector{};

	testVector.reserve(200);

	PrintVectorData(testVector);

	for (size_t i = 0; i < 30005; i++)
	{
		testVector.push_back(i);
	}

	testVector.shrink_to_fit();

	PrintVectorData(testVector);
}


void AtVSOperator()
{
	vector<int> testVector{2,5,6,9};

	try
	{
		cout << testVector.at(10) << endl;
	}
	catch (std::exception& e)
	{
		cout << e.what();
	}

}

void LoopThroughSize(std::vector<long> testVector)
{
	size_t lenght = testVector.size();

	for (size_t i = 0; i < lenght; i++)
	{
		cout << i<< " element is: " <<testVector[i] << endl;
	}
}

void VectorTests()
{
	
	vector<long> testVector{12, 25, 53};
	testVector.push_back(123);

	//PrintByTypeValue(testVector);
	//PrintByAutoValue(testVector);
	//ChangeAndPrintByAutoValue(testVector);
	//PrintByIterator(testVector);
	//PrintByOstrem(testVector);
	//LoopThroughSize(testVector);
	//TestCapacity();

	AtVSOperator();
}
