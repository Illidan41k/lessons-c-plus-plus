#include "PerfectMathUtilities.h"

Value::Value(const int integer)
{
	m_integer = std::make_shared<int>(integer);
}


Value::Value(const float fractional)
{
	m_fractional = std::make_shared<float>(fractional);
}


bool AreEqual(const Value& value1, const Value& value2)
{
	bool areBothFractional = value1.m_fractional && value2.m_fractional;
	bool areBothInteger = value1.m_integer && value2.m_integer;

	if (!(areBothFractional || areBothInteger))
		return false;

	if (areBothFractional)
	{
		return *(value1.m_fractional) == *(value2.m_fractional);
	}

	if (areBothInteger)
	{
		return *(value1.m_integer) == *(value2.m_integer);
	}
}
