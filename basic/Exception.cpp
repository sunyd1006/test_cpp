//
// Created by sun yin dong on 2021/6/7.
//
#include <execinfo.h>
#include <stdlib.h>
#include "Exception.h"

/*保存用户信息于message_;
将堆栈信息存于stack_;*/
Exception::Exception(const char *msg)
        : message_(msg) {
    fillStackTrace();
}

/*保存用户信息于message_;
将堆栈信息存于stack_;*/
Exception::Exception(const string &msg)
        : message_(msg) {
    fillStackTrace();
}

Exception::~Exception() throw() {
}

/*返回用户信息*/
const char *Exception::what() const throw() {
    return message_.c_str();
}

/*返回堆栈信息*/
const char *Exception::stackTrace() const throw() {
    return stack_.c_str();
}

void Exception::fillStackTrace() {
    const int len = 200;
    void *buffer[len];
    int nptrs = ::backtrace(buffer, len);
    char **strings = ::backtrace_symbols(buffer, nptrs);
    if (strings) {
        for (int i = 0; i < nptrs; ++i) {
            // TODO demangle funcion name with abi::__cxa_demangle
            stack_.append(strings[i]);
            stack_.push_back('\n');
        }
        free(strings);
    }
}