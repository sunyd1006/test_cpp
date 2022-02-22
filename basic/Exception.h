//
// Created by sun yin dong on 2021/6/7.
//

#ifndef TEST_CPP_EXCEPTION_H
#define TEST_CPP_EXCEPTION_H

#include <iostream>
#include <string>
using namespace std;

/*
那么throw()究竟有何意义呢?
其实,与其称其为"空异常描述符",
还不如称其为"中断描述符".
简单的说,如果throw()修饰的函数中发生任何异常,
即便函数外部有捕获操作,函数也不会抛出任何异常,
那么程序将直接终止!!!

简单的说,对使用throw()修饰的函数进行try{}catch(...){}
是没有任何意义的!顾,在使用throw()修饰函数的时候,
请务必确认,函数在任何情况下都不会发生异常.
*/
class Exception : public std::exception
{
public:
    /*防止隐式转换的*/
    explicit Exception(const char* what);
    explicit Exception(const string& what);
    virtual ~Exception() throw();
    virtual const char* what() const throw();
    const char* stackTrace() const throw();

private:
    void fillStackTrace();
    string message_;
    string stack_;
};

#endif //TEST_CPP_EXCEPTION_H
