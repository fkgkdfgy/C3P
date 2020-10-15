project(CPlusPlusPractice)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "-std=c++11 -ox")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY executable)


include_directories(
    "/usr/local/include/eigen3"
    "/usr/local/include/sophus"
)


## C++ Basic

# include-error
include_directories(BasicContent/include-error)
add_executable(include-main BasicContent/include-error/include-main.cpp)

# explicit
add_executable(explicit-test BasicContent/explicit/explicit-test.cpp)

# functor
add_executable(functor-test BasicContent/functor/functor.cpp)

# pointer-test
add_executable(pointer-test BasicContent/pointer/pointer-test.cpp)

# inline type 的测试
add_executable(inline-type-uchar ./BasicContent/inline-type/inline-type-uchar.cpp)

# Big Four Test
add_executable(big-four-in-arguments-transfer ./BasicContent/big-four-default/big-four-in-arguments-transfer.cpp)
add_executable(big_four_test ./BasicContent/big-four-default/big-four-test.cpp)

# 关于 make_shared<Derived>(Derived()) 析构两次的问题 存疑？
add_executable(virtual_dtor_base ./BasicContent/big-four-default/virtual-dtor-base.cpp)

# using
add_executable(usingtry ./BasicContent/using/usingFieldtest.cpp)

# ...参数包的测试
#add_executable(lotsofvalue ./BasicContent/lotsofvalue/lotsofvalue.cpp)

# template
add_executable(template-speciz-class ./BasicContent/template/template-specialize-class.cpp)
add_executable(templatespecFunc ./BasicContent/template/template-specialize-function.cpp)
add_executable(template-default BasicContent/template/template-default.cpp)
# macro  
    # https://cmake.org/cmake/help/v3.2/command/configure_file.html?highlight=cmakedefine
    # 以上是cmakedefine 的使用内容
    # SET 可以用于def or undef 
    SET(US_B 1)

    # message(STATUS ${US_B})

    SET(MACRO_PRAC_DIR BasicContent/macro)
    
    # 使用了cmakedefine01 后缀有个0 存疑 TODO
    SET(TEST_VAR1 AAAAAAA)

    # 使用cmakedefine
    SET(TEST_VAR2 BBBBB)

    # message(STATUS ${MACRO_PRAC_DIR})

    # message(STATUS ${PROJECT_SOURCE_DIR})

    # message(STATUS ${PROJECT_BINARY_DIR})

    # 这里的PROJECT_SOURCE_DIR 和 PROJECT_BINARY_DIR  不能更改 不然不能生成config文件
    configure_file( ${PROJECT_SOURCE_DIR}/BasicContent/macro/Config.h.in  ${PROJECT_BINARY_DIR}/config/Config.h)

    include_directories(${PROJECT_BINARY_DIR}/config)

    include_directories(BasicContent/macro)

    add_executable(macro_prac ./BasicContent/macro/macro_prac.cpp BasicContent/macro/macro.cpp)

# include_directories_recursively
# 这个部分还没有进行编写

# reference 测试
add_executable(right-reference-learning BasicContent/reference/right-value-ref-function-default.cpp)

# iherit
add_executable(inherit-relation BasicContent/inherit/inherit-relation.cpp)
add_executable(inherit-public BasicContent/inherit/inherit-public.cpp)

# 测试static 关键字
include_directories(BasicContent/static)
add_executable(static-class BasicContent/static/static-class.cpp)

## C++11 
# Variadic Templates
add_executable(vt_eg1 ./CPP11/VariadicTemplate/vt_eg1.cpp) 
# add_executable(return-function CPP11/functional/return-function.cpp) 有报错的问题

# reference 主要测试 万能引用和完美转发
add_executable(universal-reference CPP11/reference/universal-reference.cpp)
add_executable(perfect-forwarding CPP11/reference/perfect-forwarding.cpp)

## Carto-self-test Part

# functional 融合 模板类
add_executable(downsampling ./Carto-self-test/downsampling/downsampling.cpp)

# 模板类  -> 模板的type 是一个包的形式
add_executable(template_pack_class ./Carto-self-test/LidarMatcher/template_pack_class.cpp)

# vtable for 未定义报错

include_directories("Carto-self-test/downsampling")

# 用于添加所有的.cpp 文件和去除掉不需要的.cpp 文件
# file(GLOB_RECURSE ALL_SRC "Carto-self-test/downsampling/*.cpp")
# file(GLOB_RECURSE NONEED "Carto-self-test/downsampling/downsampling.cpp")
# list(REMOVE_ITEM ALL_SRC ${NONEED})

# message(STATUS ${ALL_SRC})
# # message(STATUS "the lib RAW is " ${RAW})
# add_executable(vtable_wrong_test  ./Carto-self-test/test/test-voxel-filter.cpp ${ALL_SRC})
# target_link_libraries(vtable_wrong_test
#     ${RAW}
#     )

# bitset 测试

add_executable(bitset-test ./Carto-self-test/bitset/bitset.cpp)

# Sophus Eigen 主要目的是确定 模板版本的Sophus的使用

#add_executable(sophus-test ./Carto-self-test/Sophus/sophus_test.cpp)

### ECPP 

# ECPP17 
add_executable(ECPP17 "Effective C++/ECPP17.cpp")
add_executable(ECPP33 "Effective C++/ECPP33. name-scope-in-inherit.cpp")