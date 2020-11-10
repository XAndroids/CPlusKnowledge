//
// Created by QITMAC0000562 on 2020/11/10.
//
//文件块读写，格式化输入和输出
#include <stdio.h>
#include <stdlib.h>

int calc(int a, char b, int c);

int main652() {
    FILE *p = fopen("/Users/qitmac0000562/CLionProjects/CPlusKnowledge/src/c/day06/test/a.txt", "r");
    if (p) {
        char *array = calloc(100, sizeof(char));
        char *tmp = array;
        int index = 0;
        while (1) {
            char buf[100] = {0};
            if (feof(p)) break;
            fgets(buf, sizeof(buf), p);//读取每一行

            int a = 0;
            char b = 0;
            int c = 0;
            sscanf(buf, "%d%c%d=", &a, &b, &c);//格式化输入
            sprintf(tmp, "%d%c%d=%d\n", a, b, c, calc(a, b, c));//格式化输出
            array = realloc(array, 100 * (index + 2));
            tmp = array + 100 * (index + 1);
            index++;
        }
        fclose(p);


        p = fopen("/Users/qitmac0000562/CLionProjects/CPlusKnowledge/src/c/day06/test/d.txt", "w");
        tmp = array;
        if (p) {
            for (int i = 0; i < index; i++) {
                fputs(tmp, p);
                tmp += 100;
            }
        }

        free(tmp);
        free(array);

        fclose(p);
        p = NULL;

    }
    return 0;
}

int calc(int a, char b, int c) {
    switch (b) {
        case '+':
            return a + c;
        case '-':
            return a - c;
        case '*':
            return a * c;
        case '/':
            if (c != 0)
                return a / c;
    }
    return 0;
}
