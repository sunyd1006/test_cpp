#include <iostream>
#include <iterator>
#include <vector>
#include <cstring>
#include <stdexcept>

// current file include
#include <map>
#include <set>
#include <algorithm>
#include <utility>

// #include "ex7.h"
#include "Sales_data.h"
#include "Sales_item.h"
#include "tool.h"
#include <sstream>
#include <fstream>

using namespace std;

//for ex11.4
// auto strip(string str) -> string {
auto strip(string str) -> string const & {
    auto ispunct = [](char c) { return (c == '.' || c == ',') ? true : false; };
    for (auto &ch : str) ch = tolower(ch);
    str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
    return str;
}

//  ex11_11.cpp
auto less(Sales_data const &lhs, Sales_data const &rhs) {
    return lhs.getIsbn() < rhs.getIsbn();
}

// g14  ex99.cpp -o main && ./main
int main() {
    clear_println("\n习题 ------ ex11.3 ");
    ifstream filein("./ex10/test_file.txt");
    istream_iterator<string> file_it(filein), file_eof;
    set<string> exclude = {"is", "a"};
    map<string, size_t> word_count;
    while (file_it != file_eof) {
        if (exclude.find(*file_it) == exclude.end()) {
            ++word_count[strip(*file_it)];
        }
        ++file_it;
    }
    for (const auto &item : word_count) {
        std::cout << item.first << " -> " << item.second << "   ";
    }

    clear_println("\n习题 ------ ex11.9 ");
    // ex 11.9
    std::map<std::string, std::list<std::size_t>> m;

    // ex 11.10
    // can be declared.
    std::map<std::vector<int>::iterator, int> mv;
    std::map<std::list<int>::iterator, int> ml;
    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

    // TODO 注意 list 未定义 <
    // but when using this one the compiler complained that
    // error: no match for 'operator<' in '__x < __y'
    // std::list<int> li;
    // ml.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));

    clear_println("\n习题 ------ ex11.11 ");
    using Less = bool (*)(Sales_data const&, Sales_data const&);
    std::multiset<Sales_data, Less> bookstore(Less);

    clear_println("\n习题 ------ ex11.13 pair插入方式");
    vector<pair<string, int>> test_pair_vec;
    test_pair_vec.push_back(make_pair("sun", 1));
    test_pair_vec.push_back(std::make_pair("ying", 2));
    test_pair_vec.push_back({ "dong", 3});
    test_pair_vec.emplace_back("yeah", 4); //!! easiest way.
    for (const auto &item : test_pair_vec) {
        cout << item.first << " " << item.second << " ";
    }
    println();

    clear_println("\n习题 ------ ex11.17");
    test_string_vec.push_back("test_string_vec");
    multiset<string> str_multiset{"mutiset", "mutiset"};
    copy(test_string_vec.begin(), test_string_vec.end(), inserter(str_multiset, str_multiset.end())); // legal
    println_clear(str_multiset);
    // todo // illegal, no `push_back` in `set`.
    // copy(test_string_vec.begin(), test_string_vec.end(),  back_inserter(str_multiset));
    // print(str_multiset);

    copy(str_multiset.begin(), str_multiset.end(), inserter(test_string_vec, test_string_vec.end())); // legal.
    std::cout << test_string_vec.size() ;
    println_clear(test_string_vec);
    copy(str_multiset.begin(), str_multiset.end(), back_inserter(test_string_vec)); // legal.
    println_clear(test_string_vec);

    str_multiset.insert("insertByFunc");
    println(str_multiset);


    clear_println("\n习题 ------ ex11.23 ");
    istringstream iStr("sun hao hu wenrui sun yindong");
    string fname, lname;
    map<string, vector<string>> count_map;
    multimap<string, string> count_multi;
    while (iStr >> fname >> lname) {
        count_map[fname].push_back(lname);
        count_multi.insert({fname, lname});
    }
    for (const auto &item : count_map) {
        std::cout << item.first << " -> ";
        println(item.second);
    }
    for (const auto &item : count_multi) {
        std::cout << item.first << " -> " << item.second << "   ";
    }

    // ----------------------------------------------
    // clear_println("\n习题 ------ ex10.36 ");
    // clear_println("\n章节 ------------------ 10.2");

    return 0;
};
