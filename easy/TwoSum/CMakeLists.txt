cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(project_name TwoSum)
set(path_include "../../../googletest-main/googletest/include")
set(path_gtest "../../../googletest-main")

project(${project_name})

add_subdirectory(${path_gtest} googletest)

add_executable(${project_name} main.cpp)

target_include_directories(${project_name} PUBLIC ${path_include})


find_package(gtest REQUIRED)

target_link_libraries(${project_name} PRIVATE gtest)

set_target_properties(${project_name} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

