#pragma once

enum class EnemyType
{
	Melee,
	Ranged,
	Turtle
};

class Enemy
{
public:
	Enemy();

	void Info();
	static int ReadLastId();
	~Enemy();

private:
	static int s_globalId;
	int m_id;
};

