#include <iostream>
#include <stack>
#include <queue>

#include "Containers.h"
using namespace std;

void Containers::WorkWithDeque()
{
    std::deque<int> simpleDeque;

    for (int count = 0; count < 9; count++)
    {
        simpleDeque.push_back(count);
        simpleDeque.push_front(count);
    }

    for (const auto& iterator : simpleDeque)
    {
        std::cout << iterator << ' ';
    }

    std::cout << std::endl;

}

void Containers::WorkWithList()
{
    std::list<int> numbers{ 10, 20, 30, 40, 666 };

    int first{ numbers.front() };  
    int last{ numbers.back() }; 

    std::cout << "First: " << first << std::endl;
    std::cout << "Last: " << last << std::endl;


    for (const auto& element : numbers)
    {
        std::cout << element << std::endl;
    }
       
    std::cout << std::endl;

    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;
}

void Containers::WorkWithMap()
{
    std::map<Types, Monster> monstersTemplates{};

    monstersTemplates[Types::Snake] = Monster("Snake");
    monstersTemplates[Types::Wolf] = Monster("Wolf");
    monstersTemplates[Types::Zombie] = Monster("Zombie");

    std::cout << monstersTemplates[Types::Snake].m_type << std::endl;
    std::cout << monstersTemplates[Types::Wolf].m_type << std::endl;


    cout << endl;
    //-----------------------------------------------------------------

    /*
    monstersTemplates = {
        std::pair<Types, Monster>{Types::Snake, "ANACONDA"},
        std::pair<Types, Monster>{Types::Wolf, "GERALT WOOF WOOF"}
    };

    for (const auto monster : monstersTemplates)
    {
        std::cout << monster.second.m_type << std::endl;
    }

    cout << endl;
    */
    
    //-----------------------------------------------------------------

    monstersTemplates = {
        {Types::Zombie, "CRANBERIES"},
        {Types::Wolf, "ZAYAC-WOLK"},
        {Types::Wolf1, "AKELA"},
        {Types::Wolf1, "QWEWOLK"},
        {Types::Wolf2, "LYCAN"}
    };

    monstersTemplates[Types::Wolf1] = Monster("WOLFAUF");

    for (const auto monster : monstersTemplates)
    {
        std::cout << monster.second.m_type << std::endl;
    }

    cout << endl;
    monstersTemplates.erase(Types::Wolf1);

    for (const auto monster : monstersTemplates)
    {
        std::cout << monster.second.m_type << std::endl;
    }
    

}

void Containers::WorkWithSet()
{
    std::multiset<int> numbers{ 1, 2, 3333, 5345345, 43434 };

    numbers.insert(666);
    numbers.insert(666);
    numbers.insert(666);

    for (const auto number : numbers)
    {
        std::cout << number << std::endl;
    }
}

void Containers::WorkWithAdaptersStack()
{
    //std::stack<int> s; //use std::deque
    std::stack<int, std::list<int>> s;

    //push, pop, empty, top

    s.push(1);
    s.push(666);
    s.push(13);
    
    s.pop();  

    std::cout << s.top() << std::endl; 
    s.pop();
    std::cout << s.top() << std::endl;

    if (s.empty()) {  
        std::cout << "Stack is empty" <<std::endl;
    }


}

void Containers::WorkWithAdaptersQueue()
{
    std::queue<int> s;
    s.push(1);
    s.push(666);
    s.push(25);
    s.push(2525);

    std::cout << s.front() << std::endl;  
    std::cout << s.back() << std::endl; 

    s.pop();  
    std::cout << std::endl;
    std::cout << s.front() << std::endl;
    std::cout << s.back() << std::endl;

    if (s.empty()) {
        std::cout << "Queue is empty" << std::endl;
    }
}

void Containers::WorkWithAdaptersPriorityQueue()
{
    //std::priority_queue<int> priority_queue;

    std::priority_queue<int, std::vector<int>, std::greater<int>> priority_queue;

    for (int x : {3, 14, 15, 92, 6, 0, 1, 10}) {
        priority_queue.push(x);
    }

    while (!priority_queue.empty()) {
        std::cout << priority_queue.top() << " ";
        priority_queue.pop();
    }

    cout << endl;
}
