#include "unity.h"

#include "fizzbuzz.hpp"

void setUp(void) {}
void tearDown(void) {}

void test_returns_fizz_on_multiples_of_3(void)
{
    TEST_ASSERT_EQUAL_STRING("Fizz", fizzbuzz(3).c_str());
}

void test_returns_buzz_on_multiples_of_5(void)
{
    TEST_ASSERT_EQUAL_STRING("Buzz", fizzbuzz(5).c_str());
}

void test_returns_fizzbuzz_on_multiples_of_15(void)
{
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizzbuzz(15).c_str());
}

void test_returns_number_as_string_otherwise(void)
{
    TEST_ASSERT_EQUAL_STRING("1", fizzbuzz(1).c_str());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_returns_fizz_on_multiples_of_3);
    RUN_TEST(test_returns_buzz_on_multiples_of_5);
    RUN_TEST(test_returns_fizzbuzz_on_multiples_of_15);
    RUN_TEST(test_returns_number_as_string_otherwise);
    return UNITY_END();
}
