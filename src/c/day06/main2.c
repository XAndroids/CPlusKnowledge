//
// Created by QITMAC0000562 on 2020/11/9.
//
//文件拷贝
#include <stdio.h>

int main623() {
    //文件拷贝
    FILE *pr = fopen("/Users/qitmac0000562/CLionProjects/CPlusKnowledge/src/c/day06/test/a.txt", "r");
    if (pr == NULL) return 0;
    FILE *pw = fopen("/Users/qitmac0000562/CLionProjects/CPlusKnowledge/src/c/day06/test/b.txt", "w");
    if (pw) {
        while (1) {
            char c = fgetc(pr);
            if (c == EOF) {
                break;
            }
            fputc(c, pw);
        }
        fclose(pw);
        pw = NULL;
    }
    fclose(pr);
    pr = NULL;
    return 0;
}

int main655(int argc, char **argv) {
    printf("argc = %d\n", argc);
    //获取输入参数个数argc，参数数组argv
    if (argc < 3) return 0;
    FILE *pr = fopen(argv[1], "r");
    if (pr == NULL) return 0;
    FILE *pw = fopen(argv[2], "w");
    if (pw) {
        while (1) {
            char c = fgetc(pr);
            if (c == EOF) {
                break;
            }
            fputc(c, pw);
        }
        fclose(pw);
        pw = NULL;
    }
    fclose(pr);

    return 0;
}

int main666(int argc, char **argv) {
    printf("argc = %d\n", argc);
    //获取输入参数个数argc，参数数组argv
    if (argc < 3) return 0;
    printf("加密解码，第三个 0代表加密，1代表解码\n");
    FILE *pr = fopen(argv[1], "r");
    if (pr == NULL) return 0;
    FILE *pw = fopen(argv[2], "w");
    if (pw) {
        char key = argv[3][0];
        while (1) {
            char c = fgetc(pr);
            if (c == EOF) {
                break;
            }
            if (key == '0') {
                c++;
            } else {
                c--;
            }
            fputc(c, pw);
        }
        fclose(pw);
        pw = NULL;
    }
    fclose(pr);

    return 0;
}