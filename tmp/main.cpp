#include <iostream>
#include <set>
using namespace std;

struct song {
    int m_id;
    int m_hot;

    song(int id, int hot) {
        this->m_id = id;
        this->m_hot = hot;
    }
    // bool operator<(const struct song & right)const   //重载<运算符{
    //     if(this->m_id == right.m_id)     //根据id去重
    //         return false;
    //     else
    //     {
    //         if(this->m_hot != right.m_hot)
    //         {
    //             // return this->m_hot > right.m_hot;      //降序
    //             return this->m_hot < right.m_hot;      //降序
    //         }
    //         else
    //         {
    //             // return this->m_id > right.m_id;
    //             return this->m_id < right.m_id;
    //         }
    //     }
    // }
    // bool operator<(const struct song & right) const  {
    //     return this->m_id < right.m_id;
    // }
};

bool operator<(const struct song &left, const struct song &right) {
    return left.m_id < right.m_id;
}

int main() {
    std::set<song> mySet;
    song s1(10, 100);
    song s2(20, 200);
    song s3(20, 300);
    song s4(30, 200);
    mySet.insert(s1);    //插入s1
    mySet.insert(s2);    //插入s2
    mySet.insert(s3);    //s3和s2的id相同，不插入
    mySet.insert(s4);    //插入s4
    for (auto it:mySet) {
        std::cout << "id:" << it.m_id << ",hot:" << it.m_hot << std::endl;
    }
    std::cout << "end" << std::endl;
    return 0;
};