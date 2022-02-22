//
// Created by sun yin dong on 2021/9/17.
//
#ifndef Sales_data_H
#define Sales_data_H

#include <iostream>
#include <string>

// syd include common util
#include "tool.h"

// 第7章 p230
class Sales_data {
    // 不用 friend 这里是无法访问私有数据成员的。有了friend 相当于不用get/set方法了
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream& out, const Sales_data& item);
    friend std::istream &read(std::istream& in, Sales_data& item);
public:
    Sales_data() = default;
    Sales_data(std::istream &is);
    Sales_data(std::string book): bookNo(book) { };
    Sales_data(std::string book, unsigned sold, double reve)
        :bookNo(book), units_sold(sold), revenue(reve) { }
    double getAvgPrice() const;
    Sales_data& combine(const Sales_data&);
    void printString();
    std::string getIsbn() const { return bookNo; } // implicit inline
    unsigned getUnitsSold() const { return units_sold; }
    double getRevenue() const { return revenue; }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

private:
    static const int valInner = 2021;
    static int valOuter;
    static int valInitByCall;     // TODO:
public:
    static int initByCall();
    void printStaticVal() {
        std::cout << " valInner: " << valInner << " valOuter: " << valOuter << " valInitByCall: "
            << valInitByCall << std::endl;
    }
};

// Sales_data相关的非成员函数
void startMain(std::istream& in, std::ostream& out);
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream& out, const Sales_data& item);
std::istream &read(std::istream& in, Sales_data& item);

// NOTE: 如果read，和 print在这里定义，则会在Sales_data-ea10df.o ex7-6f0e09.o 里面重复的符号
// std::ostream &print(std::ostream& out, const Sales_data& item) {
//     out << item.getIsbn() << " " << item.getUnitsSold() << " " << item.getRevenue() << std::endl;
//     return out;
// }
// std::istream &read(std::istream& in, Sales_data& item) {
//     in >> item.bookNo >> item.units_sold >>  item.revenue ;
//     return in;
// }

// 第二章
#endif // Sales_data_H
