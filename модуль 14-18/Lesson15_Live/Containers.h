#pragma once

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>

#include <map>
#include <set>
#include <unordered_set>

class Containers
{
public:
	void WorkWithDeque();

	void WorkWithList();

	void WorkWithMap();

	void WorkWithSet();

	void WorkWithAdaptersStack();

	void WorkWithAdaptersQueue();

	void WorkWithAdaptersPriorityQueue();

};

enum class Types
{
	Zombie,
	Wolf,
	Wolf1,
	Wolf2,
	Snake
};

class Monster
{
public:
	Monster() {};
	Monster(const std::string& type) :
		m_type(type) {};

	std::string m_type;

	
};