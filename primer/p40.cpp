//
// Created by sunyindong on 2021/12/1.
//

#include <string>
#include <iostream>

std::string global_str;
int global_int;

int main () {
    std::string local_str;
    int local_int;

    // p40 测试
    std::cout << "global_str: " <<  global_str << std::endl;
    std::cout << "global_int: " <<  global_int << std::endl;
    std::cout << "local_str: " <<  local_str << std::endl;
    std::cout << "local_int: " <<  local_int << std::endl;


    return 0;
}