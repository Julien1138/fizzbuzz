#include "unity.h"

#include "fizzbuzz.hpp"
#include "rules/divisor_rule.hpp"

void setUp(void) {}
void tearDown(void) {}

// fizzbuzz() orchestration, with a custom rule set independent of defaultRules()

void test_fizzbuzz_returns_first_matching_rule_word(void)
{
    std::vector<std::unique_ptr<SubstitutionRule>> rules;
    rules.push_back(std::make_unique<DivisorRule>(4, "Multiple4"));
    rules.push_back(std::make_unique<DivisorRule>(2, "Even"));

    TEST_ASSERT_EQUAL_STRING("Multiple4", fizzbuzz(8, rules).c_str());
}

void test_fizzbuzz_falls_back_to_number_when_no_rule_matches(void)
{
    std::vector<std::unique_ptr<SubstitutionRule>> rules;
    rules.push_back(std::make_unique<DivisorRule>(4, "Multiple4"));

    TEST_ASSERT_EQUAL_STRING("7", fizzbuzz(7, rules).c_str());
}

// fizzbuzz() behavior with defaultRules()

void test_returns_fizz_on_multiples_of_3(void)
{
    auto rules = defaultRules();
    TEST_ASSERT_EQUAL_STRING("Fizz", fizzbuzz(3, rules).c_str());
}

void test_returns_buzz_on_multiples_of_5(void)
{
    auto rules = defaultRules();
    TEST_ASSERT_EQUAL_STRING("Buzz", fizzbuzz(5, rules).c_str());
}

void test_returns_fizzbuzz_on_multiples_of_15(void)
{
    auto rules = defaultRules();
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizzbuzz(15, rules).c_str());
}

void test_returns_number_as_string_otherwise(void)
{
    auto rules = defaultRules();
    TEST_ASSERT_EQUAL_STRING("1", fizzbuzz(1, rules).c_str());
}

void test_returns_fizzbuzz_for_zero(void)
{
    // 0 is a multiple of every divisor, so the first rule (FizzBuzz) wins.
    auto rules = defaultRules();
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizzbuzz(0, rules).c_str());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_fizzbuzz_returns_first_matching_rule_word);
    RUN_TEST(test_fizzbuzz_falls_back_to_number_when_no_rule_matches);
    RUN_TEST(test_returns_fizz_on_multiples_of_3);
    RUN_TEST(test_returns_buzz_on_multiples_of_5);
    RUN_TEST(test_returns_fizzbuzz_on_multiples_of_15);
    RUN_TEST(test_returns_number_as_string_otherwise);
    RUN_TEST(test_returns_fizzbuzz_for_zero);
    return UNITY_END();
}
