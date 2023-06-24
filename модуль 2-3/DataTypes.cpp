#include "DataTypes.h"
#include <iostream>
#include <iomanip>

#define tab "  "
#define vertical  " |"

const std::string delimitter(150, '-'); // string contains 150 '-' characters

void DataTypesInfo()
{
    PrintDataType(int{});
    PrintDataType(unsigned int{});
    PrintDataType(long long{});
    PrintDataType(char{});
    PrintDataType(short{});
    PrintDataType(long{});
    PrintDataType(int64_t{});
    PrintDataType(bool{});
}

template<typename T>
inline void PrintDataType(const T variable)
{
    std::cout << "name: |" << std::setw(15) << typeid(variable).name() << vertical << tab;
    std::cout << "size: |" << std::setw(5) << sizeof(variable) << std::setw(30) << vertical << tab;
    std::cout << "min: |" << std::setw(25) << std::numeric_limits<decltype(variable)>::min() << vertical << tab;
    std::cout << "max: |" << std::setw(15) << std::numeric_limits<decltype(variable)>::max() << std::setw(30) << tab;

    std::cout << std::endl;
    std::cout << delimitter;
    std::cout << std::endl;
}