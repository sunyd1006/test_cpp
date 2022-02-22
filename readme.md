# 常见问题

include <>  VS ""
- 当你使用的实现比较主流的时候，要包含在和你的源文件相同路径下的文件请使用""形式包含
- 而当包含stl或你所使用的第三方库等的文件时请在配置了相关路径后使用<> 形式包含 ，这样可以减少编译时搜索文件的时间，也可能减少不必要的歧义（例如源文件的当前路径下有和你要包含的库的文件重名的文件时）。
- https://www.zhihu.com/question/25436617/answer/202624758

强制类型转换
- https://blog.csdn.net/ydar95/article/details/69822540
- const_cast：将指向const变量的指针，或引用 转换成 非const的指针或引用，也就是作用是，把原来不能改原值的指针，改成可以改原值的指针。
- reinterpret_cast: 任意两个指针间的转换
- dynamic_cast：和多态有关，Base* base = &Sub
- static_cast：前3中都是用这种实现的, 也是强制类型转换。。
```cpp
   const int c_val = 233;  //声明为常量类型
    int &use_val = const_cast<int&>(c_val); //使用去const 引用
    int *ptr_val = const_cast<int*>(&c_val);//使用去const 指针

    use_val = 666;  //     233 666 666

    std::cout << c_val << "\t" << use_val << "\t" << *ptr_val << std::endl;
    *ptr_val = 110; //   233 110 110
    std::cout << c_val << "\t" << use_val << "\t" << *ptr_val << std::endl;
    return 0;
}

// Sub->Base
cout << "Sub->Base" << endl;
Sub * sub = new Sub();
sub->print();

// Base* sub2base = sub; 
// 等价于 Base *base_ptr = static_cast<Base*>(&sub);
// 等价于
Base* sub2base = dynamic_cast<Base*>(sub); 

// 强制类型转换  reinterpret_cast
int *ptr = new int(233);
uint32_t ptr_addr = reinterpret_cast<uint32_t>(ptr);
cout << "ptr 的地址: " << hex << ptr << endl
<< "ptr_addr 的值(hex): " << hex << ptr_addr << endl;
```

static关键字
- 限制函数func()的作用范围仅在定义它的文件中
- static int func() { … }

内联函数
- 内联函数不被编译为单独一段可执行代码， 而是把函数的可执行代码直接插入到对该函数的每一次调用处;


Cmake 使用
- https://www.hahack.com/codes/cmake/


to_string 方法
```cpp
//C++11新特性
void test3()
{
    int a = 520;
    float b = 5.20;
    string str = "dong";
    string res = str + to_string(a);
    cout << res << endl;
    res = str + to_string(b);
    res.resize(8);
    cout << res << endl;
}
```

构造函数
- 不能是虚函数

析构函数
- 如果有虚函数，则必须是虚构造函数.
  - 基类指针ptr指向了派生类对象，因析构函数不是虚函数，所以编译连接时已经确定delete时调用基类的析构函数而不调用派生类的析构函数，故该派生类对象中的v所指空间没有被释放


namespace
- 头文件中一般// anonymous namespace用std::cout这种方式，而一般不在头文件，using namespace std; 这样包含此头文件的，都会using namespace std;
- 其他时候，一般只引入最小的需要用的函数, using DemoNameSpace::f;
- 匿名空间是全局的，我猜全局变量就在的匿名空间的中。
```cpp
// anonymous namespace
namespace {
        int ID = 21;
}
```

继承：
- 私有继承使基类的保护成员和公有成员成为派生类的私有成员
- 保护继承使基类的保护成员和公有成员成为派生类的保护成员
- 公有继承使基类的保护成员和公有成员仍然成为派生类的保护成员和公有成
- cpp默认是私有的，而一般我们使用共有的。

- 参考printInfo ,无论继承层次有多深，基类中声明的虚函数，在派生类中自动为虚函数，在派生类中声明该虚函数时可不用关键字virtual
- virtual void area()=0; 纯虚函数
  - 在子类中才需要实现，在基类中实现无意义。类似 Java 接口中的方法，或者抽象类的方法
  

