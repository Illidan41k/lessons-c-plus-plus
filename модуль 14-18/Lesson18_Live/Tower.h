#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Creep.h"


class Tower
{
public:
	Tower(const std::string &name, int x, int y, int radius, double atsSeconds, std::shared_ptr<std::vector<Creep>> creepsStorage);

	Tower(const std::string& name, int x, int y, int radius, double atsSeconds, Creep* creep);

	void operator()();

private:
	bool InRadius(const Creep& creep);
	void Spin();

	int m_x;
	int m_y;
	int m_radius;
	std::string m_name;
	double m_atsSeconds;

	std::weak_ptr<std::vector<Creep>> m_creepsStorage;
};

