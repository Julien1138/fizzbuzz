#pragma once

#include <memory>
#include <string>
#include <vector>

#include "rules/substitution_rule.hpp"

std::vector<std::unique_ptr<SubstitutionRule>> defaultRules();
std::string fizzbuzz(int n, const std::vector<std::unique_ptr<SubstitutionRule>>& rules);
