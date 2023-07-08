#pragma once
#include <vector>

struct Quaternion
{
	double x;
	double y;
	double z;
	double w;
};

class ManipulatorPosition
{
public:

	~ManipulatorPosition()
	{
		delete oldPointer;
	};

	ManipulatorPosition();

	/**
	 * @brief Builds manipulators position by Euclidean coordinates and Euler angles of its end-effector with reference to base link.
	 *
	 * @param x - x with reference to base link
	 * @param y - y with reference to base link
	 * @param z - z with reference to base link
	 * @param R - roll with reference to base link
	 * @param P - pitch with reference to base link
	 * @param Y - yaw with reference to base link
	*/
	ManipulatorPosition(const float &x, const float &y, const float &z, const float &R, const float &P, const float &Y);

	/**
	 * @brief Builds manipulators position by Euclidean coordinates and quaternion of its end-effector with reference to base link.
	 * @param x
	 * @param y
	 * @param z
	 * @param quaternion
	*/
	ManipulatorPosition(const float& x, const float& y, const float& z, Quaternion quaternion);
	
	void ShowJointStates();

private:
	std::vector<float> m_jointStates{ 0.1f, 0.2f, 0.3f, 0.657f};
	int m_a;
	//std::shared_ptr<int> m_pointerInt;
	int* oldPointer;
};