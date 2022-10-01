# 常见问题

# Cmake 使用
- https://www.hahack.com/codes/cmake/

# cpp 协程
- https://zhuanlan.zhihu.com/p/218156339

# typedef Vs define
- 定义值建议使用 #define， 而且相当于替换，由预编译器执行
- 定义类型，时建议使用typedef, 由编译器执行

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

