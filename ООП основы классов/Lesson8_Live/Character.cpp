#include <iostream>
#include "Character.h"


void Character::PrintStats()
{
	//std::cout << "damage: " << m_damage << ", hp: " << m_hp << std::endl;
}

void Character::PrintClassInfo()
{
	std::cout << "class size is: " << sizeof(Character) << std::endl;
}
