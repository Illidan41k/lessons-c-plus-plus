#pragma once
#include <string>

float Divide(float divisible, float divider, bool &success);


int BestFunction() throw(char*);




class DivizionException
{
public:
	DivizionException(const std::string& error)
		: m_error(error)
	{
	}


	const std::string getError()
	{
		return m_error;
	}

private:
	std::string m_error;
};


class FloatDivizionException: public DivizionException
{
public:
	FloatDivizionException(const std::string& error)
		: DivizionException("FLOAT "  + error)
	{
	}

private:

};


class BestDivizionException :public std::exception
{
public:
	BestDivizionException(const std::string &message):
		std::exception(message.c_str()) {}
};