#include "Creep.h"

Creep::Creep(int hp, int x, int y):
	m_x(x),
	m_y(y),
	m_hp(hp)
{
}

Creep::Creep(const Creep& other):
	m_x(other.m_x),
	m_y(other.m_y),
	m_hp(other.m_hp)
{
}

void Creep::Bom(int damage)
{
	std::lock_guard<std::recursive_mutex> locker(m_hpProtectionMutex);

	std::cout << std::this_thread::get_id() <<" thread damaged me ;(" << std::endl;

	m_hp -= damage;

}

void Creep::Bom(std::vector<int> damageBunch)
{
	std::lock_guard<std::recursive_mutex> locker(m_hpProtectionMutex);

	for (const auto damage : damageBunch)
	{
		Bom(damage);
	}
}


