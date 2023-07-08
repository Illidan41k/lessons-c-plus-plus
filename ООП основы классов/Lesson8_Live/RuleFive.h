#pragma once

class RuleFive
{
private:
    int* m_value;

public:
    // Usual constructor
    RuleFive(int arg)
    {
        m_value = new int(arg);
    }

    //-------------------------------------------------

    // Destructor
    ~RuleFive()
    {
        delete m_value;
    }

    // Copy constructor
    RuleFive(const RuleFive& other)
    {
        m_value = new int;
        *m_value = *other.m_value;
    }

    // Move constructor
    RuleFive(RuleFive&& other) noexcept
    {
        m_value = other.m_value;
        other.m_value = nullptr;
    }

    // Copy assignment constructor
    RuleFive& operator=(const RuleFive& other)
    {
        if (this == &other)
            return *this;

        int* temp = new int;
        *temp = *other.m_value;
        delete[] m_value;
        m_value = temp;
        return *this;
    }

    // Move assignment constructor
    RuleFive& operator=(RuleFive&& other) noexcept
    {
        if (this == &other)
            return *this;

        delete m_value;
        m_value = other.m_value;
        other.m_value = nullptr;
        return *this;
    }

};


//RuleFive rf1(3);
//RuleFive rf2 = rf1;
//RuleFive rf2(rf1);
//rf1 = rf2;
//rf1 = std::move(rf2);