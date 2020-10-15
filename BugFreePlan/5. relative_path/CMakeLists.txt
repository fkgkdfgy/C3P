project(relative_path)
cmake_minimum_required(VERSION 3.1)
# 如果地址是 ./bin 那么cmake 不会自动创建文件夹 
# 基于bin进行的executable 会失败
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(relative_path ./foo.cpp)