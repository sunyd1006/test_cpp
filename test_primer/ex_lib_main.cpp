//
// Created by sunyindong on 2022/3/9.
//

#include <iostream>

#include "ex_lib.h"

using namespace std;

int main () {
    int a = 1, b = 2;

    swap(&a, &b);

    printf("%d %d\n", a, b);

    return EXIT_SUCCESS;
}

// 生成动态库和静态库，放入 include 目录
// --- 静态库编译和使用命令
// g++ ex_lib.cpp -c -o ex_lib.o                   # 预编译+编译+汇编
// ar rcs include/ex_lib_static.a ex_lib.o              # 链接成静态库
// g++ ex_lib_main.cpp include/ex_lib_static.a -o ex_static && ./ex_static # 使用静态库

// --- 动态库编译和使用命令
// g++ ex_lib.o -fPIC -shared -o include/ex_lib_shared.so    # 建立动态链接库
// 使用时，要么扩展动态库搜索目录 export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH 2. 要么执行是-L指定目录 -l指定具体动态库
// g++ ex_lib_main.cpp include/ex_lib_shared.so -o ex_shared && ./ex_shared # 使用动态库
// g++ ex_lib_main.cpp -L/Users/sunyindong/codespace/test_cpp/primer/include -lex_lib_shared -o ex_shared && ./ex_shared # 使用动态库