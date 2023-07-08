#pragma once
#include <vector>
#include <memory>

class AdvancedEnemiesFactory
{
public:

	class EnemyEntity
	{
	public:
		EnemyEntity();
		~EnemyEntity();

	private:
		static int s_globalId;
		int m_id;
	};

	static void ShowEnemies();
	
private:
	
	static std::vector<int> s_enemyIds;
};

