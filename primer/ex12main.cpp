#include <iostream>
#include <iterator>
#include <vector>
#include <cstring>
#include <stdexcept>

// current file include
#include <memory> // for make_shared<>

#include "ex12.h"
#include "Sales_data.h"
#include "Sales_item.h"
#include "tool.h"
#include <sstream>
#include <fstream>

using namespace  std;

// define current function
size_t static_count_func() {
    static size_t static_count_func_val = 0;
    return ++static_count_func_val;
}

// ex12.6
auto get_dynamic_vec() {
    return new vector<int>();
}
using dynamicVecPtr = vector<int>*;
auto init_dynamic_vec(dynamicVecPtr ptr) {
    // for (int tmp; cin >> tmp; ptr->push_back(tmp));
    for (int i = 0; i < 5; ++i) {
        ptr->push_back(i);
    }
    return ptr;
}

// ex12.7
using dynamicVecSPtr = shared_ptr<vector<int>>;
auto get_dynamic_sp_vec() {
    return make_shared<vector<int>>();
}
auto init_dynamic_vec(dynamicVecSPtr ptr) {
    for (int i = 0; i < 6; ++i) {
        ptr->push_back(i);
    }
    return ptr;
}

// ex12.14
struct SunConnection {
    string name;
    SunConnection();
    SunConnection(string _name): name(_name) {};
};

void auto_free_use_connection(const string str) {
    SunConnection conn(str);
    println("正在使用: " + conn.name);
    auto deleteMethod = [] (const SunConnection* ptr) {
        println("Delete " + (ptr->name) + " now.");
        // delete ptr;   // todo 此处模拟是应该用于关闭资源，而为何会报错呢?
    };
    // shared_ptr<SunConnection, decltype(deleteMethod) *> sptr(conPtr, deleteMethod);
    shared_ptr<SunConnection> sptr(&conn, deleteMethod);
    println("即将结束使用: " + (sptr->name));
}


// g14 ex12.cpp ex12main.cpp -o main && ./main
int main() {
    clear_println("\n章节 ------------------ 12 测试 static 变量");
    for (auto i = 0; i != 5; ++i) {
        cout << static_count_func() << " ";
    }
    println();

    clear_println("\n习题 ------ ex12.2 ");
    const StrBlob csb{ "hello", "world", "pezy" };
    StrBlob sb{ "hello", "world", "pezy" };

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "Mooophy";
    std::cout << sb.front() << " " << sb.back() << std::endl;

    clear_println("\n习题 ------ ex12.6 ");
    auto ex126 = init_dynamic_vec(get_dynamic_vec());
    println(*ex126);
    delete ex126;

    clear_println("\n习题 ------ ex12.7 ");
    auto ex127 = init_dynamic_vec(get_dynamic_sp_vec());
    println(*ex127);

    clear_println("\n习题 ------ ex12.14 ");
    auto_free_use_connection(string("CONNECTION"));

    clear_println("\n习题 ------ ex12.16 ");
    unique_ptr<string> ex16(new string("unique_ptr_value"));
    // unique_ptr<string> p2(ex16); // copy
    //                      ^
    // Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
    //
    // unique_ptr<string> p3 = ex16; // assign
    //                      ^
    // Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
    std::cout << *ex16 << std::endl;
    ex16.reset();
    // ex16.reset(nullptr);

    clear_println("\n习题 ------ ex12.19 ");
    std::ifstream ifs("./data/book.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;

    clear_println("\n习题 ------ ex12.19 ");


    clear_println("\n习题 ------ ex12.19 ");


    clear_println("\n习题 ------ ex12.19 ");


    clear_println("\n习题 ------ ex12.19 ");


    // ----------------------------------------------
    // clear_println("\n习题 ------ ex10.36 ");
    // clear_println("\n章节 ------------------ 10.word_transformation_bad.txt");

    return 0;
};
