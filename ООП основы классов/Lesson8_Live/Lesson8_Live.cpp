#include <iostream>
#include <vector>

#include "Character.h"
#include "ConstructorsMechanics.h"
#include "CirclesProcessor.h"
#include "EnemiesFactory.h"
#include "AdvancedEnemiesFactory.h"
#include "CarSimulator.h"


int main()
{   
    /*
    CarSimulator carSimulator;

    std::cout << carSimulator.GetDistance(5) << std::endl;
    carSimulator.PrintEngineParameters();
    */


    //why pointers
    //Character firstCharacter{250};

    //firstCharacter.PrintStats();
    //firstCharacter.PrintClassInfo();
    

    //constructors
    //ManipulatorPosition position1 = ManipulatorPosition();
    //ManipulatorPosition position2 = ManipulatorPosition(1,2,3,45,60,34);
    //ManipulatorPosition position3 = ManipulatorPosition(1, 2, 3, Quaternion{});

    //position1.ShowJointStates();
    //position2.ShowJointStates();
    //position3.ShowJointStates();

    //static members
    CirclesProcessor circlesProcessor;

    //double pi1 = CirclesProcessor::m_accuratePi;
    //double pi2 = circlesProcessor.m_accuratePi;

    //Enemy enemy1;
    //Enemy enemy2;
    //Enemy enemy3;

    //enemy1.Info();
    //enemy2.Info();
    //enemy3.Info();
    
    using EnemyEntity = AdvancedEnemiesFactory::EnemyEntity;

    std::vector<std::shared_ptr<EnemyEntity>> enemies{};

    for (int i = 0; i < 10; i++)
    {
        auto enemy = std::make_shared<EnemyEntity>();
        enemies.push_back(enemy);
    }

    AdvancedEnemiesFactory::ShowEnemies();

    std::vector<int> killedEnemies = { 8, 5, 2 };

    for (const auto& killedEnemyIndex : killedEnemies)
    {
        enemies.erase(enemies.begin() + killedEnemyIndex - 1);
    }

    AdvancedEnemiesFactory::ShowEnemies();
    
}

