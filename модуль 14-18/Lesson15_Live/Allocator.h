#pragma once
#include <exception>
#include <vector>


template <typename T>
class SimpleAllocator {
public:
    using value_type = T;

    //malloc
    //calloc(size, count)
    //realloc(*, newSize)
    //free(*)

    SimpleAllocator()
    {
        m_ownedMemory = malloc(10000);
        m_currentPosition = 0;
    }

    T* allocate(size_t n) {
        //auto ptr = static_cast<T*>(malloc(sizeof(T) * n));
        //if (ptr)
        //    return ptr;
        //throw std::bad_alloc();

        m_currentPosition += sizeof(T) * n;

        return  static_cast<T*>(m_ownedMemory) + m_currentPosition;
    }

    void deallocate(T* ptr, size_t n) {
        free((void*)ptr + sizeof(T) * n);
        m_currentPosition -= sizeof(T) * n;
    }

private:

    void* m_ownedMemory;
    int m_currentPosition;
};
