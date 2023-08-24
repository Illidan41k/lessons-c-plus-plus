#include "Tower.h"
#include <iostream>
#include <thread>

Tower::Tower(
	const std::string& name, 
	int x, 
	int y, 
	int radius, 
	double atsSeconds, 
	std::shared_ptr<std::vector<Creep>> creepsStorage
) :
	m_x(x),
	m_y(y),
	m_radius(radius),
	m_name(name),
	m_atsSeconds(atsSeconds),
	m_creepsStorage(creepsStorage)
{
}


void Tower::operator()()
{
	while (true)
	{
		Spin();
	}
	
}

bool Tower::InRadius(const Creep& creep)
{
	int deltaX = creep.getX() - m_x;
	int deltaY = creep.getY() - m_y;

	int euclideanDistance = sqrt(deltaX * deltaX + deltaY * deltaY);
	return euclideanDistance < m_radius;
}

void Tower::Spin()
{
	std::cout << "========================================" << std::endl;
	std::cout << m_name << " tower is on duty!"<<std::endl;

	auto solidCopy = m_creepsStorage.lock(); 

	for (auto &creep : (*solidCopy))
	{
		if (InRadius(creep))
		{
			std::cout << m_name << " bom!" << std::endl;
			creep.Bom(20);
			creep.print();
		}
	}
	std::cout << "========================================" << std::endl << std::endl;

	long long delayMsec = 1000 * m_atsSeconds;
	std::this_thread::sleep_for(std::chrono::milliseconds(delayMsec));
}
