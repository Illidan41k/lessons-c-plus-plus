#pragma once
#include <iostream>
#include <memory>

template <class T>
class GenericStorage
{

public:
    GenericStorage(T value)
    {
        m_value = value;
    }

    void print()
    {
        if (std::is_same<T, bool>::value) 
        {
            std::cout << "This one is boolean: ";
        }

        std::cout << m_value << std::endl;
    }

private:
    T m_value;
};



template <class T>
class GenericStorage<std::shared_ptr<T>> 
{

public:
    GenericStorage(std::shared_ptr<T> value)
    {
        m_value = std::make_shared<T>(*value); 
    }

    void print()
    {
        std::cout << *m_value << std::endl;
    }

private:
    std::shared_ptr<T> m_value;
};
