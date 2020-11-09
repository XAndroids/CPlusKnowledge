//
// Created by QITMAC0000562 on 2020/11/9.
//

#include <stdio.h>
#include <string.h>

//结构体定义
struct Books {
    char title[10];
    char author[10];
    int book_id;
} book = {"C语言基础", "zero", 2};//结构体初始化

int main5663() {
    struct Books book1;
    //结构体赋值
    strcpy(book1.title, "c program");
    strcpy(book1.author, "av");
    book1.book_id = 2;

    //访问结构体
    printf("book1.title = %s\n", book1.title);
    printf("book1.author = %s\n", book1.author);
    printf("book1.book_id = %d\n", book1.book_id);

    //结构体指针p
    struct Books *p;
    p = &book1;
    printf("book1->title = %s\n", p->title);
    printf("book1->author = %s\n", p->author);
    printf("book1->book_id = %d\n", p->book_id);
    printf("(*p).title = %s\n", (*p).title);
    printf("(*p).author = %s\n", (*p).author);
    printf("(*p).book_id = %d\n", (*p).book_id);
    return 0;
}

//共用体
union Data {
    int i;
    float f;
};

int main53234() {
    union Data data;
    data.i = 10;
    data.f = 20.0f;

    printf("data.i = %d\n", data.i);
    printf("data.f = %f\n", data.f);
    return 0;
}