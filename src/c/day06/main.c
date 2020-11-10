//
// Created by QITMAC0000562 on 2020/11/9.
//
//文件读写
#include <stdio.h>
#include <string.h>

int main611() {
    //文件打开
//    FILE *p = fopen("test/a.txt", "w");//FIXME 为什么性对路径就打开失败呢，权限也不行？？？
    FILE *p = fopen("/Users/qitmac0000562/CLionProjects/CPlusKnowledge/src/c/day06/test/a.txt", "w");//打开文件

    if (p) {
        printf("success\n");
        fclose(p);
        p = NULL;
    } else {
        printf("fail\n");
    }
    return 0;
}

int main622() {
    //文件读取
    FILE *p = fopen("/Users/qitmac0000562/CLionProjects/CPlusKnowledge/src/c/day06/test/a.txt", "r");
    if (p) {
        while (1) {
            char c = fgetc(p);//文件读取
            if (c == EOF) {
                break;
            }
            printf("%c\n", c);
        }
    }
    return 0;
}

int main633() {
    //文件写入
    FILE *p = fopen("/Users/qitmac0000562/CLionProjects/CPlusKnowledge/src/c/day06/test/a.txt", "w");
    if (p) {
        while (1) {
            printf("please intput:\n");
            char buf[100] = {0};
            scanf("%s", buf);
            if (strcmp(buf, "exit") == 0) {
                break;
            }
            fputs(buf, p);//文件写入
            fflush(p);//每次写入完毕后，写入文件！
        }
        fclose(p);
        p = NULL;
    }
    return 0;
}

