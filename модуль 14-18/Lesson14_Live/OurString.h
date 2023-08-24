#pragma once
#include <iostream>

class OurString
{
public:
	OurString()
	{
		//std::cout << "created" << std::endl;
		m_string = new char[100000];
	}

	OurString(OurString&& other) noexcept
	{
		m_string = new char[100000];
		m_string = other.m_string;
		other.m_string = nullptr;
	}

	OurString(OurString& other) 
	{
		m_string = new char[100000];
		for (int i = 0; i < 100000; i++)
			m_string[i] = other.m_string[i];
	}

	~OurString()
	{
		//std::cout << "deleted" << std::endl;
		delete[] m_string;
	}


	OurString& operator=(const OurString& other)
	{
		//std::cout << "copy=" << std::endl;

		if (&other == this)
			return *this;

		delete[] m_string;
		m_string = new char[100000];

		for (int i = 0; i < 100000; i++)
			m_string[i] = other.m_string[i];

		return *this;
	}

	OurString& operator=(OurString&& arr) noexcept
	{
		//std::cout << "move=" << std::endl;
		if (&arr == this)
			return *this;
		m_string = arr.m_string;
		arr.m_string = nullptr;
		return *this;
	}

private:
	char* m_string;
};
