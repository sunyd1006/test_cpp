//
// Created by sunyindong on 2021/12/1.
//

#include <iostream>
#include <vector>

using namespace std;

int main () {
    // 两类迭代器用法
    vector<int> vec(10, 1);
    for (auto &item : vec) {
       item *= 2;
    }

    for (const auto &item : vec) {
        cout << item << " ";
    }

    for (auto it = vec.cbegin(); it != vec.cend(); it++) {
        cout << *it << " ";
    }
    return 0;
}