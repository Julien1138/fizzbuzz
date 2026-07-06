#pragma once

#include <memory>
#include <string>
#include <vector>

#include "rules/substitution_rule.hpp"

class FizzBuzz
{
public:
    explicit FizzBuzz(std::vector<std::unique_ptr<SubstitutionRule>> rules);

    std::string apply(int n) const;
    std::vector<std::string> generate(int limit) const;

private:
    std::vector<std::unique_ptr<SubstitutionRule>> m_rules;
};
