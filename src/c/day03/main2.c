//
// Created by QITMAC0000562 on 2020/11/8.
//
//数组与一维数组
//数组名就是数组的起始地址，也是第一个元素的地址，数组名就是一个常量指针
#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int *ptr_array = array;
    //数组名称、第一个元素是数组的第一个内存地址
    printf("ptr_array = %p\n", ptr_array);
    printf("&array = %p\n", &array);
    printf("&array[0] = %p\n", &array[0]);
    printf("------------------------\n");

    //指针运算符和数组的索引类似功能
    //array+3,&array[3],ptr_array+3,&ptr_array[3]代表同一个地址
    printf("array + 3 = %p\n", array + 3);
    printf("&array[3] = %p\n", &array[3]);
    printf("ptr_array + 3 = %p\n", ptr_array + 3);
    printf("&ptr_array[3] = %p\n", &ptr_array[3]);
    printf("------------------------\n");

    //*(array+3),*(ptr_array+3),*&array[3],*&ptr_array[3]都是array[3]的值
    printf("array[3] = %d\n", *(array + 3));
    printf("*(ptr_array + 3) = %d\n", *(ptr_array + 3));
    printf("*&array[3] = %d\n", *&array[3]);
    printf("*&ptr_array[3] = %d\n", *&ptr_array[3]);
    return 0;
}
