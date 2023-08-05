#pragma once

template<typename T, T ... Nums>
struct VariadicArray
{
    T m_nums[sizeof...(Nums)] = {Nums ...};

    int nums_count = sizeof ... (Nums);
};

