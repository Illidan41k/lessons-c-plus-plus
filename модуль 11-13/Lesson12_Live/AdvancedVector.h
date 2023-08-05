#pragma once
#include <vector>
#include <memory>
#include <numeric>

template<class T>
class AdvancedVector
{
public:
	void Add(const T& element)
	{
		m_baseVector.push_back(element);
	}

	virtual T Average()
	{
		return std::accumulate(m_baseVector.begin(), m_baseVector.end(), 0.0) / m_baseVector.size();
	}
private:
	std::vector<T> m_baseVector{};
};
