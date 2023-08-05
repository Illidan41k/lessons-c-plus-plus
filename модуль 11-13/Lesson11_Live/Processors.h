#pragma once
#include <iostream>

class ProcessorBase
{
public:
	void CommonFunction() 
	{
		std::cout << "just common function" << std::endl;
	};

	~ProcessorBase() {};
};

class Processor1 : public ProcessorBase
{
public:
	void Function1() {
		std::cout << "f1"  << m_1 << std::endl;
	};

private:
	int m_1{ 24 };
};

class Processor2 : public ProcessorBase
{
public:
	void Function2() {
		std::cout << "f2"  << m_2 << std::endl;
	};

private:
	bool m_111{ true };
	int m_2{ 25 };
};