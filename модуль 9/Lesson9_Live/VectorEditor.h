#pragma once

class MultishotDefenceTower
{
public:
	MultishotDefenceTower(const int towerDamage) :
		m_splashDamage(towerDamage) {}

	int operator()(int);

private:
	int m_splashDamage{ 42 };
};

