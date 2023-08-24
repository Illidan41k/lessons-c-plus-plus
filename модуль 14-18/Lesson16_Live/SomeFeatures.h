#pragma once
#include <numeric>

#pragma pack(push, 1)

class Class1
{
    long long a;
    char b;
    long long c;
    char d;
};

class Class2
{
    long long a;
    long long c;

    char b;
    char d;
};

#pragma pack(pop)

void ThernaryEqualization();

void Iota();