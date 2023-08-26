#pragma once
#include <vector>
#include <future>
#include <iostream>


void CalculateSum(std::vector<int> source,
    std::promise<int> accumulatePromise);

