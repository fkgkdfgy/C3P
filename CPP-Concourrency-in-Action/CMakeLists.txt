project(CPPCA)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "-std=c++14 -o3")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY devel)
set(CMAKE_BUILD_TYPE DEBUG)

find_package(Threads)

include_directories(include)

### baseline
## 1. 多线程的创建和mutex 锁
add_executable(thread_create_and_mutex "baseline/thread_create_and_mutex.cpp")
target_link_libraries(thread_create_and_mutex ${CMAKE_THREAD_LIBS_INIT})

## 2. Condition_Variable 和mutex 综合使用
add_executable(condition_variable_and_mutex "baseline/condition_variable_and_mutex.cpp")
target_link_libraries(condition_variable_and_mutex ${CMAKE_THREAD_LIBS_INIT})

## 3. future 和 Async 的使用
add_executable(future_and_async "baseline/future_and_async.cpp")
target_link_libraries(future_and_async ${CMAKE_THREAD_LIBS_INIT})

## 4. 线程池简单实现
add_executable(thread_pool_simple "baseline/thread_pool_simple.cpp")
target_link_libraries(thread_pool_simple ${CMAKE_THREAD_LIBS_INIT})

## 5. atomic if CPU 占用查看
add_executable(simple_test_atomic_if "baseline/simple_test_atomic_if.cpp")
target_link_libraries(simple_test_atomic_if ${CMAKE_THREAD_LIBS_INIT})


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