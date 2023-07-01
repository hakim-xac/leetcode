cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(RomanToInteger)

add_executable(RomanToInteger main.cpp)

target_include_directories(RomanToInteger PUBLIC "include")
target_link_directories(RomanToInteger PUBLIC "lib/Release/")
target_link_libraries(RomanToInteger PUBLIC "lib/Release/gmock")
target_link_libraries(RomanToInteger PUBLIC "lib/Release/gtest")
target_link_libraries(RomanToInteger PUBLIC "lib/Release/gtest_main")
target_link_libraries(RomanToInteger PUBLIC "lib/Release/gmock_main")

add_subdirectory(../../../googletest-main googletest)

set_target_properties(RomanToInteger PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

					  