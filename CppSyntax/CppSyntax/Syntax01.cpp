#include <iostream>
using namespace std;    //std是一个类(输入输出标准)

//单行注释
/*
多行注释*/

namespace first_name
{
    void fun() {
        cout << "第一个命名空间" << endl;
    }
}

int fun1(); //声明函数

extern int x, y;    //变量声明——（声明而非定义）
int z;  //全局变量声明

int main()
{
    int a = 5;  //a是常量
    int b,c;    //b,c是变量，变量定义——（声明并定义）
    int d;  //局部变量声明
    x = 5;  //变量初始化

    /*基本数据类型：
    * 整型：
    * 短整型short int
    * 整型int
    * 长整型long int
    *
    * 字符类型char
    * 宽字符类型wchar_t
    * 
    * 浮点型：
    * 单精度型float
    * 双精度型double
    * 长双精度型long double
    * 
    * 布尔型bool
    * 空类型void
    */

    //结构体类型：
    /*
    * 声明：
    * struct 结构体类型名
    * {
    *       成员列表;
    * };
    */
    struct People
    {
        int age;
        char name[20];
        float height;
    };
    struct People man, woman;   //定义结构体

    /*
    * 声明类型的同时定义变量：
    * struct 结构体类型名
    * {
    *       成员列表;
    * }变量名列表;
    */
    struct People
    {
        int age;
        char name[20];
        float height;
    }man, woman;

    /*
    * 直接定义结构体类型变量
    *struct
    * {
    *       成员列表;
    * }变量名列表;
    */
    struct
    {
        int age;
        char name[20];
        float height;
    }man, woman;

    //类类型：
    /*
    * class <类名>
    * {
    * public:
    * <成员变量或者成员函数的说明>
    * private:
    * <成员变量或者成员函数的说明>
    * protected:
    * <成员变量或者成员函数的说明>
    * }
    * 
    * <各个成员函数的实现>
    */
    std::cout << "Hello World!\n";  //标准输出流cout
    cin >> b;   //标准输入流cin
    first_name::fun();  //调用第一个命名空间
    fun1(); //调用函数
    return 0;
}

int fun1() {    //定义函数
    cout << "这是fun1函数" << endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
