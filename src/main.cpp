#include <iostream>

#include "fizzbuzz.hpp"

int main()
{
    const auto rules = defaultRules();
    for (int i = 1; i <= 100; ++i)
    {
        std::cout << fizzbuzz(i, rules) << "\n";
    }
    return 0;
}
