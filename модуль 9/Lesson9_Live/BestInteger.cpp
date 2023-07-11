#include "BestInteger.h"


std::ostream& operator<<(std::ostream& output, const BestInteger& object)
{
    output << object.m_int;
    return output;
}
