//
// Created by sunyindong on 2021/12/1.
//

#include <iostream>
#include <vector>

using namespace std;

int main () {
    // 两类迭代器用法
    vector<int> v;
    for (int buffer; cin >> buffer; v.push_back(buffer));

    if (v.size() < 2) {
        cout << "Please input more" << endl;
        return -1;
    }

    // cout << v.size() << endl;
    for (auto it = v.begin(); it + 1 != v.end(); it++) {
        cout << *it + *(it + 1) << endl;
    }

    char a1[] = {'c' , 'p', 'p'};
    char a2[] = {'c' , 'p', 'p', '\0'};
    cout << "size of : " << endl;
    cout << sizeof a1 / sizeof(char) << endl;
    cout << sizeof a2 / sizeof(char) << endl;

    return 0;
}