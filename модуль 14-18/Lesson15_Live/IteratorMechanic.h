#pragma once
#include <initializer_list>
#include <memory>

template<typename ValueType>
class BestIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
    friend class BestContainer;
private:
    BestIterator(ValueType* p) :
        p(p) {};
public:
    BestIterator(const BestIterator& it) :
        p(it.p) {};

    bool operator!=(BestIterator const& other) const
    {
        return p != other.p;
    }

    bool operator==(BestIterator const& other) const
    {
        return p == other.p;
    }

    typename BestIterator::reference operator*() const
    {
        return *p;
    };


    BestIterator& operator++()
    {
        p++;
        return *this;
    }
private:
    ValueType* p;
};


class BestContainer
{
public:
    typedef BestIterator<int> iterator;
    typedef BestIterator<const int> const_iterator;

    BestContainer(std::initializer_list<int> values);

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;
private:
    const size_t size;
    std::unique_ptr<int[]> data;
};

