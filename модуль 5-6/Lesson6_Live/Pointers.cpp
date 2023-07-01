#include "Pointers.h"
#include <iostream>

using std::cout;
using std::endl;

#include <memory>

void SimpleExample()
{
    int* a = new int; 
    int* b = new int{6};

    *a = 10;
    *b = *a + *b;

    cout << "b is " << *b << endl;
    cout << "b pointer is " << b << endl;

    delete b;
    delete a;
}

void GetAdress()
{
    int a = 10;

    int* pointerA = &a;

    cout << "a is " << a << endl;
    cout << "pointerA is " << pointerA << endl;
    cout << "pointerA value is " << *pointerA << endl;
    cout << "pointerA adress is " << &pointerA << endl;
}

void ChangeValue(int* pointer, int value)
{
    *pointer += value;
}

void PointerOnSameMemory()
{
    int A = 39;

    int* pointer1 = &A;
    int* pointer2 = &A;

    cout << A << endl;

    ChangeValue(pointer1, -5);

    cout << A << endl;

    ChangeValue(pointer2, 23);

    cout << A << endl;

}

void ArrayExample()
{
    int a[3] = { 1, 2, 3 };

    int* pointer = a;

    for (int i = 0; i < 3; i++)
    {
        cout << *pointer << endl;
        cout << pointer << endl << endl;
        pointer++;
    }
}

void DynamicArray()
{
    int size;
    std::cin >> size;

    int* array = new int[size] {};

    for (int i = 0; i < size; ++i)
    {
        array[i] = i;
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << "  ";
    }

    delete[] array;
}

void OldPointers()
{
    //SimpleExample();
    //GetAdress();
    //PointerOnSameMemory();
    //ArrayExample();
    //DynamicArray();
}


void WrongSharedPointersCreation()
{
    int* a = new int(18);

    std::shared_ptr<int> pointer(a);

    {
        std::shared_ptr<int> pointer2(a);

        // pointer 2 would be killed there
        // delete a
    }

    //pointer 1 would be killed there

    //exception??? why??
    // delete a
}


void NiceSharedPointerCreation()
{
    std::shared_ptr<int> pointer = std::make_shared<int>(231);

    {
        std::shared_ptr<int> pointer2 = pointer;

        // pointer 2 would be killed there
    }

    //pointer 1 would be killed there

}

void UniquePointerCreation()
{
    std::unique_ptr<int> A = std::make_unique<int>(42);
    //auto A = std::make_unique<int>(42);
    //std::unique_ptr<int> A(new int(42)); 
    std::unique_ptr<int> B; 

    std::cout << "A is " << (static_cast<bool>(A) ? "not null" : "null" ) << endl;
    std::cout << "B is " << (static_cast<bool>(B) ? "not null" : "null") << endl;

    //B = A; // cause error
    B = std::move(A);

    std::cout << "swapped" << endl;

    std::cout << "A is " << (static_cast<bool>(A) ? "not null" : "null") << endl;
    std::cout << "B is " << (static_cast<bool>(B) ? "not null" : "null") << endl;

    if (A)
    {
        cout << "a value is" << *A << endl; // reference to resource
    }

    if (B)
    {
        cout << "b value is" << *B << endl; // reference to resource
    }
}

std::unique_ptr<long> createDigit()
{
    return std::make_unique<long>(1899862831);
}

std::unique_ptr<long> NowIControlPointer(std::unique_ptr<long> digit)
{
    cout << __FUNCTION__ << endl;

    if (digit)
    {
        std::cout << *digit << endl;
    }
    
    return digit;
}

void TestOwnership()
{
    cout << __FUNCTION__ << endl;
    auto pointerOnDigit = createDigit();
    cout << *pointerOnDigit << endl;

    pointerOnDigit = NowIControlPointer(std::move(pointerOnDigit));

    if (!pointerOnDigit)
    {
        cout << "i no longer own it" << endl;
    }
    else
    {
        cout << "i got it again! " << *pointerOnDigit << endl;
    }
}


void UseRawPointer(long *digit)
{
    if (digit)
    {
        cout << *digit << endl;
    }
}

void TestRawPointerExtracting()
{
    auto pointer = std::make_unique<long>(989);

    UseRawPointer(pointer.get());

}


int FunctionForInt()
{
    //

    //
    //

    return 11;
}

template <typename T>
void ImaginaryFunction(std::unique_ptr<T> somePointer, int someAdditionalData)
{
    // some code
}

void SmartPointers()
{
    //WrongSharedPointersCreation();
    //NiceSharedPointerCreation();
    //UniquePointerCreation();

    //TestOwnership();
    
    //TestRawPointerExtracting();

    ImaginaryFunction(std::unique_ptr<int>(new int{ 22 }), FunctionForInt());
    
}
