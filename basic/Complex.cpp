//
// Created by sunyindong on 2021/6/word_transformation_bad.txt.
//

#include "Complex.h"

namespace basic{
    static string test_cpp_define_h_can_find = "h_can_print_this_line";  // h 不能访问他
    int Complex::private_static_value = 100;

    // public:
    int Complex::static_int = 2;
    const int Complex::staic_const_int_define = 4;               // 静态常量整型成员变量定义
    const double Complex::static_const_double_define = 5.1;      // 静态常量非整型成员变量定义

    // 使用参数化列表
    Complex::Complex(float value) : real(value), const_int(5){
    }
    Complex::Complex() :const_int(5) {
    }
    Complex::Complex(float real, float image) : real(real), image(image), const_int(5){
        other = image+5;
        cout << " call anonymousStaticVariable: " << anonymousStaticVariable << endl;
    }
    Complex::~Complex() {
        // delete &static_value;
        std::cout << to_string() << "  destructed" << std::endl;
        cout << " call anonymousStaticVariable: " << anonymousStaticVariable << endl;
    }

    Complex Complex::operator+(const Complex &image) {
        return Complex(this->real + image.getReal(), this->image + image.getImage());
    }

    bool Complex::operator==(const Complex &rhs) const {
        return private_static_value == rhs.private_static_value;
    }

    bool Complex::operator!=(const Complex &rhs) const {
        return !(rhs == *this);
    }

    std::string Complex::to_string() {
        return std::to_string(real) + " + (" + std::to_string(image) + ")i";
    }

    float Complex::getReal() const {
        return real;
    }

    void Complex::setReal(float real) {
        Complex::real = real;
    }

    float Complex::getImage() const {
        return image;
    }

    void Complex::setImage(float image) {
        Complex::image = image;
    }

    std::ostream &operator<<(std::ostream &os, const Complex &c) {
        os << c.real << " + (" << c.image << ")i";
        return os;
    }

    std::istream &operator>>(std::istream &is, const Complex &c) {
        is >> c.real >> c.image;
        return is;
    }

    int Complex::getPrivateStaticValue() {
        return private_static_value;
    }

    void Complex::setPrivateStaticValue(int privateStaticValue) {
        private_static_value = privateStaticValue;
    }
}
