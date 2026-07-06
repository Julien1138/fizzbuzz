#include "unity.h"

#include "fizzbuzz.hpp"
#include "rule_factory.hpp"
#include "rules/divisor_rule.hpp"

void setUp(void) {}
void tearDown(void) {}

// FizzBuzz orchestration, with a custom rule set independent of buildRules()

void test_fizzbuzz_returns_first_matching_rule_word(void)
{
    std::vector<std::unique_ptr<SubstitutionRule>> rules;
    rules.push_back(std::make_unique<DivisorRule>(4, "Multiple4"));
    rules.push_back(std::make_unique<DivisorRule>(2, "Even"));

    FizzBuzz fizzbuzz(std::move(rules));
    TEST_ASSERT_EQUAL_STRING("Multiple4", fizzbuzz.apply(8).c_str());
}

void test_fizzbuzz_falls_back_to_number_when_no_rule_matches(void)
{
    std::vector<std::unique_ptr<SubstitutionRule>> rules;
    rules.push_back(std::make_unique<DivisorRule>(4, "Multiple4"));

    FizzBuzz fizzbuzz(std::move(rules));
    TEST_ASSERT_EQUAL_STRING("7", fizzbuzz.apply(7).c_str());
}

// FizzBuzz behavior with buildRules(3, "Fizz", 5, "Buzz")

void test_returns_fizz_on_multiples_of_3(void)
{
    FizzBuzz fizzbuzz(buildRules(3, "Fizz", 5, "Buzz"));
    TEST_ASSERT_EQUAL_STRING("Fizz", fizzbuzz.apply(3).c_str());
}

void test_returns_buzz_on_multiples_of_5(void)
{
    FizzBuzz fizzbuzz(buildRules(3, "Fizz", 5, "Buzz"));
    TEST_ASSERT_EQUAL_STRING("Buzz", fizzbuzz.apply(5).c_str());
}

void test_returns_fizzbuzz_on_multiples_of_15(void)
{
    FizzBuzz fizzbuzz(buildRules(3, "Fizz", 5, "Buzz"));
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizzbuzz.apply(15).c_str());
}

void test_returns_number_as_string_otherwise(void)
{
    FizzBuzz fizzbuzz(buildRules(3, "Fizz", 5, "Buzz"));
    TEST_ASSERT_EQUAL_STRING("1", fizzbuzz.apply(1).c_str());
}

void test_returns_fizzbuzz_for_zero(void)
{
    // 0 is a multiple of every divisor, so both rules match.
    FizzBuzz fizzbuzz(buildRules(3, "Fizz", 5, "Buzz"));
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizzbuzz.apply(0).c_str());
}

// FizzBuzz::generate()

void test_fizzbuzz_generate_returns_expected_sequence(void)
{
    FizzBuzz fizzbuzz(buildRules(3, "Fizz", 5, "Buzz"));
    auto result = fizzbuzz.generate(5);

    TEST_ASSERT_EQUAL_INT(5, result.size());
    TEST_ASSERT_EQUAL_STRING("1", result[0].c_str());
    TEST_ASSERT_EQUAL_STRING("2", result[1].c_str());
    TEST_ASSERT_EQUAL_STRING("Fizz", result[2].c_str());
    TEST_ASSERT_EQUAL_STRING("4", result[3].c_str());
    TEST_ASSERT_EQUAL_STRING("Buzz", result[4].c_str());
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
    RUN_TEST(test_fizzbuzz_generate_returns_expected_sequence);
    return UNITY_END();
}
