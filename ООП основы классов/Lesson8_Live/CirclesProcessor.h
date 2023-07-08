#pragma once
#include <vector>
#include <array>

class CirclesProcessor
{
private:
	enum class Figures
	{
		Circle,
		Rectangle,
		Rhomb
	};

	constexpr static double m_pi = 3.14;

	static const int m_somethingInteger = 35;
	static const char m_somethingChar = 'q';
	static const bool m_someFlag = false;

	static const Figures figureType = Figures::Rectangle;

	//static constexpr std::vector<float> m_coefficients = { 0.24f, 0.35f };
	static constexpr std::array<float, 2> m_coefficients = { 0.24f, 0.35f };

public:
	static double m_accuratePi;


};