抽象类(不一定全是虚函数) == Java抽象类  ==Cpp类如果全是纯虚函数的话，
- 包含纯虚函数的，称为抽象类，和Java抽象类一致。 
- 抽象类不能创建抽象类的对象，但可定义抽象类的指针，也可以声明抽象类的引用

const 注意：
// const char * a; //指向const对象的指针或者说指向常量的指针。
// char const * a; //同上
// char * const a; //指向类型对象的const指针。或者说常指针、const指针。
// const char * const a; //指向const对象的const指针。

形如 func() const{}的函数
- 2。const member function 不能修改对象的任意成员 
- 3。const member function 不能调用非 const member function

函数模板：
- 模板函数可以重载

模板类
- 编译不会产生代码，要在运行时动态的产生
- focus 一般 声明和定义放在一个文件夹中

宏的定义
- https://blog.csdn.net/shuzfan/article/details/52860664
```cpp
#define Square(x) x*x
float temp = Square(3+3);
//程序的本意可能是要计算6*6=36，但由于宏定义执行的是直接替换，本身并不做计算，因此实际的结果为 3+3*3+3=15
//想要避免这个问题，只需要修改如下：
#define Square(x) ((x)*(x))

/*x连接y，例如：int n = Conn(123,456); 结果就是n=123456;char* str = Conn("asdf", "adf"); /*结果就是 str = "asdfadf";*/
#define Conn(x,y) x##y

/*给x加上单引号，结果返回是一个const char。例如：char a = ToChar(1);结果就是a='1';做个越界试验char a = ToChar(123);结果就错了;但是如果你的参数超过四个字符，编译器就给给你报错了！error C2015: too many characters in constant   ：P */
#define ToChar(x) #@x

// x加双引号,例如：char* str = ToString(123132);就成了str="123132";
#define ToString(x) #x
```

typedef 别名
- https://www.cnblogs.com/charley_yang/archive/2010/12/15/1907384.html
```cpp
// typedef 不是简单的替换
typedef char * pstr;int mystrcmp(pstr, pstr);
这里将带我们到达第一个 typedef 陷阱。标准函数 strcmp()有两个'const char *'类型的参数。因此，它可能会误导人们象下面这样声明 mystrcmp()：

int mystrcmp(const pstr, const pstr); 
这是错误的，按照顺序，'const pstr'被解释为'char * const'（一个指向 char 的常量指针），而不是'const char *'（指向常量 char 的指针）。这个问题很容易解决：

typedef const char * cpstr; int mystrcmp(cpstr, cpstr); // 现在是正确的
记住：不管什么时候，只要为指针声明 typedef，那么都要在最终的 typedef 名称中加一个 const，以使得该指针本身是常量，而不是对象。
```

shared_ptr 用法
```cpp
shared_ptr<Complex> sp1(new Complex(1,2));      //Complex(1,2)由sp1托管，
shared_ptr<Complex> sp2(sp1);                               //Complex(1,2)同时交由sp2托管
```



cpp 协程
- https://zhuanlan.zhihu.com/p/218156339

枚举 enum 类型
```cpp
enum letter_set {'a','d','F','s','T'};                  //枚举常量不能是字符常量, 可以 enum letter_set {a, d, F, s, T};
enum year_set{2000,2001,2002,2003,2004,2005};           //枚举常量不能是整型常量
```


inline 注意：
- 声明了内联就会内联，声明内联只是一个建议而已 
- inline 只适合涵数体内代码简单的涵数使用，不能包含复杂的结构控制语句例如 while、switch



cpp 单例模式
```cpp
typedef std::tr1::shared_ptr<TenantMetaManager> TenantMetaManagerPtr;
static inline TenantMetaManagerPtr GetInstance()
    {
        static Mutex mutex;
        static TenantMetaManagerPtr tenantMMPtr;
        if(!tenantMMPtr.get())
        {
            ScopedLock lock(mutex);
            if(!tenantMMPtr.get())
            {
                tenantMMPtr.reset(new TenantMetaManager());
            }
        }
        return tenantMMPtr;
    }
```


make_pair(a, b);
make_pair(a,b,c);


// cpp 初始化顺序
```cpp
// C++ 初始化类成员时，是按照声明的顺序初始化的，而不是按照出现在初始化列表中的顺序。
// 但是编译器先初始化 m_x，然后是 m_
class CMyClass {
    CMyClass(int x, int y);
    int m_x;
    int m_y;
};

CMyClass::CMyClass(int x, int y) : m_y(y), m_x(m_y)
{
};
```


