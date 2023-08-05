#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>

class Target
{
public:
	void DoDamage(int damage) 
	{
		m_hp -= damage;
	};

	void SetDebuf(const std::string& debuff)
	{
		m_debuffs.push_back(debuff);
	};

	void Status()
	{
		std::cout << std::endl << "-----------------------------------" << std::endl;

		std::cout << "hp: " << m_hp << std::endl;
		std::cout << "debuffs: " << std::endl;

		for (const auto& defuf : m_debuffs)
		{
			std::cout << defuf  << std::endl;
		}

		std::cout << std::endl << "-----------------------------------" << std::endl;
	}

	void Clear()
	{
		m_debuffs = {};
	}
private:
	int m_hp{1000};
	std::vector<std::string> m_debuffs{};
};


class AutoAttack
{
public:
	void Attack(Target& target)
	{
		for (const auto& effect : m_effects)
		{
			effect(target);
		}
	}


	void AddEffect(const std::function<void(Target &)>& effect)
	{
		m_effects.push_back(effect);
	}

private:
	std::vector<std::function<void(Target &)>> m_effects{};
};


////////
using effectOnTarget = std::function<void(Target&)>;

class Support
{
public:
	effectOnTarget GetAmplification()
	{
		return m_debuff;
	}
private:
	effectOnTarget m_debuff = [](Target& target) { target.SetDebuf("Stunned!"); };
};