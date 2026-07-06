#pragma once

#include <memory>
#include <string>
#include <vector>

#include "rules/substitution_rule.hpp"

std::string fizzbuzz(int n, const std::vector<std::unique_ptr<SubstitutionRule>>& rules);
std::vector<std::string> fizzbuzzList(int limit, const std::vector<std::unique_ptr<SubstitutionRule>>& rules);
