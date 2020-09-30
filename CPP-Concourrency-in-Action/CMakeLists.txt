project(CPPCA)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "-std=c++11 -o3")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY devel)

find_package(Threads)

include_directories(include)

### Chapter1 hello world
add_executable(hello_world_node "chapter1 hellowrold/hello_world_node.cpp")
target_link_libraries (hello_world_node ${CMAKE_THREAD_LIBS_INIT})


### Chapter2
## 1 
add_executable(create_thread "chapter2 managing threads/create_thread.cpp")
target_link_libraries (create_thread ${CMAKE_THREAD_LIBS_INIT})

## 2
add_executable(join_detach "chapter2 managing threads/join_detach.cpp")
target_link_libraries (join_detach ${CMAKE_THREAD_LIBS_INIT})

## 3 
add_executable(thread_guard "chapter2 managing threads/thread_guard.cpp")
target_link_libraries (thread_guard ${CMAKE_THREAD_LIBS_INIT})

## 4
add_executable(arguments_pass_for_thread "chapter2 managing threads/arguments_pass_for_thread.cpp")
target_link_libraries (arguments_pass_for_thread ${CMAKE_THREAD_LIBS_INIT})

## 5 
add_executable(parallel_accumulate "chapter2 managing threads/parallel_accumulate.cpp")
target_link_libraries (parallel_accumulate ${CMAKE_THREAD_LIBS_INIT})