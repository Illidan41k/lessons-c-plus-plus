#pragma once
#include <memory>

class Value
{
public:
	Value(const int integer);
	Value(const float fractional);

	//payload

private:
	std::shared_ptr<int> m_integer{ nullptr };
	std::shared_ptr<float> m_fractional{ nullptr };

	friend bool AreEqual(const Value&, const Value&);
};
