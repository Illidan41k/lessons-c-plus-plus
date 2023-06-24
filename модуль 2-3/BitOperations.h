#pragma once

void FlagsCombination();

void PrintFlags(char flags);
void PrintBinary(char var);
void checkBit(char var, int location);

char SwithcFlagOff(char flags, char flag);
char ChangeBitPositions(char var, int firstPosition, int secondPosition);

void TestSwap();