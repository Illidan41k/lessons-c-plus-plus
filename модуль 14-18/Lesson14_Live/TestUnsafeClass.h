#pragma once
#include <string>

class TestUnsafeClass
{
public:
	void UnsafeMethod(bool isThereSmthBad = false);
};

class Big
{
public:
	Big();
	//Big(const Big& other);
	~Big();

private:
	std::string m_str[100000];
};

