#include "AdvancedEnemiesFactory.h"
#include <iostream>

int AdvancedEnemiesFactory::EnemyEntity::s_globalId{ 1 };
std::vector<int> AdvancedEnemiesFactory::s_enemyIds{};

AdvancedEnemiesFactory::EnemyEntity::EnemyEntity() :
	m_id(s_globalId++)
{
	std::cout << "enemy " << m_id << " initialized" << std::endl;
	s_enemyIds.push_back(m_id);
}

AdvancedEnemiesFactory::EnemyEntity::~EnemyEntity()
{
	std::cout << "enemy " << m_id << " died. R.I.P." << std::endl;
	s_enemyIds.erase(std::remove(s_enemyIds.begin(), s_enemyIds.end(), m_id), s_enemyIds.end());
}

void AdvancedEnemiesFactory::ShowEnemies()
{
	for (const auto& enemy : s_enemyIds)
	{
		std::cout << enemy << ", ";
	}

	std::cout << std::endl;
}
