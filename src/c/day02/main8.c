//
// Created by QITMAC0000562 on 2020/11/7.
//
//typedef关键字

#include <stdio.h>

//为类型char取一个新名称BYTE
typedef unsigned char BYTE;

int main8() {
    BYTE b = 'b';//BYTE就是char的别名
    printf("b1 = %c\n", b);

    return 0;
}
