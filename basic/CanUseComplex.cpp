//
// Created by sun yin dong on 2021/6/3.
//


#include "iostream"

#include "Complex.h"
#include "CanUseComplex.h"

// 在CanUseComplex 和 Complex 处重复定义，却没有加命名空间
// int nConflict;
namespace basic{
    void CanUseComplex::sayClassInfo() {
        std::cout << Complex::private_static_value << std::endl;
        std::cout << "I'm CanUseComplex! " << std::endl;
    }
}
