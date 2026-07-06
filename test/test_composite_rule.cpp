#include "unity.h"

#include "rules/composite_rule.hpp"
#include "rules/divisor_rule.hpp"

void setUp(void) {}
void tearDown(void) {}

std::vector<std::unique_ptr<SubstitutionRule>> makeChildren()
{
    std::vector<std::unique_ptr<SubstitutionRule>> children;
    children.push_back(std::make_unique<DivisorRule>(3, "Fizz"));
    children.push_back(std::make_unique<DivisorRule>(5, "Buzz"));
    return children;
}

void test_composite_rule_returns_first_child_word_when_only_it_matches(void)
{
    CompositeRule rule(makeChildren());
    auto result = rule.apply(3);
    TEST_ASSERT_TRUE(result.has_value());
    TEST_ASSERT_EQUAL_STRING("Fizz", result->c_str());
}

void test_composite_rule_returns_second_child_word_when_only_it_matches(void)
{
    CompositeRule rule(makeChildren());
    auto result = rule.apply(5);
    TEST_ASSERT_TRUE(result.has_value());
    TEST_ASSERT_EQUAL_STRING("Buzz", result->c_str());
}

void test_composite_rule_concatenates_words_when_both_children_match(void)
{
    CompositeRule rule(makeChildren());
    auto result = rule.apply(15);
    TEST_ASSERT_TRUE(result.has_value());
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", result->c_str());
}

void test_composite_rule_returns_nullopt_when_no_child_matches(void)
{
    CompositeRule rule(makeChildren());
    auto result = rule.apply(7);
    TEST_ASSERT_FALSE(result.has_value());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_composite_rule_returns_first_child_word_when_only_it_matches);
    RUN_TEST(test_composite_rule_returns_second_child_word_when_only_it_matches);
    RUN_TEST(test_composite_rule_concatenates_words_when_both_children_match);
    RUN_TEST(test_composite_rule_returns_nullopt_when_no_child_matches);
    return UNITY_END();
}
