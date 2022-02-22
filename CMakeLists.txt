cmake_minimum_required(VERSION 3.19)
project(test_cpp)
set(CMAKE_CXX_STANDARD 14)

# --- --- --- --- --- --- --- --- --- ---
# 生成一个名为 test_cpp的可执行文件, 等价于后面的内容
#add_executable(test_cpp main.cpp Complex.cpp Complex.h CanUseComplex.cpp CanUseComplex.h)

# 查找当前目录下, 即更目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(TEST_CPP ${DIR_SRCS} primer/ex3_36.cpp)

# 不包含的文件夹
#add_executable(TEST_CPP ${DIR_SRCS} test.cpp primer/test_2.cpp)


# 指定生成目标
add_subdirectory(oop)
add_subdirectory(basic)
add_subdirectory(template)

# 添加链接库
target_link_libraries(TEST_CPP basic oop template )

add_executable(ex11 primer/ex11.cpp)