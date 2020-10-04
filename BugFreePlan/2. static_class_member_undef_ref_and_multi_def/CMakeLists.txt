project(static_member_problem)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

include_directories()

add_executable(multi_def multi_def.cpp foo.hpp foo.cpp)