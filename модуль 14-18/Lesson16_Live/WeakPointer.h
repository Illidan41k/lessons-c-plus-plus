#pragma once
#include <memory>
#include <string>
#include <iostream>

using namespace std;


class Character
{
public:
	Character(const string &name):
		m_name(name)
	{
		cout << m_name << " created!" << endl;
	}

	~Character()
	{
		cout << m_name << " deleted!" << endl;
	}

	friend bool StartFight(std::shared_ptr<class Character>& first, std::shared_ptr<class Character>& second);

	void PrintInfo();


private:
	string m_name{};
	weak_ptr<Character> m_opponent;
};

