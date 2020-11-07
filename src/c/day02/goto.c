//
// Created by QITMAC0000562 on 2020/11/4.
//
//goto 语句
#include <stdio.h>

//定义变量b2
int b2 = 20;

int maingoto() {
    int a = 10;
    //do循环执行
    LOOP:
    do {
        if (a == 15) {
            a = a + 1;
            goto LOOP;
        }
        printf("a的值：%d\n", a);
        a++;
    } while (a < 20);
    return 0;
}
