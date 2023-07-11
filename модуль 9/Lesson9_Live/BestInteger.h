#pragma once
#include <ostream>

class BestInteger
{
public:
	BestInteger(const int initializer) :
		m_int(initializer) {};

	BestInteger(const BestInteger& other) = delete;
	
	friend std::ostream& operator<<(std::ostream& output, const BestInteger &object);
private:
	int m_int{ 0 };
};

