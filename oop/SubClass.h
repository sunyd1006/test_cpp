//
// Created by sun yin dong on 2021/6/6.
//

#ifndef TEST_CPP_SUBCLASS_H
#define TEST_CPP_SUBCLASS_H

#include "Base.h"

namespace oop{
    class SubClass: public Base{
    public:
        void subPrintBaseClassPrivateValue();

        virtual ~SubClass();

        // 重写定义
        void printInfo() override;
    private:
        // printBaseClass 是private 方法，如下语句可以 在SubClass设置成public
        // ISO CPP 11不允许访问声明了，Base::printBaseClassPrivateValue;
        // 只能用声明命名空间的方法
    };

    class SubClassPrivate: Base{
    public:
        void subPrintBaseClassPrivateValue();
    };

}

#endif //TEST_CPP_SUBCLASS_H
