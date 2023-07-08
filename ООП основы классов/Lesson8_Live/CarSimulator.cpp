#include "CarSimulator.h"

int CarSimulator::GetDistance(int time)
{
	return m_maxSpeed * time;
}

int CarSimulator::GetMaxSpeed()
{
	return m_maxSpeed;
}

void CarSimulator::PrintEngineParameters()
{
	std::cout << m_engine.cylinders << "   ";
	std::cout << m_engine.volume << "   ";
	std::cout << m_engine.moment << "   ";
	std::cout << std::endl;
}