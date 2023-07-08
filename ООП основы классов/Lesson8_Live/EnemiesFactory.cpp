#include "EnemiesFactory.h"
#include <iostream>
#include <fstream>


//int Enemy::s_globalId = 1;
int Enemy::s_globalId = Enemy::ReadLastId();

Enemy::Enemy()
{
	m_id = s_globalId++;
}

void Enemy::Info()
{
	std::cout << "my id is " << m_id << std::endl;
}

//---------------------------------------//

 int Enemy::ReadLastId()
{
	int id=0;

	try 
	{
		std::ifstream source("dump.txt");

		source >> id;
	}
	catch (std::exception& exc)
	{
		std::cout << exc.what();
	}

	return id;
}

Enemy::~Enemy()
{
	std::ofstream save("dump.txt", std::ios::trunc);

	save << Enemy::s_globalId;
}
