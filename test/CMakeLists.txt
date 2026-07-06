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

add_executable(test_rules test_rules.cpp)
target_link_libraries(test_rules PRIVATE fizzbuzz_lib unity)
add_test(NAME rules_tests COMMAND test_rules)
