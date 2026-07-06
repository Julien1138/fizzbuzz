#include "divisor_rule.hpp"

#include <utility>

DivisorRule::DivisorRule(int divisor, std::string word)
    : m_divisor(divisor), m_word(std::move(word))
{
}

std::optional<std::string> DivisorRule::apply(int n) const
{
    if (n % m_divisor == 0)
    {
        return m_word;
    }
    return std::nullopt;
}
