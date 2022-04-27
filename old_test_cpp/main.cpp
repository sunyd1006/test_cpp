#include <cstdlib>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// 本地编译目录 + 系统类库，当然费时一点
using namespace std;

#define COMMON_LOG_INFO "CHECKINFO"
#define loginfo() cout << COMMON_LOG_INFO << endl;
// #define LOG_ERROR(desc, ) \
//     cout << desc << endl; \


#define B_WITH_CALL_A(value) CALL_A(value)

#define CALL_A(value) cout << "call A" << value;

enum Flag { aaa = 0 };
void print(Flag &flag) { cout << flag << endl; };

// extern int basic::nConflict;
string external_byte_array[] = {"error", "File", "Edit", "Search", "Help"};

int static_factor(int n);

void testPointerRet(string *msg) {
    string &msgInf = *msg;
    // string msgInf= *msg;
    msgInf = "haha";
}

int main() {
    string mulu =
        " 1 basic: "
        " word_transformation_bad.txt oop: 测试导入，测试 重载运算法、有元函数、虚函数等等 "
        " 3 polymorphism："
        " - 静态多态：主要指的是函数重载overload, "
        "不同的参数或不同的返回结果。因为编译的时间就确定了，叫编译时多态"
        " - 动态多态：虚成员函数实现，是在编译过程中动态确定的，称为运行时多态。"
        " 4 template"
        " 5 shared_ptr"
        " 6 stl"
        " 7 testFunctionParamRet";
    string whichTestShouldBeTest = "stl";

    while (true) {
        if (whichTestShouldBeTest == "eof") break;
        if (whichTestShouldBeTest == "stl") {
        }
        if (whichTestShouldBeTest == "testFunctionParamRet") {
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
            for (const auto &item : map) {
                cout << item.first << ": ";
                for (const auto &name : item.second) {
                    cout << name << " ";
                }
                cout << endl;
            }

            // 字符串连接
            string hello = "hello";  // 但const* 相加是不行的 "hello" + "world"
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
            for (int i = 1; i <= 8; i++) cout << static_factor(i) << " ";
            cout << endl;

            // 测试 char* 和 string 之间的连接
            const char *kIsCheckedSetDelimiter = "#*#*#";
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
            double *ptdouble = new double;         // 4
            int sizeofptint = sizeof pt;           // 8
            int sizeofptdouble = sizeof ptdouble;  // 8

            // 数组静态绑定长度，和动态绑定长度
            // int array[3];
            // int size; cin >> size;
            // int * array_pt = new int[size];

            // 动态内存分配：
            int *dynamic_array = new int[5];
            cout << "sizeof  ptr of dynamic_array: " << sizeof dynamic_array << endl;
            delete[] dynamic_array;

            // 引用
            int nSomeVar = 5;
            int &ref = nSomeVar;
            cout << "nSomeVar: " << nSomeVar << " ref: " << ref << endl;

            // 枚举
            enum color_set { RED, BLUE, WHITE, BLACK } color, red;
            color = RED;
            red = RED;
            cout << color << endl;
            cout << "color == red: " << (color == red) << endl;
        }
        if (whichTestShouldBeTest == "oop") {
        }
        if (whichTestShouldBeTest == "polymorphism") {
        }
        if (whichTestShouldBeTest == "template") {
        }
        if (whichTestShouldBeTest == "shared_ptr") {
        }
        if (whichTestShouldBeTest == "test") {
        }
        if (whichTestShouldBeTest == "mock") {
        }
        cin >> whichTestShouldBeTest;
    }
}

int static_factor(int n) {
    static int result = 1;
    result *= n;
    return result;
}
