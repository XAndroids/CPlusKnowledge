//
// Created by QITMAC0000562 on 2020/10/11.
//

#include <iostream>

using namespace std;

void printA();//函数声明

//C语言的宏定义
#define MYFUNC(a, b) ((a)<(b))?(a):(b)

//C++内联函数
inline void printB() {
    int a = 10;
    cout << "a:" << a << endl;
//    for (int i = 0; i < 10000; i++) {//如果内联函数中，存在for/if/else/switch语句过多的时候不会内联
//
//    }
}

//1.内联函数，声明必须实现，没有办法分开。如果分开C++编译器会取消内联
//2.内联函数必须放在调用它的方法前面
//3.C++编译器不一定会允许内联，只是请求它内联，是否内联由编译器自己判断。
//限制：
//1.不能存在任何形式的循环语句；
//2.不能存在过多的条件判断语句；
//3.函数体不能过于庞大；
//4.不能被函数进行取地址操作；
//5.函数内联声明必须在调用之前；
//当我们的函数本身代码执行的代价大于函数调用压栈开销的时候，内联没有任何意义
int main30() {
    cout << "函数" << endl;
    printA();//函数调用

    MYFUNC(1, 2);//调用宏

    printB();//调用内联函数
    return 0;
}

void printA() {//方法实现
    cout << "printA" << endl;
}

//内联函数，声明和实现分开，C++编译器会取消内联
//inline void printB(){
//
//}