#pragma once

#include <string>

#include "substitution_rule.hpp"

class DivisorRule : public SubstitutionRule
{
public:
    DivisorRule(int divisor, std::string word);
    std::optional<std::string> apply(int n) const override;

private:
    int m_divisor;
    std::string m_word;
};
