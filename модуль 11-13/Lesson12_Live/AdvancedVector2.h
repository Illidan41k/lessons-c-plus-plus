#pragma once
#pragma once
#include <vector>
#include <memory>
#include <numeric>
#include <string>
#include <iostream>

/*
template <class T> 
class AdvancedVector2
{
public:
	void Add(const T& element)
	{
		m_baseVector.push_back(element);
	}

	T Average()
	{
		return std::accumulate(this->m_baseVector.begin(), this->m_baseVector.end(), 0.0) / this->m_baseVector.size();
	}

private:
	std::vector<T> m_baseVector{};
};

template<>
class AdvancedVector2<std::string>
{
public:
	void Add(const std::string& element)
	{
		m_baseVector.push_back(element);
	}
	std::string Average()
	{
		std::cout << "how can I calculate average string lol??" << std::endl;
		return "";
	}

private:
	std::vector<std::string> m_baseVector{};
};

*/





template<class T>
class AdvancedVectorBase
{
public:
	void Add(const T& element)
	{
		m_baseVector.push_back(element);
	}

	virtual T Average() = 0;

protected:
	std::vector<T> m_baseVector{};
};

template <class T> // 
class AdvancedVector2 : public AdvancedVectorBase<T>
{
public:

	virtual T Average() override
	{
		return std::accumulate(this->m_baseVector.begin(), this->m_baseVector.end(), 0.0) / this->m_baseVector.size();
	}
};

template<>
class AdvancedVector2<std::string> :public AdvancedVectorBase<std::string>
{
public:
	AdvancedVector2() :
		AdvancedVectorBase<std::string>()
	{

	}
	virtual std::string Average() override
	{
		std::cout << "how can I calculate average string lol??" << std::endl;
		return "";
	}
};

