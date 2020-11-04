//
// Created by QITMAC0000562 on 2020/10/11.
//

#include <iostream>

using namespace std;

void myfunc5(int a) {
    cout << "a: " << a << endl;
}

void myfunc5(char *a) {
    cout << "a: " << a << endl;
}

void myfunc5(int a, int b) {
    cout << "a: " << a << " b: " << b << endl;
}

void myfunc5(char *a, char *b) {
    cout << "a: " << a << " b: " << b << endl;
}

//函数的指针，基础的语法
//FIXME 既然有直接函数调用，为什么需要函数指针呢，函数又不存在值传递和引用传递？
typedef void (myTypeFunc5)(int a, int b);

//直接声明一个函数指针类型
typedef void (*myFunc5)(int a, int b);

//指针类型无法"重载"
//typedef void (*myFunc5)(char *a, char *b);

int main60() {
    cout << "函数指针与函数重载" << endl;
    myTypeFunc5 *func = nullptr;//声明函数指针类型myTypeFunc5变量func
    func = myfunc5;//将函数指针func指向myfunc5
    func(1, 2);//通过函数指针func调用myfunc5方法

    myFunc5 func1 = myfunc5;//直接定义函数指针类型myFunc5变量func1；
    func1(1, 2);
    //Too few arguments to function call, expected 2, have 1
//    func1(1);//函数指针，无法调用重载函数
    return 0;
}