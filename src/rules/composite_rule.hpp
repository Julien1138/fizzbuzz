#pragma once

#include <memory>
#include <vector>

#include "substitution_rule.hpp"

class CompositeRule : public SubstitutionRule
{
public:
    explicit CompositeRule(std::vector<std::unique_ptr<SubstitutionRule>> children);
    std::optional<std::string> apply(int n) const override;

private:
    std::vector<std::unique_ptr<SubstitutionRule>> m_children;
};
