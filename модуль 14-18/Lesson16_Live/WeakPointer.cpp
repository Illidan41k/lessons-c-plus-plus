#include "WeakPointer.h"

bool StartFight(std::shared_ptr<class Character>& first, std::shared_ptr<class Character>& second)
{
	if (!first || !second)
		return false;

	first->m_opponent = second;
	second->m_opponent = first;

	std::cout << first->m_name << " is fighting with " << second->m_name << endl;

	return true;
}

void Character::PrintInfo()
{
	cout << "Character: " << m_name << endl;

	if (m_opponent.expired())
	{
		cout << "Opponent: " << m_opponent.lock()->m_name << endl;
	}
}
