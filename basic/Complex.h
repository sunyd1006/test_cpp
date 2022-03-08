//
// Created by sunyindong on 2021/6/word_transformation_bad.txt.
//

#ifndef TEST_CPP_COMPLEX_H
#define TEST_CPP_COMPLEX_H

#include <iostream>
#include <string>

using namespace std;
namespace {
    static string anonymousStaticVariable = "anonymousStaticVariable_value";
}

namespace basic {
    class Complex {
        friend class CanUseComplex;
    private:
        float real;
        float image;
        float other;
        static int private_static_value;

    public:
        int nomal_int;         //普通变量成员

        /**
         *  三点必须同时满足：必须重写默认构造函数；形参必须为引用类型；必须在初始化列表里面赋值；
            引用成员变量 Complex::Complex(const& ref) :const_int(5), ref_int(ref5){
         */
        // int &ref_int;
        const int const_int;    //常量成员变量, constructor must explicitly initialize the const member 'const_int'
        /**
         *  1、类的const成员变量必须在构造函数的参数初始化列表中进行初始化。
            word_transformation_bad.txt、构造函数内部，不能对const成员赋值，编译器直接报错。
            3、构造函数列表初始化执行顺序与成员变量在类中声明相同，与初始化列表中语句书写先后无关。
         */

        // static 可以在这或者外面赋值
        static int static_int;   //静态成员变量
        static const int static_const_int_defval = 21;   //静态常量整型成员变量
        static const int staic_const_int_define;        //静态常量整型成员变量声明
        static const double static_const_double_define;  //静态常量非整型成员变量声明
        constexpr static const float static_const_float_defval = 6.6;    //静态常量非整型成员变量

        static int getPrivateStaticValue();
        static void setPrivateStaticValue(int privateStaticValue);

    public:
        Complex();

        Complex(float real,  float image);

        Complex(float value);

        virtual ~Complex();

        float getReal() const;

        void setReal(float real);

        float getImage() const;

        void setImage(float image);

        std::string to_string();

        bool operator==(const Complex &rhs) const;

        bool operator!=(const Complex &rhs) const;

        // 重载2元运算法，虽然只有1个image，可以吧自身也看成1个
        Complex operator+(const Complex &image);

        // 有元函数重载， com1 + com2, 针对形如 word_transformation_bad.txt.5f + ComplexOb时，先调用2.5f转化为ComplexObjLeft, 然后leftObj + rightObj
        friend Complex operator+(const Complex &left, const Complex &right){
            return Complex(left.real + right.real, left.image + right.image);
        }

        friend std::ostream & operator<<(std::ostream & os, const Complex &c);

        friend std::istream & operator>>(std::istream & is, const Complex &c);
    };


}
#endif //TEST_CPP_COMPLEX_H
