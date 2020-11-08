//
// Created by QITMAC0000562 on 2020/11/8.
//
//函数的指针：
#include <stdio.h>

void test1(int n);

int call(int a, int b);

int test3(int a, int b, int (*callback)(int, int));

int main() {
    //函数指针
    void (*p)(int);//定义函数指针类型p
    p = &test1;//p指向test1函数
    p(100);//通过函数指针p调用test1函数

    printf("test3 = %d\n", test3(1, 2, call));
}

//函数指针调动
void test1(int n) {
    printf("test1 %d \n", n);
}

int call(int a, int b) {
    return a + b;
}

//函数指针回调
int test3(int a, int b, int (*callback)(int, int)) {
    return (callback(a, b));
}
