#include "composite_rule.hpp"

#include <utility>

CompositeRule::CompositeRule(std::vector<std::unique_ptr<SubstitutionRule>> children)
    : m_children(std::move(children))
{
}

std::optional<std::string> CompositeRule::apply(int n) const
{
    std::string result;
    for (const auto& child : m_children)
    {
        if (auto word = child->apply(n))
        {
            result += *word;
        }
    }
    if (result.empty())
    {
        return std::nullopt;
    }
    return result;
}
