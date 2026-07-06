#include "unity.h"

#include "fizzbuzz.hpp"
#include "rule_factory.hpp"

void setUp(void) {}
void tearDown(void) {}

void test_build_rules_matches_int1_only(void)
{
    auto rules = buildRules(2, "Even", 7, "Lucky");
    TEST_ASSERT_EQUAL_STRING("Even", fizzbuzz(2, rules).c_str());
}

void test_build_rules_matches_int2_only(void)
{
    auto rules = buildRules(2, "Even", 7, "Lucky");
    TEST_ASSERT_EQUAL_STRING("Lucky", fizzbuzz(7, rules).c_str());
}

void test_build_rules_matches_both(void)
{
    auto rules = buildRules(2, "Even", 7, "Lucky");
    TEST_ASSERT_EQUAL_STRING("EvenLucky", fizzbuzz(14, rules).c_str());
}

void test_build_rules_matches_neither(void)
{
    auto rules = buildRules(2, "Even", 7, "Lucky");
    TEST_ASSERT_EQUAL_STRING("3", fizzbuzz(3, rules).c_str());
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
