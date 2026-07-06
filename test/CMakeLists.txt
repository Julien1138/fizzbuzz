include(FetchContent)
FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.6.0
)
FetchContent_MakeAvailable(unity)

add_executable(test_fizzbuzz test_fizzbuzz.cpp)
target_link_libraries(test_fizzbuzz PRIVATE fizzbuzz_lib unity)
add_test(NAME fizzbuzz_tests COMMAND test_fizzbuzz)

add_executable(test_divisor_rule test_divisor_rule.cpp)
target_link_libraries(test_divisor_rule PRIVATE fizzbuzz_lib unity)
add_test(NAME divisor_rule_tests COMMAND test_divisor_rule)

add_executable(test_composite_rule test_composite_rule.cpp)
target_link_libraries(test_composite_rule PRIVATE fizzbuzz_lib unity)
add_test(NAME composite_rule_tests COMMAND test_composite_rule)
