#pragma once
#include <vector>
#include <numeric>
#include <iostream>
#include <memory>

class HugeMathValue
{
public:
	explicit HugeMathValue(const int init) :
		m_value(init) {};

	HugeMathValue() {};

	HugeMathValue& operator+=(const HugeMathValue &other)
	{
		m_value += other.m_value;
		return *this;
	}

	void Print()
	{
		std::cout << m_value << std::endl;
	}

private:
	int m_value{0};
};

///////////////////

class Caching
{
public:

	void AddNewElement(const HugeMathValue& element);

	HugeMathValue GetSum();

private:
	std::vector<HugeMathValue> m_values{5, HugeMathValue(13)};
	std::vector<int> m_integers{ 3,4,5,6,7,8,9 };
	std::unique_ptr<HugeMathValue> m_lastSum = nullptr;
};

