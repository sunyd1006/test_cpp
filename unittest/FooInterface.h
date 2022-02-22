//
// Created by sun yin dong on 2021/6/11.
//

#ifndef TEST_CPP_FOO_H
#define TEST_CPP_FOO_H

#include <string>

// #include <gmock/gmock.h>
// #include <gtest/gtest.h>
// #include <boost/functional/hash.hpp>
// using namespace seamless;
// using ::testing::Return;

namespace seamless {
    class FooInterface {
    public:
        virtual ~FooInterface() {}

    public:
        // 虚函数，在类成员方法的声明（不是定义）语句前加“virtual”, 如 virtual void func()
        // 纯虚函数，在虚函数后加“=0”，如 virtual void func()=0
        // 对于虚函数，子类可以（也可以不）重新定义基类的虚函数，该行为称之为复写Override。
        // 对于纯虚函数，子类必须提供纯虚函数的个性化实现
        virtual std::string getArbitraryString() = 0;
    }; // namespace seamless
};

#endif //TEST_CPP_FOO_H
