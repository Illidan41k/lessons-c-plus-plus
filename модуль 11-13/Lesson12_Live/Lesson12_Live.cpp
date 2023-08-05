#include <iostream>
#include <fstream>
#include "BestLogger.h"
#include "SumFunctions.h"
#include "AdvancedVector.h"
#include "AdvancedVector2.h"
#include "AdvancedArray.h"
#include "GenericStorage.h"
#include "VariadicArray.h"

template<class BestVector, class Iterator = typename BestVector::Iterator>
class Something
{

};
int main()
{
    //CalculateSum(10, 13);
    //CalculateSum(10.5, 13.9);
    //CalculateSum(Something{}, Something{});

    //CalculateSumSmart(12, 20);
    //CalculateSumSmart(12.4, 20.5);
    //CalculateSumSmart(Something{}, Something{});
    //CalculateSumSmart(true, false);

    //AdvancedVector<int> list;
    //list.Add(24);
    //list.Add(10);
    //std::cout << list.Average() << std::endl;

    //AdvancedArray<float, 4> ourArray;
    //ourArray[0] = 4;
    //ourArray[1] = 5;
    //ourArray[2] = 10;
    //ourArray[3] = 10;
    //std::cout << ourArray.Average() << std::endl;

    //AdvancedVector2<int> ints;
    //ints.Add(25);
    //ints.Add(45);
    //std::cout << ints.Average() << std::endl;

    //AdvancedVector2<std::string> strings;
    //strings.Average();

    
    //int a = 10;
    //float b = 23.1f;
    //bool isTrue = false;
    //std::shared_ptr<std::string> ptrOnString = std::make_shared<std::string>("qwerty");

    //GenericStorage<int> genericInt(a);
    //GenericStorage<float> genericFloat(b);
    //GenericStorage<bool> genericBool(isTrue);
    //GenericStorage<std::shared_ptr<std::string>> genericPtrOnString(ptrOnString);

    //genericInt.print();
    //genericFloat.print();
    //genericBool.print();
    //genericPtrOnString.print();

    //Debug(std::cout, 23, 'a', "asd", 23, 13.78, true);

    //VariadicArray<int, 66, 99, 69, 96, 666, 6575, 32> convenientArray;

    //std::cout << convenientArray.nums_count << std::endl;

    //for (int n = 0; n < convenientArray.nums_count; ++n)
    //{
    //    std::cout << convenientArray.m_nums[n] << " ";
    //}

    //std::cout << std::endl;
}