智能指针：
https://www.cnblogs.com/tenosdoit/p/3456704.html
- 智能指针可以像类的原始指针一样访问类的public成员，成员函数get()返回一个原始的指针，成员函数reset()重新绑定指向的对象，而原来的对象则会被释放。 
- 注意我们访问auto_ptr的成员函数时用的是“.”，访问指向对象的成员时用的是“->”。
- 我们也可用声明一个空智能指针auto_ptr<Test>ptest();
```cpp
auto_ptr<Test> ptest(new Test("123"));
ptest.get() //返回指针
```
  
```cpp
class Test{
public:
    Test(string s){
        str = s;
       cout<<"Test creat\n";
    }
    ~Test(){
        cout<<"Test delete:"<<str<<endl;
    }
    string& getStr(){
        return str;
    }
    void setStr(string s){
        str = s;
    }
    void print(){
        cout<<str<<endl;
    }
private:
    string str;
};
 
 
int main(){
    auto_ptr<Test> ptest(new Test("123"));
    ptest->setStr("hello ");
    ptest->print();
    ptest.get()->print();
    ptest->getStr() += "world !";
    (*ptest).print();
    ptest.reset(new Test("123"));
    ptest->print();
    return 0;
}
```


# typedef Vs define
- 定义值建议使用 #define， 而且相当于替换，由预编译器执行
- 定义类型时建议使用typedef， 有编译器执行

define 只是字面上的替换，由预处理器执行，#define A B 相当于打开编辑器的替换功能，把所有的 B 替换成 A。
而typedef 具有以下三个特点：

1. typedef 给出的符号名称仅限于对类型，而不是对值。定义值建议使用 #define
2. typedef 的解释由编译器，而不是预处理器执行, 并不是简单的文本替换。定义类型时建议使用typedef
3. 虽然范围有限，但是在其受限范围内 typedef 比 #define 灵活。
```cpp


typedef char * STRING;
STRING name, sign;   // char * name , * sign;  

#define STRING char *
STRING name, sign;  // char * name, sign;
```


# 调试信息 FUNCTION 
```cpp

// __FUNCTION__ ：函数名, 相当于字符串
// __TIME__ ：文件运行的时间
// __LINE__ ：所在行数
// __FILE__：文件的名字

printf("The file is %s.\n",__FILE__); 
printf( "The date is %s.\n", __DATE__ );
printf( "The time is %s.\n", __TIME__); 
printf( "This is line %d.\n", __LINE__ );
printf( "This function is %s.\n", __FUNCTION__ );

```

# 测试宏
- 宏定义顺序不同，对宏的调用没有影响


# const_inter
```cpp

	vector<int>::iterator it;
	for(it = v.begin(); it != v.end(); it++)
	{
		*it = it - v.begin(); // 迭代器的解引用就像指针的解引用一样
	}
 
	vector<int>::const_iterator cit; // 指向常量的迭代器， cit本身可变， 但*cit不能变
	for(cit = v.begin(); cit != v.end(); cit++)
	{
		cout << *cit << endl;
```

const成员变量如何复制：参考 const_int
1、类的const成员变量必须在构造函数的参数初始化列表中进行初始化。
2、构造函数内部，不能对const成员赋值，编译器直接报错。
3、构造函数列表初始化执行顺序与成员变量在类中声明相同，与初始化列表中语句书写先后无关。

关于成员变量，应用类型的初始化
- https://blog.csdn.net/lazyq7/article/details/48186291
总结：必须重写默认构造函数；形参必须为引用类型；必须在初始化列表里面赋值；
- 不能有默认构造函数，必须提供构造函数
凡是有引用类型的成员变量的类，不能有缺省构造函数。默认构造函数没有对引用成员提供默认的初始化机制，也因此造成引用未初始化的编译错误。
- 构造函数的形参必须为引用类型
暂时还不知道该怎么解释，牵涉到引用的机制。
- 初始化必须在成员初始化链表内完成
不能直接在构造函数里初始化，必须用到初始化列表，且形参也必须是引用类型。构造函数分为初始化和计算两个阶段，前者对应成员初始化链表，后者对应构造函数函数体。引用必须在初始化阶段，也即在成员初始化链表中完成，否则编译时会报错（引用未初始化）。

