#pragma once

#include <optional>
#include <string>

class SubstitutionRule
{
public:
    virtual ~SubstitutionRule() = default;
    virtual std::optional<std::string> apply(int n) const = 0;
};
