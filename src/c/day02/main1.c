//
// Created by QITMAC0000562 on 2020/11/7.
//
//声明变量的2中方式
#include <stdio.h>

int b1 = 10;//声明，并定义变量b1，建立内存
extern int b2;//声明，不定义变量b2，可以访问got.c中定义的b2；

int main1() {
    printf("b1 = %d\n", b1);
    printf("b2 = %d\n", b2);//访问goto.c中定义的b2 = 20
    return 0;
}