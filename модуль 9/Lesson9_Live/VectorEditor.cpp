#include "VectorEditor.h"
#include <iostream>

int MultishotDefenceTower::operator()(int hp)
{
	std::cout << "tower deals " << m_splashDamage << " damage." << std::endl;
	std::cout << hp << " -> ";
	hp -= m_splashDamage;
	std::cout << hp << std::endl << std::endl;
	return hp;

}
