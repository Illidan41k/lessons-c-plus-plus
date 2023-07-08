#pragma once
#include <string>
#include <memory>


struct ALotOfStats
{
	std::string stat1;
	std::string stat2;
	std::string stat3;
	std::string stat4;
	std::string stat5;
	std::string stat6;
	std::string stat7;
	std::string stat8;
	std::string stat9;
	std::string stat10;
};


class Character
{
public:
	int m_hp;
	int m_damage;	
	int m_armour;
	std::shared_ptr<std::string> m_name{};
	std::shared_ptr<ALotOfStats> m_aLotOfStats;

	void PrintStats();

	void PrintClassInfo();
};

