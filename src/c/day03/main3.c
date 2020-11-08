//
// Created by QITMAC0000562 on 2020/11/8.
//
//数组指针和指针数据
//运算符优先级：* < [] < ()
//int (*ptr_array)[5] 数组的指针，代表一个5个元素的整形数组的起始指针
//int *ptr_array[5] 指针的数组，代表指针数组ptr_array数组，元素为5个指针类型数组；
#include <stdio.h>

int main311() {
    int array[] = {1, 2, 3, 4, 5};

    printf("array = %p \n", array);
    printf("&array = %p \n", &array);
    printf("------------------------\n");

    printf("array + 1 = %p \n", array + 1);//偏移1个元素字节，8字节
    printf("&array + 1 = %p \n", &array + 1);//偏移的array[5]类型5个元素字节，40字节

    int *ptr_array = array;//array为数组的起始指针
//    int (*ptr_array1)[4] = &array;//ptr_array1为(*)[4]类型，array为(*)[5]类型，不同类型
    int (*ptr_array2)[5] = &array;//&array为数组指针，步长为整个数组的长度

    //通过索引访问数组
    for (int i = 0; i < 5; i++) {
        printf("array[%d] = %d, *(array+%d) = %d\n", i, array[i], i, *(array + i));
        printf("&array[%d] = %p, array+%d = %p\n", i, &array[i], i, array + i);
    }

    //通过数组的指针遍历访问数组
    for (int *p = array; p < array + 5; p++) {
        printf("p = %p, *p= %d\n", p, *p);
    }
    return 0;
}

