#include "CoinsMixture.h"
#include <iostream>

Gold& Gold::operator+(Silver& silver)
{
    int appendedGold = silver.m_count/10;
    m_count += appendedGold;

    silver.m_count -= appendedGold * 10;
    return *this;
}

Gold& Gold::operator+(int count)
{
    m_count += count;
    return *this;
}


void PrintCoins(const Gold& coins)
{
    std::cout << coins.m_count << std::endl << std::endl;
}

void PrintCoins(const Silver& coins)
{
    std::cout << coins.m_count << std::endl << std::endl;
}