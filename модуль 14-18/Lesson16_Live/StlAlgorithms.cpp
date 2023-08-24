#include "StlAlgorithms.h"

void all_of()
{
    list<int> numbers{ 51, 41, 11, 21, 21 };
    list<int>::iterator iter;

    cout << "list = ( ";

    for (iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        cout << *iter << " ";
    }
        
    cout << ")" << endl;

    auto is_even = [](int elem) { return !(elem % 2); };

    if (all_of(numbers.begin(), numbers.end(), is_even))
    {
        cout << "All the elements are even numbers." << endl;
    }
    else
    {
        cout << "Not all the elements are even numbers." << endl;

    }
     

    if (any_of(numbers.begin(), numbers.end(), is_even))
    {
        cout << "There is at least one element which is even." << endl;
    }
    else
    {
        cout << "No the elements are even numbers." << endl;
    }

    
}

void copy()
{
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2;

    int i;
    for (i = 0; i <= 5; i++)
        v1.push_back(10 * i);

    int ii;
    for (ii = 0; ii <= 10; ii++)
        v2.push_back(3 * ii);

    cout << "v1 = ( ";
    for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
        cout << *Iter1 << " ";
    cout << ")" << endl;

    cout << "v2 = ( ";
    for (Iter2 = v2.begin(); Iter2 != v2.end(); Iter2++)
        cout << *Iter2 << " ";
    cout << ")" << endl;

    copy(v1.begin(), v1.begin() + 3, v2.begin() + 4);

    cout << "v2 with v1 insert = ( ";
    for (Iter2 = v2.begin(); Iter2 != v2.end(); Iter2++)
        cout << *Iter2 << " ";
    cout << ")" << endl;


    copy(v2.begin() + 4, v2.begin() + 7, v2.begin() + 2);

    cout << "v2 with shifted insert = ( ";
    for (Iter2 = v2.begin(); Iter2 != v2.end(); Iter2++)
        cout << *Iter2 << " ";
    cout << ")" << endl;
}

void equality()
{
    vector<int> v1{ 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
    vector<int> v2{ 0, 5, 10, 15, 20, 25};

    bool areEqual = equal(v1.begin(), v1.end(), v2.begin(), v2.end());
    cout << "equality:" << areEqual << endl;

    cout << "==================================" << endl << endl;
    auto result = equal_range(v1.begin(), v1.end(), 15);


    cout << "[" << *(result.first) << ", " << *(result.second) << "]" << endl;
}

void filling()
{
    std::vector<int> values{};
    values.reserve(16);
    values.resize(16);

    fill(values.begin() , values.end(), 666);

    for (auto element = values.begin(); element != values.end(); element++)
    {
        cout << *element << " ";
    }
    
    cout << endl;

    fill_n(values.end() - 5, 3, 341);
       
    for (auto element = values.begin(); element != values.end(); element++)
    {
        cout << *element << " ";
    }

    cout << endl;
}

void finding()
{
    vector<int> v1{5, 10, 11, 12,  15, 20, 25, 30},
        v2{3, 4, 10, 7};
     
    auto result1 = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());

    if (result1 == v1.end())
    {
        cout << "There is no match of v2 in v1." << endl;
    }
       
    else
    {
        cout << "There is at least one match of v2 in v1" << endl << " and the first one begins at "  << "position " << result1 - v1.begin() << "." << endl;

    }
       
}

void including()
{
    vector<int> v1{ 5, 10, 11, 12,  15, 20, 25, 30 }, 
        v2{ 5,10,11};

    if (includes(v2.begin(), v2.end(), v2.begin(), v2.end()))
    {
        std::cout << "includes" << endl;
    }
}

void swap_elements()
{
    vector<int> values{ 10,11,25,666 };

    auto iterator1 = values.begin();

    auto iterator2 = iterator1+2;
    
    swap(iterator1, iterator2);

    //swap(values[1], values[3]);

    for (auto element = values.begin(); element != values.end(); element++)
    {
        cout << *element << " ";
    }
    cout << endl;

    iter_swap(iterator1, iterator2);

    for (auto element = values.begin(); element != values.end(); element++)
    {
        cout << *element << " ";
    }
    cout << endl;
}

void unique_vector()
{
    vector<int> list1{ 5,7,666,10,7,7,7,7,6,7,5, 43 };

    auto new_end = unique(list1.begin(), list1.end());

    for (auto element = list1.begin(); element != new_end; element++)
    {
        cout << *element << " ";
    }

}

void DOaLL()
{
    //all_of();

    //copy();

    //equality();

    //filling();

    //finding();

    //including();

    //swap_elements();

    unique_vector();
}
