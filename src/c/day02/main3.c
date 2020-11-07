//
// Created by QITMAC0000562 on 2020/11/7.
//
//全局变量、全局静态变量、局部变量和局部静态变量区别
#include <stdio.h>

int a1 = 1;//全局变量，全局作用域
static int a2 = 2;//静态全局变量，如果多个文件定义同名静态全局变量，只有当前文件可用

void print();

int main3(){
    int a3 = 3;//默认auto，局部变量默认存储类型，只能在函数内局部访问，函数执行期间存在
    static int a4 = 4;//静态局部变量，只初始化一次，直到程序结束，只对自己函数体可见
    register int a5 = 5;//寄存器变量(register)，存储寄存器，效率高

    printf("a1 = %d\n", a1);
    printf("a2 = %d\n", a2);
    printf("a3 = %d\n", a3);
    printf("a4 = %d\n", a4);
    printf("a5 = %d\n", a5);

    print();
    return 0;
}

void print(){
    printf("a1 = %d\n", a1);//a1全局变量，全局作用域，可访问
    printf("a2 = %d\n", a2);//a2全局变量，全局作用域，可访问
//    printf("a3 = %d\n", a3);//a3是局部变量，只在main函数中可访问
//    printf("a4 = %d\n", a4);//a4是局部静态变量，在整个程序声明周期都存在，但是也只能在main函数中访问
}

