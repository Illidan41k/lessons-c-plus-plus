#include "Caching.h"

void Caching::AddNewElement(const HugeMathValue& element)
{
	m_values.push_back(element);
	m_lastSum = nullptr;
}

HugeMathValue Caching::GetSum()
{
	if (m_lastSum)
	{
		std::cout << "optimized way" << std::endl;
		return *m_lastSum;
	}

	std::cout << "recalculation" << std::endl;

	auto result = std::accumulate(m_values.begin(),
		m_values.end(),
		decltype(m_values)::value_type(),
		[](HugeMathValue& currentSum, const auto& nextObject)
		{
			return currentSum += nextObject;
		});

	m_lastSum = std::make_unique<HugeMathValue>(result);

	return result;
}
