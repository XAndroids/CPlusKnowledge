//
// Created by QITMAC0000562 on 2020/11/7.
//
//参数化宏
#include <stdio.h>

//参数化宏来模拟函数
//参数化宏之前，必须用#define指令定义
//参数列表是圆括号内，必须紧跟在宏名称后面
#define square(x)((x) * (x))
#define MAX(x, y)((x) > (y)?(x):(y))

int main7() {
    int result = square(2);
    printf("result = %d\n", result);

    printf("Max between 20 and 10 is %d\n", MAX(10, 20));
    return 0;
}