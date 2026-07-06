#include "unity.h"

#include "fizzbuzz.hpp"
#include "rule_factory.hpp"

void setUp(void) {}
void tearDown(void) {}

void test_build_rules_matches_int1_only(void)
{
    FizzBuzz fizzbuzz(buildRules(2, "Even", 7, "Lucky"));
    TEST_ASSERT_EQUAL_STRING("Even", fizzbuzz.apply(2).c_str());
}

void test_build_rules_matches_int2_only(void)
{
    FizzBuzz fizzbuzz(buildRules(2, "Even", 7, "Lucky"));
    TEST_ASSERT_EQUAL_STRING("Lucky", fizzbuzz.apply(7).c_str());
}

void test_build_rules_matches_both(void)
{
    FizzBuzz fizzbuzz(buildRules(2, "Even", 7, "Lucky"));
    TEST_ASSERT_EQUAL_STRING("EvenLucky", fizzbuzz.apply(14).c_str());
}

void test_build_rules_matches_neither(void)
{
    FizzBuzz fizzbuzz(buildRules(2, "Even", 7, "Lucky"));
    TEST_ASSERT_EQUAL_STRING("3", fizzbuzz.apply(3).c_str());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_build_rules_matches_int1_only);
    RUN_TEST(test_build_rules_matches_int2_only);
    RUN_TEST(test_build_rules_matches_both);
    RUN_TEST(test_build_rules_matches_neither);
    return UNITY_END();
}
