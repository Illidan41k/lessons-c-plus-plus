#include "FuturePromiseUsage.h"

void CalculateSum(std::vector<int> source, std::promise<int> accumulatePromise)
{
    int sum = 0;

    for (size_t i = 0; i < source.size(); i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1300));
        sum += source[i];
        std::cout << "calculating..." << std::endl;
    }

    accumulatePromise.set_value(sum); 
}