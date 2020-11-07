//
// Created by QITMAC0000562 on 2020/11/7.
//
//宏运算符
#include <stdio.h>

//如果一个宏太长了，一个单行容纳不下，则使用宏延续运算符（\）
//将宏的参数，转换成字符串常量是，使用字符串常量化运算符（#），#a访问宏传入的参数a
#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")

//宏定义内的标记粘贴运算符(##)，允许合并两个参数，token##n合并后为token34访问变量token34
#define tokenpaster(n) printf ("token" #n " = %d\n",token##n)

//预处理器defined运算符用在常量表达式，确定一个标识是否已经被使用#define定义过
#if !defined(MESSAGE)
#define MESSAGE "you wish!"
#endif

int main6() {
    message_for(Carole, Debra);

    int token34 = 40;
    tokenpaster(34);

    printf("Here is the message: %s\n", MESSAGE);
    return 0;
}
