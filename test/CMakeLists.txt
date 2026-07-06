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
