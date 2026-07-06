#include "rule_factory.hpp"

#include "rules/composite_rule.hpp"
#include "rules/divisor_rule.hpp"

std::vector<std::unique_ptr<SubstitutionRule>> buildRules(
    int int1, const std::string& str1,
    int int2, const std::string& str2)
{
    std::vector<std::unique_ptr<SubstitutionRule>> children;
    children.push_back(std::make_unique<DivisorRule>(int1, str1));
    children.push_back(std::make_unique<DivisorRule>(int2, str2));

    std::vector<std::unique_ptr<SubstitutionRule>> rules;
    rules.push_back(std::make_unique<CompositeRule>(std::move(children)));
    return rules;
}
