#pragma once

#include <memory>
#include <string>
#include <vector>

#include "rules/substitution_rule.hpp"

std::vector<std::unique_ptr<SubstitutionRule>> buildRules(
    int int1, const std::string& str1,
    int int2, const std::string& str2);
