//
// Created by sun yin dong on 2021/6/6.
//

#ifndef TEST_CPP_BASE_H
#define TEST_CPP_BASE_H

namespace oop {
    class Base {
    private:
        int base_privite_int;
    public:
        int base_public_int;
        Base();
        virtual ~Base();
        Base(int basePriviteInt);
        virtual void printInfo();
    private:
        void printBaseClassPrivateValue();

    };

    class BasePure{
    public:
        // 纯虚函数，在子类中才需要实现，在基类中实现无意义。类似 Java 接口中的方法，或者抽象类的方法
        virtual void area()=0;
    };
}

#endif //TEST_CPP_BASE_H
