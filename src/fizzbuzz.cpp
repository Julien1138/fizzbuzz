#include "fizzbuzz.hpp"

#include "rules/composite_rule.hpp"
#include "rules/divisor_rule.hpp"

std::vector<std::unique_ptr<SubstitutionRule>> defaultRules()
{
    std::vector<std::unique_ptr<SubstitutionRule>> children;
    children.push_back(std::make_unique<DivisorRule>(3, "Fizz"));
    children.push_back(std::make_unique<DivisorRule>(5, "Buzz"));

    std::vector<std::unique_ptr<SubstitutionRule>> rules;
    rules.push_back(std::make_unique<CompositeRule>(std::move(children)));
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
