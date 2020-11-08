//
// Created by QITMAC0000562 on 2020/11/8.
//
//指针的指针：函数内部值可以返回给外部
#include <stdio.h>

int find(const char *src, char ch, char **ret);

void test(int array[]);

int main222() {
    int i = 100;
    int *pInt = &i;//指针
    int **ppInt = &pInt;//指针的指针

    printf("i = %d \n", i);
    printf("pInt = %d \n", *pInt);//访问指针的值
    printf("ppInt = %d \n", **ppInt);//访问指针的指针的值

    char str[] = "huan ying lai xiangxue";//待查找字符串
    char *ret = NULL;//查找结果，char *类型，作为find函数的参数传递，需要通过它返回则需要char**类型
    //总结：
    //指针参数，函数内部可以改变外部的值；
    //指针的指针参数，函数内部值可以返回给外部；
    if (find(str, 'y', &ret)) {
        printf("ret = %s \n", ret);
    }

    int array[5] = {1, 2, 3, 4, 5};
    test(array);//数组名作为指针，参数传递
    printf("array[0] = %d\n", array[0]);
    return 0;
}

//指针的指针作为参数传递
int find(const char *src, char ch, char **ret) {
    char *index = (char *) src;
    while (*index) {
        if (*index == ch) {
            *ret = index;
            return 1;
        }
        index++;
    }
    return 0;
}

//数组名称作为参数传递，等同于void test(int *array)
void test(int array[]) {
    array[0] = 100;
}