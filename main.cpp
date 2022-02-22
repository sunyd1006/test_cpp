#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <set>

// 本地编译目录 + 系统类库，当然费时一点
#include "stl/stl_test.h"
#include "basic/Complex.h"
#include "basic/CanUseComplex.h"
#include "basic/Exception.h"
#include "oop/SubClass.h"
#include "oop/Base.h"
#include "template/TemplateDemo.h"

using namespace std;
using namespace basic;

#define COMMON_LOG_INFO "CHECKINFO"
#define loginfo()   \
    cout << COMMON_LOG_INFO << endl;
// #define LOG_ERROR(desc, ) \
//     cout << desc << endl; \


#define B_WITH_CALL_A(value) \
    CALL_A(value)

#define CALL_A(value) \
    cout << "call A" << value;

enum Flag{
    aaa = 0
};
void print(Flag & flag){
    cout<< flag << endl;
};

// extern int basic::nConflict;
string external_byte_array[] = {"error", "File", "Edit", "Search", "Help"};

int static_factor(int n);

void testPointerRet(string* msg){
    string& msgInf= *msg;
    // string msgInf= *msg;
    msgInf="haha";
}

int main() {
    string mulu =
            " 1 basic: "
            " 2 oop: 测试导入，测试 重载运算法、有元函数、虚函数等等 "
            " 3 polymorphism："
            " - 静态多态：主要指的是函数重载overload, 不同的参数或不同的返回结果。因为编译的时间就确定了，叫编译时多态"
            " - 动态多态：虚成员函数实现，是在编译过程中动态确定的，称为运行时多态。"
            " 4 template"
            " 5 shared_ptr"
            " 6 stl"
            " 7 testFunctionParamRet";
    string whichTestShouldBeTest = "stl";

    while (true) {
        if (whichTestShouldBeTest == "stl") {
            cout << "unorderset 不支持，vector, tuple, pair等等，需要自己实现Hash函数，实现==函数" << endl;
            IsCheckedKeyTuple tp = {"a", "b", "c"};
            IsCheckedKeyTuple tp2 = {"ab", "", "c"};
            IsCheckedKeyTuple tp3 = {"ab", "", "c"};

            unordered_set<IsCheckedKeyTuple, IsCheckedKeyTupleHash, IsCheckedKeyTupleComp> myset{tp, tp2, tp3};
            cout << "myset.size(): " << myset.size() << endl;
            for (const auto &item : myset) {
                cout << item.tenantId << item.clusterName << item.quotaId << endl;
            }
            unordered_map<IsCheckedKeyTuple, bool, IsCheckedKeyTupleHash, IsCheckedKeyTupleComp> myHash;
            myHash[tp] = true;
            cout << myHash[tp] << " end" << endl;
            if (myHash[tp] == true) {
                cout << "不行" << endl;
            }
            for (auto it : myHash) {
                // std::cout << "key = " << it.first << " value = " << it.second << std::endl;
            }
            cout << getIsCheckedKeyTuple().tenantId << endl;

            // 测试 set 如何去重
            // set<IsCheckedKeyTuple, IsCheckedKeyTupleComp> setObj{tp, tp2, tp3};
            set<IsCheckedKeyTuple> setObj;
            // {tp, tp2, tp3
            setObj.insert(tp);
            setObj.insert(tp2);
            setObj.insert(tp3);
            cout << setObj.find(tp)->tenantId << endl;
            cout << "setObj.size: " << setObj.size() << " " << endl;

            // 4. 使用 boost_hash支持：integers, floats, pointers, strings, arrays, pairs 以及其它 STL 里的东西
            // 测试结果，失败, mac 本地没有 boost_hash
            typedef tuple<string, string, string> stringTp;
            set<tuple<string, string, string>> realTp;
            set<pair<string, string>> newPair;
            realTp.insert(stringTp("ab", "", "c"));
            realTp.insert(stringTp("a", "b", "c"));
            cout << "realTp.size(): " << realTp.size() << endl;

            // todo: nordered_map 是没有 hash的，要自己实现；set/map是有是
            // unordered_map<stringTp, IsCheckedKeyTuple> tupleKeyMap; // error
            // map<stringTp , IsCheckedKeyTuple> tupleKeyMap;
            set<IsCheckedKeyTuple> stringIpSet;
            stringIpSet.insert(tp);
            stringIpSet.insert(tp2);
            stringIpSet.insert(tp3);
            cout << "stringIpSet: " << stringIpSet.size() << endl;

            // 可变参数  todo
            // make_pair("key", "name")
            printPair(make_pair("key", "name"), make_pair("key", "name"));


        }
        if (whichTestShouldBeTest == "testFunctionParamRet"){
            Flag flag = Flag::aaa;
            print(flag);

            // 测试 用函数形参为指针返回值
            string msg;
            testPointerRet(&msg);
            cout << "testPointerRet: " << msg << endl;
        }
        if (whichTestShouldBeTest == "new") {
            // map 常见使用
            unordered_map<std::string, std::vector<std::string>> map;
            std::vector<std::string> vec1{"sun", "yin", "dong"};
            std::vector<std::string> vec2{"hu", "wen", "rui"};
            map["s"] = vec1;
            map["h"] = vec2;
            for (const string &string_v : map["s"]) {
                cout << string_v << " ";
            }
            cout << endl;
            for (const auto &item: map) {
                cout << item.first << ": ";
                for (const auto &name : item.second) {
                    cout << name << " ";
                }
                cout << endl;
            }

            // 字符串连接
            string hello = "hello";   // 但const* 相加是不行的 "hello" + "world"
            hello += "world";
            cout << "字符串连接: " << hello << endl;
            // 9      //实现一个字典
            // 10      typedef map<string, string>::iterator MyIterator;
            // 11      map<string, string> direct;
            // 12      direct.insert( pair<string, string>("insert", "插入" ));
            // 13      direct.insert( pair<string, string>("sort", "排序" ));
            // 14      direct.insert( make_pair("apple", "苹果" ));
            // 15      direct.insert( make_pair("insert", "插入" ));
            // 16      direct.insert( make_pair("insert", "插入" ));
            // 17      direct.insert( make_pair("sort", "排序" ));
            cout << " __FILE__ " << endl;
            printf("The file is %s.\n", __FILE__);
            printf("This is line %d.\n", __LINE__);
            printf("This function is %s.\n", __FUNCTION__);
            printf("The date is %s.\n", __DATE__);
            printf("The time is %s.\n", __TIME__);
            cout << "测试宏逆序声明是否可以调用成功：" << endl;
            B_WITH_CALL_A(1);  // 宏定义顺序不同，对宏的调用没有影响
            // 测试 define
            // loginfo()  // 可以成功
        }
        if (whichTestShouldBeTest == "basic") {
            // 使用 static 关键字
            for (int i = 1; i <= 8; i++)
                cout << static_factor(i) << " ";
            cout << endl;

            // 测试 char* 和 string 之间的连接
            const char* kIsCheckedSetDelimiter = "#*#*#";
            string aaa = "aaa";
            string abc = aaa + kIsCheckedSetDelimiter + "ccc";
            cout << abc << endl;

            // 外部变量
            // cout << FirstClass_exter_value << endl;

            // 函数返回指针：返回的指针必须是有意义的，不能是一个指向函数内的局部变量或参数变量的指针或处于"悬空"状态的指针
            int int_array[] = {1, 2, 3};
            int *pt_array = int_array;
            cout << "数组长度：" << sizeof(int_array) / sizeof(int);
            cout << "int_array 是const, pt_array不是const,可以++;" << endl;
            cout << "&int_array[0] == pt_array: " << (&int_array[0] == pt_array) << endl;
            cout << *(pt_array++) << endl;
            cout << *(pt_array++) << endl;

            // 数组长度
            cout << "数组占用字节数，sizeof(int_array): " << sizeof(int_array) << endl;
            cout << "数组length: : " << sizeof(int_array) / sizeof(int) << endl;

            // 指针长度 size
            int *pt = new int;
            double *ptdouble = new double;                            // 4
            int sizeofptint = sizeof pt;                             // 8
            int sizeofptdouble = sizeof ptdouble;                     // 8

            // 数组静态绑定长度，和动态绑定长度
            // int array[3];
            // int size; cin >> size;
            // int * array_pt = new int[size];

            // 动态内存分配：
            int *dynamic_array = new int[5];
            cout << "sizeof  ptr of dynamic_array: " << sizeof dynamic_array << endl;
            delete[]dynamic_array;

            // 引用
            int nSomeVar = 5;
            int &ref = nSomeVar;
            cout << "nSomeVar: " << nSomeVar << " ref: " << ref << endl;

            // 枚举
            enum color_set {
                RED, BLUE, WHITE, BLACK
            } color, red;
            color = RED;
            red = RED;
            cout << color << endl;
            cout << "color == red: " << (color == red) << endl;
        }
        if (whichTestShouldBeTest == "oop") {
            // // extern 外部变量，定义在 Complex, CanUseComplex
            // // cout << nConflict << endl;
            // // 导入
            Complex *one = new Complex(1, 1);
            // 测试普通方法
            one->to_string();
            // 测试 << 方法重写
            cout << "one: " << *one << endl;

            // 测试重载运算符
            Complex *two = new Complex(2, 2);
            Complex res = *one + *two;
            cout << "*one + *two: " << res.to_string() << endl;
            Complex floadAddResult = *one + 2.5f;
            cout << "floadAddResult: " << floadAddResult << endl;

            // 测试有元类CanUseComplex 类，可以访问Complex的方法
            CanUseComplex *canUseFristClass = new CanUseComplex();
            canUseFristClass->sayClassInfo();

            // 测试重载调用顺序  C++ 初始化类成员时，是按照声明的顺序初始化的，而不是按照出现在初始化列表中的顺序。
        }
        if (whichTestShouldBeTest == "polymorphism") {
            cout << "测试多态性" << endl;
            oop::Base *ptr;

            ptr = new oop::Base;
            ptr->printInfo();
            cout << endl;
            delete ptr;

            cout << "测试虚析构函数" << endl;
            ptr = new oop::SubClass;
            ptr->printInfo();
            cout << endl;
            delete ptr;

            // 测试
            ptr = dynamic_cast<oop::Base *>(new oop::SubClass);
            ptr = new oop::SubClass;
            ptr->printInfo();
            cout << endl;
            delete ptr;
        }
        if (whichTestShouldBeTest == "template") {
            cout << "测试函数模板 template: ";
            cout << "template_func::TabsTemplate(1): " << templateDemo::MaxTemplate(1, 2) << endl;
        }
        if (whichTestShouldBeTest == "shared_ptr") {
            shared_ptr<Complex> sp1(new Complex(1, 2));      //Complex(1,2)由sp1托管，
            shared_ptr<Complex> sp2(sp1);                               //Complex(1,2)同时交由sp2托管
            shared_ptr<Complex> sp3;
            sp3 = sp2;                                                  //Complex(1,2)同时交由sp3托管
            cout << sp1->getImage() << "," << sp2->getImage() << "," << sp3->getImage() << endl;
            Complex *p = sp3.get();                                     // get返回托管的指针，p 指向 Complex(1,2)
            cout << p->getImage() << endl;  //输出 2
            sp1.reset(new Complex(1, 3));    // reset导致托管新的指针, 此时sp1托管Complex(1,3)
            sp2.reset(new Complex(1, 4));    // sp2托管Complex(1,4)
            cout << sp1->getImage() << endl;                //输出 3
            sp3.reset(new Complex(1, 5));    // sp3托管Complex(1,5),Complex(1,2)无人托管，被delete
            cout << "end" << endl;
        }
        if (whichTestShouldBeTest == "test") {
            try {
                // 测试 assert
                int *a = new int;
                assert(a); // int *a;  // Assertion failed: (a), function testTest
                const char *charInt = "456";
                int intInt = atoi(charInt);
                cout << intInt << endl;

                string str = "123";
                assert(str.compare("123") == 0);

                bool isTrue = true;
                assert(isTrue);

                // to_string
                cout << "std::to_string(123): " << std::to_string(123) << endl;

                oop::Base *ptr;
                // assert(ptr);        //Assertion failed: (ptr), function testTest, file /Users/sunyindong/CLionProjects/test_cpp/main.cpp, line 198.
                ptr = new oop::Base;
                // assert(ptr);

                throw Exception("oops");    // 抛出自定义异常
            } catch (const Exception &ex) {
                printf("reason: %s\n", ex.what());
                printf("stack trace: %s\n", ex.stackTrace());

            } catch (...) {
                cout << " assert !" << endl;
            }
        }
        if (whichTestShouldBeTest == "mock") {
            Complex a;
            cout << &a << endl;
            cout << ((&a) != nullptr) << endl;
            cout << "haha" << endl;
            // ::testing::InitGoogleMock(&argc, argv);
            // string value = "Hello World!";
            // MockFoo mockFoo;
            // EXPECT_CALL(mockFoo, getArbitraryString()).Times(1).
            //         WillOnce(Return(value));
            // string returnValue = mockFoo.getArbitraryString();
            // cout << "Returned Value: " << returnValue << endl;
            //
            // return EXIT_SUCCESS;
        }
        cin >> whichTestShouldBeTest;
    }
}

int static_factor(int n) {
    static int result = 1;
    result *= n;
    return result;
}
