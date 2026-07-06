#include "unity.h"

#include "rules/divisor_rule.hpp"

void setUp(void) {}
void tearDown(void) {}

void test_divisor_rule_matches_multiple(void)
{
    DivisorRule rule(3, "Fizz");
    auto result = rule.apply(9);
    TEST_ASSERT_TRUE(result.has_value());
    TEST_ASSERT_EQUAL_STRING("Fizz", result->c_str());
}

void test_divisor_rule_does_not_match_non_multiple(void)
{
    DivisorRule rule(3, "Fizz");
    auto result = rule.apply(4);
    TEST_ASSERT_FALSE(result.has_value());
}

void test_divisor_rule_matches_zero(void)
{
    // 0 is a multiple of every non-zero divisor.
    DivisorRule rule(3, "Fizz");
    auto result = rule.apply(0);
    TEST_ASSERT_TRUE(result.has_value());
    TEST_ASSERT_EQUAL_STRING("Fizz", result->c_str());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_divisor_rule_matches_multiple);
    RUN_TEST(test_divisor_rule_does_not_match_non_multiple);
    RUN_TEST(test_divisor_rule_matches_zero);
    return UNITY_END();
}
