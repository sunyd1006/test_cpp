//
// Created by sunyindong on 2022/3/9.
//

#include <iostream>

#include "ex_lib_test.h"

using namespace std;

int main () {
    int a = 1, b = 2;

    swap(&a, &b);

    printf("%d %d\n", a, b);

    return EXIT_SUCCESS;
}

// 生成动态库和静态库，放入 include 目录
// g++ ex_lib_test.cpp -c -o ex_lib_test.o          # 预编译+编译+汇编
// ar rcs include/ex_lib_test_static.a ex_lib_test.o        # 链接成静态库
// g++ ex_lib_test_main.cpp include/ex_lib_test_static.a -o ex_main_static && ./ex_main_static
//
// g++ ex_lib_test.o -shared -o include/ex_main_shared.so # 建立动态链接库
// g++ ex_lib_test_main.cpp include/ex_main_shared.so -o ex_main_shared && ./ex_main_shared # 执行动态库