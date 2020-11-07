//
// Created by QITMAC0000562 on 2020/11/5.
//
//头文件，条件导入头文件
#include <stdio.h>
//#define TEST_H
//导入自定义头文件，有条件导入#ifdef/#else/#endif
//#ifdef TEST_H
//    #include "test.h"
//#else
//    #include "test2.h"
//#endif

//通过宏定义头文件名称
#define TEST_H_NAME "test2.h"
#include TEST_H_NAME //头文件名称直接作为#include参数

int main5() {
    //调用test.h/test2.h中的常量ONE
    int a2 = ONE;
    printf("ONE的值：%d\n", a2);
    return 0;
}