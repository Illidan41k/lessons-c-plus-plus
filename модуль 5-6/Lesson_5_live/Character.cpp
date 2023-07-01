#include "Character.h"
#include <iostream>

bool DealDamage(int damage)
{
    static int hp = 235;
    hp -= damage;
    std::cout << "==============" << std::endl;
    std::cout << "received damage: " << damage << std::endl;
    std::cout << "current hp is: " << hp << std::endl;

    return hp > 0;
}

long GetRandomDamage(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX));
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
 