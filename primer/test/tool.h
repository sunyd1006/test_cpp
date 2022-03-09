//
// Created by sunyindong on 2022/word_transformation_bad.txt/1.
//

#ifndef TEST_CPP_TOOL_H
#define TEST_CPP_TOOL_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

void println(const char *dis) {
    std::cout << dis << std::endl;
}

void println(std::string s) {
    std::cout << s << std::endl;
}

inline void println() {
    std::cout << std::endl;
}

void lnprintln(const char *dis) {
    println();
    println(dis);
}

void print(std::string str) {
    std::cout << str << " : ";
}

using Map = std::map<std::string, std::size_t>;
void printMapItem(Map const& m) {
    for (auto const& kv : m)
        std::cout << kv.first << " : " << kv.second << "\n";
}

auto print_int_lambda = [](const int i) { std::cout << i << " "; };

// define some variables
std::vector<int> test_int_vec;
std::vector<std::string> test_string_vec;
std::list<int> test_int_list;

std::vector<int> int_vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> int_du_vec{0, 1, 2, 3, 4, 5, 5, 5, 5, 5};
std::vector<std::string> str_vec{
        "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
};

// define some functions
inline void test_clear() {
    test_int_vec.clear();
    test_string_vec.clear();
    test_int_list.clear();
}

inline void clear_println(const char *dis) {
    println();
    test_clear();
    println(dis + std::string(" test_int_vec.size: ") + std::to_string(test_int_vec.size())
            + std::string(" test_string_vec.size: ") + std::to_string(test_string_vec.size()));
}

// print a container like vector, deque, list, etc.
template<typename Sequence>
inline std::ostream &println(Sequence const &seq, const char *dis) {
    std::cout << dis << " : ";
    for (auto const &elem : seq) {
        // if (typeid(seq) == typeid(std::pair<std::string, std::size_t>)) {
        //     std::cout << elem.first << " -> " << elem.second << " , ";
        // } else {
        //     std::cout << elem << " ";
        // }

        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return std::cout;
}

template<typename Sequence>
inline std::ostream &println(Sequence const &seq) {
    return println(seq, "容器元素为");
}


template<typename Sequence>
inline void println_clear(Sequence const &seq) {
    println(seq);
    test_clear();
}

#endif //TEST_CPP_TOOL_H