# 引用和指针的区别
- https://www.cnblogs.com/dolphin0520/archive/2011/04/03/2004869.html
- 指针是地址
- 引用存的也是地址，而引用是一个别名，它在逻辑上不是独立的，它的存在具有依附性，所以引用必须在一开始就被初始化，而且其引用的对象在其整个生命周期中是不能被改变的（自始至终只能依附于同一个变量） 
- 如果想通过指针参数传递来改变主调函数中的相关变量，那就得使用指向指针的指针，或者指针引用
指针传递参数本质上是值传递的方式，它所传递的是一个地址值。值传递过程中，被调函数的形式参数作为被调函数的局部变量处理，即在栈中开辟了内存空间以存放由主调函数放进来的实参的值，从而成为了实参的一个副本。值传递的特点是被调函数对形式参数的任何操作都是作为局部变量进行，不会影响主调函数的实参变量的值。
而在引用传递过程中，被调函数的形式参数虽然也作为局部变量在栈中开辟了内存空间，但是这时存放的是由主调函数放进来的实参变量的地址。被调函数对形参的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量。正因为如此，被调函数对形参做的任何操作都影响了主调函数中的实参变量。

```cpp
  int a = 5;
  int& b = a;
  int c = 6;
  b = c;
  std::cout<< &a << std::endl;
  std::cout<< &b << std::endl;
  std::cout<< b << std::endl;   // b 和 a 一个地址，对B操作，等价于对a操作
  std::cout<< c << std::endl;
  std::cout<< &c << std::endl;
  ```

```cpp
swap(&a, &b)
/**
 *  
 */
void swap(int *a,int *b)
{
　　int temp=*a;          // realA ，realB会改变
　　*a=*b;                // *a ,指的是realA
　　*b=temp;
}

void swap(int *a,int *b)
{
　　a=null;             // realA不会改变，因为改的指针
}
```


```cpp
// https://www.cnblogs.com/pengyingh/articles/5369061.html

/* 这是一个未初始化的全局变量的定义 */
int x_global_uninit;
 
/* 这是一个初始化的全局变量的定义 */
int x_global_init = 1;
 
/* 这是一个未初始化的全局变量的定义，尽管该变量只能在当前 C文件中访问 */
static int y_global_uninit;
 
/* 这是一个初始化的全局变量的定义，尽管该变量只能在当前 C文件中访问 */
static int y_global_init = 2;
 
/* 这是一个存在于程序别处的某个全局变量的声明 */
extern int z_global;
 
/* 这是一个存在于程序别处的某个函数的声明（如果你愿意，你可以在语句前加上 "extern"关键字，但没有这个必要） */
int fn_a( int x, int y);
 
/* 这是一个函数的定义，但由于这个函数前加了 static限定，因此它只能在当前 C文件内使用 */
static int fn_b(int x)
{
    return x +1;
}
 
/* 这是一个函数的定义，函数参数可以认为是局部变量 */
int fn_c( int x_local)
{
    
/* 这是一个未初始化的局部变量的定义 */
    int y_local_uninit ;
    
/* 这是一个初始化的局部变量的定义 */
    int y_local_init = 3 ;
 
    
/* 以下代码通过局部变量、全局变量和函数的名字来使用它们 */
    x_global_uninit = fn_a (x_local, x_global_init);
    y_local_uninit = fn_a (x_local, y_local_init);
    y_local_uninit += fn_b (z_global);
    return (x_global_uninit + y_local_uninit);
}
```

set和map自定义去重，和排序原则
- https://blog.csdn.net/wzzfeitian/article/details/70171512
```cpp
struct IsCheckedKeyTuple {
    string tenantId;
    string clusterName;
    string quotaId;
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
    if (b.tenantId < a.tenantId) return true;
    if (b.tenantId == a.tenantId && b.clusterName < a.clusterName) return true;
    if (b.tenantId == a.tenantId && b.clusterName == a.clusterName && b.quotaId < a.quotaId) return true;
    return false;
}
```