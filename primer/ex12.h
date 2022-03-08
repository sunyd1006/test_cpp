//
// Created by sunyindong on 2022/3/3.
//

#ifndef TEST_CPP_EX12_H
#define TEST_CPP_EX12_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

using std::vector, std::string;
class StrBlobPtr;  // 先声明一下，不然后面找不到

// 多人共享底层的数据结构 vector<string> ，并互相可见更改
class StrBlob {
    friend class StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();

    StrBlob(std::initializer_list<std::string> il);

    size_type size();

    void push_back(const std::string &str);

    std::string &front();

    std::string &back();

    std::string &front() const;

    std::string &back() const;

    StrBlobPtr begin();// todo 注意这个伴随类
    StrBlobPtr end();

private:
    void check(size_type i, const std::string &msg) const;

    std::shared_ptr<std::vector<std::string>> data;
};

// 不影响 StrBlob的生存周期，但组织用户访问不存在的StrBlob
class StrBlobPtr {
    typedef vector<string>::size_type size_type;
private:
    auto check(size_type _curr, const std::string &msg) const {
        auto sptr = wptr.lock();
        if (!sptr) throw std::runtime_error("unbound StrBlobPtr");
        if (_curr >= sptr->size()) {
            throw std::out_of_range(msg);
        }
        return sptr;
    }
    std::weak_ptr <vector<string >> wptr;
    size_type curr;
public:
    StrBlobPtr() : curr(0) {};

    StrBlobPtr(StrBlob& _wptr, size_type _curr = 0) : wptr(_wptr.data), curr(_curr) {};

    string &deref() const {
        auto sp = check(curr, "out of bound");
        return (*sp)[curr];
    }

    StrBlobPtr &incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

    bool operator!=(const StrBlobPtr &p) {
        return p.curr != curr;
    }
};

#endif //TEST_CPP_EX12_H
