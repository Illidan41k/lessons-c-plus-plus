#include "IteratorMechanic.h"


BestContainer::BestContainer(std::initializer_list<int> values) :
    size(values.size()),
    data(new int[size])
{
    std::copy(values.begin(), values.end(), data.get());
}

BestContainer::iterator BestContainer::begin()
{
    return iterator(data.get());
}

BestContainer::iterator BestContainer::end()
{
    return iterator(data.get() + size);
}

BestContainer::const_iterator BestContainer::begin() const
{
    return const_iterator(data.get());
}

BestContainer::const_iterator BestContainer::end() const
{
    return const_iterator(data.get() + size);
}



