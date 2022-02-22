//
// Created by sun yin dong on 2021/9/17.
//

#ifndef TEST_CPP_STL_TEST_H
#define TEST_CPP_STL_TEST_H

#include <iostream>

struct IsCheckedKeyTuple {
    std::string tenantId;
    std::string clusterName;
    std::string quotaId;
    // 比较运算符重载,按位置排序,必须const, https://blog.csdn.net/sichuanpb/article/details/95449589
    // -原则：永远让比较函数对相同元素返回false
    // set<IsCheckedKeyTuple> 必须要实现这个默认排序的函数, //排序并且去重复
    // bool operator<(const IsCheckedKeyTuple &a) const {
    //     if (tenantId < a.tenantId) return true;
    //     if (tenantId == a.tenantId && clusterName < a.clusterName) return true;
    //     if (tenantId == a.tenantId && clusterName == a.clusterName && quotaId < a.quotaId) return true;
    //     return false;
    // }
};
bool operator<(const IsCheckedKeyTuple &a, const IsCheckedKeyTuple &b) {
    // 按照 tenantId 去重。 按照clusterName, quotaId排序
    if (b.tenantId == a.tenantId){
        return false;
    }else{
        if (b.clusterName < a.clusterName) return true;
        if (b.clusterName == a.clusterName && b.quotaId < a.quotaId) return true;
    }
    return false;
}

typedef std::pair<std::string , std::string > strPair;
// https://blog.csdn.net/tennysonsky/article/details/77389891
void printPair(std::pair<std::string , std::string > arg) {
    std::cout << "(" << arg.first  << "," << arg.second << ")" << std::endl;
}

template <class ... Args>
void printPair(strPair t, Args ... args)
{
    printPair(t);
    printPair(args...);
}


struct IsCheckedKeyTupleHash {
    /*
     * ()是一个仿函数：一个对象就可以向函数一样进行调用了
     * https://www.cnblogs.com/jiu0821/p/6554169.html
     */
    size_t operator()(const struct IsCheckedKeyTuple &_r) const {
        std::string key = _r.tenantId + "###" + _r.clusterName + "###" + _r.quotaId;
        return std::hash<std::string>()(key);
    }
};

// https://www.cnblogs.com/xiaoniu-666/p/9492967.html
// 1. 建议 unordered_map, unordered_set 的 hash, compare 都用struct的格式
struct IsCheckedKeyTupleComp {
    bool operator()(const struct IsCheckedKeyTuple &X, const struct IsCheckedKeyTuple &Y) const {
        return std::hash<std::string>()(X.tenantId + "###" + X.clusterName + "###" + X.quotaId) ==
                std::hash<std::string>()(Y.tenantId + "###" + Y.clusterName + "###" + Y.quotaId);
    }
};

std::ostream &operator<<(std::ostream &os, IsCheckedKeyTuple &key) {
    os << "tenantId：" << key.tenantId << "\tclusterName：" << key.clusterName << "\tquotaId：" << key.quotaId;
    return os;
}

IsCheckedKeyTuple getIsCheckedKeyTuple() {
    IsCheckedKeyTuple key = {"123", "234", "342"};
    return key;
}

class stl_test {

};


#endif //TEST_CPP_STL_TEST_H
