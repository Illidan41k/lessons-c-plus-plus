#pragma once

class AutoAttack
{
public:
	virtual void Apply(float &targetHp)
	{
		float damage = m_damage;
		//increase damage with crit rate
		damage += 2;
		targetHp -= m_damage;
	}

protected:
	float m_damage{3};
	float m_critRate{ 0.5 };
};

class AcheAutoAttack : public AutoAttack
{
public:
	void Apply(float &targetHp) override
	{
		float damage = m_damage;
		//apply slow with crit rate
		targetHp -= m_damage;
	}

private:

};
