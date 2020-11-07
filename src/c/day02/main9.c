//
// Created by QITMAC0000562 on 2020/11/7.
//
//指针
//指针是一个特殊的变量(指针变量)，保存一个变量的内存地址
#include <stdio.h>
#include <stdlib.h>

void test_0();

void test_1();

void test_2();

void swap(int, int);

void swap2(int *, int *);

int main() {
//    test_0();
//    test_1();
//    test_2();

    int a = 2, b = 3;
    printf("swap外 交换前，x = %d,y = %d\n", a, b);
    swap(a, b);
    printf("swap2外 交换前，x = %d,y = %d\n", a, b);
    swap2(&a, &b);
    printf("swap2外 交换后，x = %d,y = %d\n", a, b);
    return 0;
}

void test_0() {
    int i = 258;
    int *ptr_i = &i;//存储的是另一个变量的内存地址

    printf("&i = %p\n", &i);//i变量的引用，即地址
    printf("ptr_i值的地址 = %p\n", ptr_i);
    printf("ptr_i = %d\n", *ptr_i);
    printf("ptr_i自己的地址 = %p\n", &ptr_i);//指针它本身也是一个变量类型，它本身也会有一个地址

    printf("int*的大小 = %lu\n", sizeof(int *));
    printf("char*的大小 = %lu\n", sizeof(char *));
    void *ptr_void = ptr_i;
    printf("ptr_void = %p\n", ptr_void);
    printf("void*的大小 = %lu\n", sizeof(void *));//void*是一种特殊的指针，其它类型的指针都可以复制给void*
    printf("long long*的大小 = %lu\n", sizeof(long long *));//int* char* long long* void*区别在哪儿？
}

void test_1() {
    int i = 258;
    int j = 10000;
    int *ptr_i = &i;
    printf("&i = %p\n", &i);
    printf("&j = %p\n", &j);
    printf("ptr_i自己的地址 = %p\n", &ptr_i);

    printf("------------------\n");
    ptr_i = (int *) malloc(sizeof(int));//使用malloc函数在对上分配了一块内存给ptr_i
    printf("ptr_i自己的地址 = %p\n", &ptr_i);//指针变量本身的地址是不变的
    printf("ptr_i = %p\n", ptr_i);//指针所指向变量的内存地址，可以指向任何地址
    free(ptr_i);
    printf("ptr_i = %p\n", ptr_i);
    ptr_i = NULL;//如果free释放后，不置位NULL，则变成悬空指针，和野指针一样危险
    printf("ptr_i = %p\n", ptr_i);
}

//野指针，悬空指针
//参考：https://www.bilibili.com/read/cv4092590/
void test_2() {
    //悬空指针
    void *p1 = malloc(sizeof(int));
    free(p1);
    printf("p1 = %p\n", p1);
    p1 = NULL;//避免悬空指针
    printf("p1 = %p\n", p1);

    //野指针
    void *p2;//定义p2指针，但是没有指向任意地址
    //避免野指针，进行初始化
    void *p3 = NULL;
    void *data = malloc(sizeof(int));
}

//值传递，不影响最终结果
void swap(int x, int y) {
    printf("swap 交换前，x = %d,y = %d\n", x, y);
    int temp = x;
    x = y;
    y = temp;
    printf("swap 交换后，x = %d,y = %d\n", x, y);
}

//引用传递，影响最终结果
void swap2(int *x, int *y) {
    printf("swap2 交换前，x = %d,y = %d\n", *x, *y);
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("swap2 交换后，x = %d,y = %d\n", *x, *y);
}