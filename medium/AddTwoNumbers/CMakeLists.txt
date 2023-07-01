cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(AddTwoNumbers)

add_executable(AddTwoNumbers main.cpp)

target_include_directories(AddTwoNumbers PUBLIC "include")
target_link_directories(AddTwoNumbers PUBLIC "lib/Debug/")
target_link_libraries(AddTwoNumbers PUBLIC "lib/Debug/gmock")
target_link_libraries(AddTwoNumbers PUBLIC "lib/Debug/gtest")
target_link_libraries(AddTwoNumbers PUBLIC "lib/Debug/gtest_main")
target_link_libraries(AddTwoNumbers PUBLIC "lib/Debug/gmock_main")

add_subdirectory(../../../googletest-main googletest)

set_target_properties(AddTwoNumbers PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

