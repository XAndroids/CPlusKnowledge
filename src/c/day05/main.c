//
// Created by QITMAC0000562 on 2020/11/9.
//
//字符串
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main511() {
    //C语言的字符串，就是字符数组
    //\-折行符号，将字符串分行连接起来
    char *s = "3234234 \
               sdfsd";
    printf("%s \n", s);
    return 0;
}

int main522() {
    int a[10];//int数组
    char c[10];//字符数组，表示字符串，C语言没有字符串类型

    //字符串声明
    //C语言字符串用字符数组表示，三种补充表达方式
    char str[10] = {'h', 'e', 'l', 'l', 'o', '\0'};//特殊字符数组
    char str1[10] = "hello";//"hello"初始化，\0可以省略
    char *str2 = "hello";//字符指针
    printf("str = %s\n", str);
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    return 0;
}

int main533() {
    //字符串输入
    printf("请输入一个字符串\n");
    char str3[10];
//    scanf("%s", str3);//scanf默认空格结束，如果输入长度大于10，在有的平台可能崩溃
//    gets(str3);//gets默认空格是内容，回车默认结束
    fgets(str3, 10, stdin);//fgets指定输入的长度
    printf("str3 = %s\n", str3);
    return 0;
}

int main544() {
    //字符串赋值
    char str4[10] = "abc";
    //循环赋值
    for (int i = 0; i < 9; i++) {
        str4[i] = 'i';
    }
    printf("str4 = %s\n", str4);
    //标准函数strcpy
    char str5[10];
    strcpy(str5, "aaaa");
    printf("str5 = %s\n", str5);
    return 0;
}

int my_str_len(char *str);

int main555() {
    //获取字符数组或字符串长度
    char str5[10] = "Hello";
    printf("sizeof(str) = %lu\n", sizeof(str5));//sizeof输出字符数组的大小10
    printf("sizeof(str) = %lu\n", strlen(str5));//strlen输出字符数组中字符的长度
    printf("my_str_len(str) = %d\n", my_str_len(str5));
    return 0;
}

//自定义字符串长度
int my_str_len(char *str) {
    int i = 0;
    while (*(str + (++i)));
    return i;
}

void my_str_cat(char *s1, char *s2);

int main566() {
    //字符换拼接
//    char *s1 = "abc";
//    char *s2 = "efg";//s2在栈中分配，但是"efg"在常量去，无法修改！！！
    char s1[] = "abc";//s1和"abc"都在栈中，可以修改；这就是char*和chat[]声明的区别！！！
    char s2[] = "efg";
    my_str_cat(s1, s2);
//    strcat(s1, s2);
    printf("s1 = %s\n", s1);
    return 0;
}

//自定义字符拼接
void my_str_cat(char *s1, char *s2) {
    while (*s1) s1++;
    while (*s1++ = *s2++);
}

int main577() {
    //字符换指针初始化和数组初始化区别
    char s3[10];
    scanf("%s", s3);
    printf("s3 = %s\n", s3);
//    char *s4;//FIXME 实际测试是可以的
    char *s4 = (char *) calloc(10, sizeof(char));
    scanf("%s", s4);
    printf("s4 = %s\n", s4);
    return 0;
}
