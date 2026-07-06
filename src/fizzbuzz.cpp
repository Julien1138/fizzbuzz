#include "fizzbuzz.hpp"

#include <utility>

FizzBuzz::FizzBuzz(std::vector<std::unique_ptr<SubstitutionRule>> rules)
    : m_rules(std::move(rules))
{
}

std::string FizzBuzz::apply(int n) const
{
    for (const auto& rule : m_rules)
    {
        if (auto result = rule->apply(n))
        {
            return *result;
        }
    }
    return std::to_string(n);
}

std::vector<std::string> FizzBuzz::generate(int limit) const
{
    std::vector<std::string> result;
    result.reserve(limit);
    for (int i = 1; i <= limit; ++i)
    {
        result.push_back(apply(i));
    }
    return result;
}
