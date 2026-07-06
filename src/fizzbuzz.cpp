#include "fizzbuzz.hpp"

#include "rules/divisor_rule.hpp"

std::vector<std::unique_ptr<SubstitutionRule>> defaultRules()
{
    std::vector<std::unique_ptr<SubstitutionRule>> rules;
    rules.push_back(std::make_unique<DivisorRule>(15, "FizzBuzz"));
    rules.push_back(std::make_unique<DivisorRule>(3, "Fizz"));
    rules.push_back(std::make_unique<DivisorRule>(5, "Buzz"));
    return rules;
}

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
