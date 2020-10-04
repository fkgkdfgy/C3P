 project(template_linker)
 cmake_minimum_required(VERSION 3.5)
 set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
 
 include_directories()

 add_executable(linker_test main.cpp foo.hpp foo.cpp foo.int.cpp)
