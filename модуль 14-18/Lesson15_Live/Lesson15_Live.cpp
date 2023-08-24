#include <iostream>

#include "Containers.h"
#include "IteratorMechanic.h"

#include "Allocator.h"

int main()
{
    Containers example{};

    //example.WorkWithDeque();
    //example.WorkWithList();
    //example.WorkWithMap();
    //example.WorkWithSet();

    //example.WorkWithAdaptersStack();
    //example.WorkWithAdaptersQueue();
    //example.WorkWithAdaptersPriorityQueue();

    BestContainer container{ 12,24,67,777,23,666 };

    for (const auto& element : container)
    {
        std::cout << element << std::endl;
    }

    typedef std::vector<std::map<std::string, std::vector<int>>> PASSWORDMANADGER;

    PASSWORDMANADGER a;

}

