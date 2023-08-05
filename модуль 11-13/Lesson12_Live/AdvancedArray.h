#pragma once
#include <array>
#include <numeric>

template <class T, int size>
class AdvancedArray
{
public:

    T& operator[](int index)
    {
        return m_array[index];
    }

    T Average()
    {
       
        return std::accumulate(m_array.begin(), m_array.end(), 0.0) / size;
    }
private:
    std::array<T, size> m_array;
};
