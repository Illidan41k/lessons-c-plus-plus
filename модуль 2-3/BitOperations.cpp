#include <time.h>
#include "BitOperations.h"
#include <iostream>
#include <bitset>


void TestSwap()
{
    char a = 23;
    PrintBinary(a);
    a = ChangeBitPositions(a, 4, 7);
    PrintBinary(a);
}


void FlagsCombination()
{
    char verbose = 1 << 6;
    char fullScreen = 1 << 5;
    char allowBuferization = 1 << 4;

    char flags = 0;

    PrintBinary(verbose);
    PrintBinary(fullScreen);
    PrintBinary(allowBuferization);

    flags = verbose | fullScreen | allowBuferization;
    PrintBinary(flags);

    PrintFlags(flags);
    std::cout << "=============" << std::endl;
    flags = SwithcFlagOff(flags, fullScreen);
    PrintBinary(flags);
    PrintFlags(flags);
}

void PrintFlags(char flags)
{
    for (int i = 0; i < CHAR_BIT; i++)
    {
        checkBit(flags, i);
    }
}

void PrintBinary(char var)
{
    std::bitset<8> bitData(var);

    std::cout << "bit representation is " << bitData << std::endl;
}

void checkBit(char var, int location)
{
    bool bitValue = var & 1 << location;
    std::cout << location << " bit is " << bitValue << std::endl;
}

char SwithcFlagOff(char flags, char flag)
{
    PrintBinary(flags);
    PrintBinary(flag);
    char result = flag ^ flags;
    return result;
}

char ChangeBitPositions(char var, int firstPosition, int secondPosition)
{

    var ^= (1 << firstPosition);
    var ^= (1 << secondPosition);

    return var;

}