cmake_minimum_required(VERSION 3.19)
project(tmp)
set(CMAKE_CXX_STANDARD 14)

# --- --- --- --- --- --- --- --- --- ---
# 生成一个名为 test_cpp的可执行文件, 等价于后面的内容
#add_executable(test_cpp main.cpp Complex.cpp Complex.h CanUseComplex.cpp CanUseComplex.h)
# --- --- --- --- --- --- --- --- --- ---

# 查找当前目录下, 即跟目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 指定生成目标
add_executable(TMP ${DIR_SRCS})
target_link_libraries(TMP basic oop template )