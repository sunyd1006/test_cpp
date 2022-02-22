//
// Created by sunyindong on 2021/12/14.
//

#include <iostream>
#include <iterator>
#include <vector>

#include <cstring>

using namespace  std;

void check_and_print(vector<int> &vec) {
    cout << " vector<int> size: " << vec.size() << " content: ";
    for (const auto &item : vec) {
        cout << item << ",";
    }
    cout << endl;
}

void check_and_print(vector<string> &vec) {
    cout << " vector<string> size: " << vec.size() << " content: ";
    // use 迭代器
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << (it + 1 != vec.end() ? "," : "");
    }
    cout << endl;
}

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{ 10 };
    vector<int> v5{ 10, 42 };
    vector<string> v6{ 10 };
    vector<string> v7{ 10, "hi" };

    check_and_print(v1);
    check_and_print(v2);
    check_and_print(v3);
    check_and_print(v4);
    check_and_print(v5);
    check_and_print(v6);
    check_and_print(v7);
};
