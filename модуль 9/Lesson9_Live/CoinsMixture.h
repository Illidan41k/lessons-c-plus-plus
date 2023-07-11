#pragma once

class Silver;

class Gold
{
public:
	Gold(const int count) :
		m_count(count) {}

	Gold& operator+(Silver&);
	Gold& operator+(int);

	friend void PrintCoins(const Gold&);

private:
	int m_count{ 0 };
};


class Silver
{
public:
	Silver(const int count) :
		m_count(count) {}

	friend Gold& Gold::operator+(Silver&);

	friend void PrintCoins(const Silver&);
private:
	int m_count{ 0 };
};


