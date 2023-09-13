#include <iostream>
#include "GameLoop.h"

#include <Windows.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    GameLoop mainLoop{};
    mainLoop.Loop();

    system("pause");
}

