#pragma once
#include <string>
#include <iostream>

template<class T>
class OurSmartPointer
{
	T* m_ptr;
public:

	OurSmartPointer(T* ptr = nullptr)
		:m_ptr(ptr)
	{
		
	}

	OurSmartPointer(OurSmartPointer& other)
	{
		m_ptr = new T(*(other.m_ptr));
	}
	

	~OurSmartPointer()
	{
		delete m_ptr;
	}

	OurSmartPointer& operator=(OurSmartPointer& other) 
	{
		if (&other == this)
			return *this;

		delete m_ptr; 
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

