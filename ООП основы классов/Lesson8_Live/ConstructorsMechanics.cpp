#include "ConstructorsMechanics.h"
#include <iostream>


ManipulatorPosition::ManipulatorPosition(const float& x, const float& y, const float& z, const float& R, const float& P, const float& Y)
{
	//calculates m_jointStates
	//
	//
	//
	//
	m_jointStates = std::vector<float> {0.3, 0.4, 0.32, -0.22};
}

ManipulatorPosition::ManipulatorPosition(const float& x, const float& y, const float& z, Quaternion quaternion)
{
	//calculates m_jointStates
	m_jointStates = std::vector<float> {-0.3, -0.4, -0.32, -0.22};
}


ManipulatorPosition::ManipulatorPosition()
{
	oldPointer = new int(25);
	m_jointStates = { 0.55f, 0.25f, 0.53f, 0.557f };
}

void ManipulatorPosition::ShowJointStates()
{
	for (const auto& joint : m_jointStates)
	{
		std::cout << joint << "  ";
	}

	std::cout << std::endl;
}
