#include "fizzbuzz.hpp"

std::string fizzbuzz(int n, const std::vector<std::unique_ptr<SubstitutionRule>>& rules)
{
    for (const auto& rule : rules)
    {
        if (auto result = rule->apply(n))
        {
            return *result;
        }
    }
    return std::to_string(n);
}

std::vector<std::string> fizzbuzzList(int limit, const std::vector<std::unique_ptr<SubstitutionRule>>& rules)
{
    std::vector<std::string> result;
    result.reserve(limit);
    for (int i = 1; i <= limit; ++i)
    {
        result.push_back(fizzbuzz(i, rules));
    }
    return result;
}
