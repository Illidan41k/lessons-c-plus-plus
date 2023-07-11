#include "CurrencyManager.h"
#include <iostream>

Cash::Cash()
{
	CreateEmptyCashStorage();
}

Cash::Cash(const CoinsType type, const int count)
{
	CreateEmptyCashStorage();
	auto initCoins = OneTypeStorage{ type, (size_t)count };
	AddCoins(initCoins);

}

void Cash::CreateEmptyCashStorage()
{
	m_summarizedCash.reserve(2);

	m_summarizedCash.push_back(OneTypeStorage{ CoinsType::Gold, 0 });
	m_summarizedCash.push_back(OneTypeStorage{ CoinsType::Silver, 0 });
}


void Cash::PrintAllCash()
{
	PrintVectorCash(m_summarizedCash, "summarized cash: ");
}

void Cash::AddCoins(const OneTypeStorage& coins)
{
	for (auto& myCash : m_summarizedCash)
	{
		if (myCash.type == coins.type)
		{
			myCash.count += coins.count;
		}
	}
}

void Cash::PrintVectorCash(const std::vector<OneTypeStorage> &data, const std::string& title)
{
	std::cout << title << std::endl;

	for (const auto &element : data)
	{
		std::cout << (element.type == CoinsType::Gold ? "Gold: " : "Silver: ");
		std::cout << element.count << std::endl;
	}

	std::cout << std::endl;
}

Cash Cash::operator+=(const Cash& other)
{
	for (const auto& otherCash : other.m_summarizedCash)
	{
		AddCoins(otherCash);
	}

	return *this;
}

Cash Cash::operator+(const Cash& other)
{
	return operator+=(other);
}
