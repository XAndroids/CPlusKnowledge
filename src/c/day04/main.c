//
// Created by QITMAC0000562 on 2020/11/8.
//
//指针和二维数组
#include <stdio.h>

int main411() {
    int array[5] = {0};//一维数组
    int arr[4][3] = {{1,  2,  3},
                     {4,  5,  6},
                     {7,  8,  9},
                     {10, 11, 12}};//二维数组

    int (*ptr_a)[3] = arr;//ptr_a是数组的指针，指向arr数组的{1，2，3}
    //遍历数组
    //下标，a[i][j]或者ptr_a[i][j]
    //指针偏移，*(*(ptr_a+i)+j)
    //参考：https://blog.csdn.net/AXuan_K/article/details/51943309


    //color为指针的数组，保存了指向3个字符换的指针
    char *color[] = {"red", "green", "blue"};
    for (int i = 0; i < 3; i++) {
        puts(color[i]);
        printf("color[%d] = %p \n", i, color[i]);
        color[i] = "color";
        printf("color[%d] = %p \n", i, color[i]);
    }

    //pcol为数组的指针，保存了col数组的起始地址
    char col[][6] = {"red", "green", "blue"};
    char(*pcol)[6] = col;
    for (int i = 0; i < 3; i++) {
        puts(pcol[i]);
    }
    return 0;
}