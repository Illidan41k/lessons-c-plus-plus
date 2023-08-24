#pragma once
#include <iostream>
#include <mutex>
#include <vector>

class Creep
{
public:
	Creep(int hp, int x, int y);
	Creep(const Creep& other);

	int getX() const
	{
		return m_x;
	}

	int getY() const
	{
		return m_y;
	}

	void Bom(int damage);

	void Bom(std::vector<int> damageBunch);

	void print()
	{
		std::cout << m_hp << std::endl;
	}

	void operator++()
	{
		m_hp++;
	}

private:
	std::recursive_mutex m_hpProtectionMutex;
	int m_x;
	int m_y;
	
	int m_hp;
};

