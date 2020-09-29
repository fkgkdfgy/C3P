project(CPPCA)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "-std=c++11 -o3")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY devel)

find_package(Threads)

include_directories(include)

### Chapter1 hello world
add_executable(hello-world-node "chapter1 hellowrold/hello-world-node.cpp")
target_link_libraries (hello-world-node ${CMAKE_THREAD_LIBS_INIT})

add_executable(join-detach "chapter2 managing threads/join-detach.cpp")
target_link_libraries (join-detach ${CMAKE_THREAD_LIBS_INIT})