#include "Auto.h"
#include <iostream>

int globalVar = 129;

int getValue()
{
    return globalVar;
}

void test_auto()
{
    using std::endl;

    auto x = 42;
    auto y = 2.23;
    auto z = 2.23f;
    auto c = 'Q';
    auto ptr = &x;
    auto pptr = &ptr; 

    decltype(442) X = 442;

    int Z = getValue();
    Z += 2;
    //int& Y = getValue();

    //std::cout << "z:" << Z << "  Y" << Y << std::endl;


    std::cout << typeid(x).name() << endl
        << typeid(y).name() << endl
        << typeid(z).name() << endl
        << typeid(c).name() << endl
        << typeid(ptr).name() << endl
        << typeid(pptr).name() << endl
        << "=========================" << endl
        << typeid(X).name() << endl
       // << typeid(Y).name() << endl
        << typeid(Z).name() << endl
        ;
}
