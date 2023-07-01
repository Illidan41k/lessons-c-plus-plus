#include "Arrays.h"
#include <iterator>
#include <iostream>
#include <array>

// *testArray
void PrintOneDimArrayWrong(char testArray []) // not working as you expect actually
{
    int size = sizeof(testArray) / sizeof(char);

    std::cout << sizeof(testArray) << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << testArray[i] << std::endl;
    }
}




void PrintOneDimArray(char (&testArray)[4]) 
{
    const int length{ (int)(std::size(testArray)) };

    for (int i = 0; i < length; i++)
    {
        std::cout << testArray[i] << std::endl;
    }

    std::cout << "=================" << std::endl;
}



void StringArray()
{
    char testString[]{ "qwe"};
    PrintOneDimArray(testString);
    const int length{ (int)(std::size(testString)) };

    std::cout << length << std::endl;
    
    std::cout << "Length of array = " << (sizeof(testString) / sizeof(char)) << std::endl;

}

void TwoDimsArray()
{
    int matrix[5][6]{};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cout << matrix[i][j] << "  ";
        }

        std::cout << std::endl;
    }

}

constexpr int StartSize(int n) 
{ 
    return 23 * n; 
}

void CorrectAndIncorrectInit()
{
    //correct cases
    const int N = 42;

    //size_t
    int correctArray1[15];
    int correctArray2[N];
    int correctArray3['Q'];
    int correctArray4[StartSize(2)];

    //incorrect cases

    //int n;

    //int incorrectArray1[0];
    //int incorrectArray2[n];   
    //int incorrectArray3["Q"];
    //auto incorrectArray4[2] = { 1, 2 };
}

void UsingArray()
{
    int M1[5][6], M2[5][6];
    //equals to
    using Matrix = int[5][6];

    Matrix L1{}, L2, L3, L4;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cout << L2[i][j] << "  ";
        }

        std::cout << std::endl;
    }
}

void SimpleArrayExample()
{
    int mass[5];

    for (int i = 0; i < 5; ++i)
    {
        mass[i] = i;
    }

    for (int i = 0; i < 5; ++i)
    {
        std::cout << mass[i] << "  ";
    }
}

void CStyleArrays()
{
    //SimpleArrayExample();
    //CorrectAndIncorrectInit();
    //StringArray();
    //TwoDimsArray();
    //UsingArray();
}

//////////////////////////////////////////////////

void PrintArray(const std::array<int, 5> &arr)
{
    for (auto element : arr)
    {
        std::cout << element++ << std::endl;
    }
}

void Initialization()
{
    std::array<int, 9> testArray;

    std::array<int, 5> testArray2 = { 7, 4, 2, 1, 9 };

    std::array<int, 23> testArray3{ 7, 4, 2, 1, 9 };

    std::array<int, 5> testArray4;

    testArray4 = { 3, 1, 1 ,1, 2};
    PrintArray(testArray4);
}

void STDArrays()
{
    Initialization();
}
