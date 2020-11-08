//
// Created by QITMAC0000562 on 2020/11/8.
//
//指针
//空指针，类型转换
//指针运算
#include <stdio.h>

int main031() {
    //空指针
    int *ptr_i = NULL;//初始化指针赋值为NULL，free之后置为NULL
//    *ptr_i;//如果是空指针，则不允许*ptr_i操作；//FIXME 实际测试可以？？

    //通用指针
    int n;
    char c;
    short s;
    //指针类型，分别是int* char* short*
    int *ptr_n = &n;
    char *ptr_c = &c;
    short *prt_s = &s;

    printf("ptr_n = %p \n", ptr_n);
    void *ptr_void = ptr_n;//把一个整型的指针转换成通用指针，地址不会改变，但是类型信息会丢失
    printf("ptr_void = %p \n", ptr_void);
    int *ptr_n_1 = (int *) ptr_void;//转换回去
    //无法将int* 转换成double *，在某些系统可能报错
    double *ptr_double = (double *) ptr_n;//语法正确，存在语义发错误，编译器无法识别

    return 0;
}

int main032() {
    //指针的运算
    //1.对于变量，不同的类型，占用空间大小不一样
    //2.对于不同类型的指针变量，占用空间大小一样
    int i = 100;
    int *ptr_i = &i;
    printf("ptr_i = %p \n", ptr_i);
    printf("ptr_i + 1= %p \n", ptr_i + 1);//+1往后移动4个字节
    printf("ptr_i + 2= %p \n", ptr_i + 2);

    short s = 100;
    short *ptr_s = &s;
    printf("ptr_s = %p \n", ptr_s);
    printf("ptr_s + 1= %p \n", ptr_s + 1);//+1往后移动2个字节(步长)
    printf("ptr_s + 2= %p \n", ptr_s + 2);

    //指针栈4位，步进长度与其所指类型有关
    //只能进行加法和减法运算：+、-、++、--，并且类型必须一致
    return 0;
}
