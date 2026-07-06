#include <iostream>

#include "fizzbuzz.hpp"
#include "rule_factory.hpp"

int main(int argc, char* argv[])
{
    if (argc != 6)
    {
        std::cerr << "Usage: " << argv[0] << " <int1> <int2> <limit> <str1> <str2>\n";
        return 1;
    }

    const int int1 = std::stoi(argv[1]);
    const int int2 = std::stoi(argv[2]);
    const int limit = std::stoi(argv[3]);
    const std::string str1 = argv[4];
    const std::string str2 = argv[5];

    const FizzBuzz fizzbuzz(buildRules(int1, str1, int2, str2));
    for (const auto& word : fizzbuzz.generate(limit))
    {
        std::cout << word << "\n";
    }
    return 0;
}
