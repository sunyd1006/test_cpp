//
// Created by sunyindong
//

#ifndef TEST_CPP_TOOL_H
#define TEST_CPP_TOOL_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

inline void println(const char *dis) {
    std::cout << dis << std::endl;
}

inline void println(std::string s) {
    std::cout << s << std::endl;
}

inline void println() {
    std::cout << std::endl;
}

inline void lnprintln(const char *dis) {
    println();
    println(dis);
}

inline void print(std::string str) {
    std::cout << str << " ";
}

using Map = std::map<std::string, std::size_t>;
inline void printMapItem(Map const& m) {
    for (auto const& kv : m)
        std::cout << kv.first << " : " << kv.second << "\n";
}

/**
 * todo: 如何 extern vector , 没有实现故而放弃
 * 转而向 ex11mian, ex10main, 里面添加了声明
 */
// define some variables
// extern std::vector<int> test_int_vec;
// extern std::vector<std::string> test_string_vec;
// extern std::list<int> test_int_list;
//
// extern const std::vector<int> int_vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// extern const std::vector<int> int_du_vec{0, 1, 2, 3, 4, 5, 5, 5, 5, 5};
// extern const std::vector<std::string> str_vec{
//         "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
// };

// define some functions
inline void test_clear() {
    // test_int_vec.clear();
    // test_string_vec.clear();
    // test_int_list.clear();
    // println(dis + std::string(" test_int_vec.size: ") + std::to_string(test_int_vec.size())
    //             + std::string(" test_string_vec.size: ") + std::to_string(test_string_vec.size()));
}

inline void clear_println(const char *dis) {
    println();
    test_clear();
    println(dis);
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
