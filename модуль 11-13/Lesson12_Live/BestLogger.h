#pragma once
#include <iostream>


template<typename T>
class BestLogger
{
public:
	static std::ostream& Debug(std::ostream& source, const T& messagePart)
	{
		return source << messagePart << "; ";
	}
};

template<typename T>
std::ostream& Debug(std::ostream& source, const T& messagePart) {
	return BestLogger<T>::Debug(source, messagePart);
}


template<typename T, typename... Types>
std::ostream& Debug(std::ostream& source, const T& messagePart, const Types& ... messageParts)
{
	std::cout << std::endl << "current size: " << sizeof...(messageParts) << std::endl;

	return Debug(BestLogger<T>::Debug(source, messagePart), messageParts...);
}

//std::cout, 23, 'a', "asd", 23, 13.78, true
//std::cout, 'a', "asd", 23, 13.78, true
//std::cout, "asd", 23, 13.78, true
//...
//std::cout, true