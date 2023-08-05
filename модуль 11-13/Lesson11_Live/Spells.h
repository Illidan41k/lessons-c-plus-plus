#pragma once
#include <iostream>

class SpellBase
{
public:
	virtual void Use() 
	{
		//............
		UseInternal();
		//............
	}

protected:
	virtual void UseInternal()=0;
};

class Fireball : public SpellBase
{
public:


protected:
	virtual void UseInternal()
	{
		std::cout << "FIREBALL DOES BOOM" << std::endl;
	}

};

class ManaBurn : public SpellBase
{
public:


private:

protected:
	virtual void UseInternal()
	{
		SpellBase::UseInternal();
	}
};
