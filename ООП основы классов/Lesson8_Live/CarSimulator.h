#pragma once
#include <string>
#include <iostream>


struct EngineParameters
{
	int moment;
	int volume;
	int cylinders;

	void RecalculateMoment()
	{

	}
};

class CarSimulator
{

private:
	int m_maxSpeed = 666;
	std::string m_name{ "carl" };
	EngineParameters m_engine{ 23, 6, 4 };

public:
	int GetDistance(int time);
	int GetMaxSpeed();
	void PrintEngineParameters();

//protected:
	
};

