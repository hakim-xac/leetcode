cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(TwoSum)

add_executable(TwoSum main.cpp)

target_include_directories(TwoSum PUBLIC "include")
target_link_directories(TwoSum PUBLIC "lib/Release/")
target_link_libraries(TwoSum PUBLIC "lib/Release/gmock")
target_link_libraries(TwoSum PUBLIC "lib/Release/gtest")
target_link_libraries(TwoSum PUBLIC "lib/Release/gtest_main")
target_link_libraries(TwoSum PUBLIC "lib/Release/gmock_main")

add_subdirectory(../../../googletest-main googletest)

set_target_properties(TwoSum PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

					  