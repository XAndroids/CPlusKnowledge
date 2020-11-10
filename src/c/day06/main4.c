//
// Created by QITMAC0000562 on 2020/11/10.
//
//文件读写，二进制
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define BLOCK_SIZE 1024*64

int main6666(int argc, char **argv) {
    //获取输入参数个数argc，参数数组argv
    if (argc < 3) return 0;

    //打开待copy二进制文件
    FILE *pr = fopen(argv[1], "rb");//rb二进制读
    if (pr == NULL) return 0;
    //打开copy目标二进制文件
    FILE *pw = fopen(argv[2], "wb");//wb二进制写
    if (pw == NULL) return 0;

    //获取复制文件的大小
    struct stat st = {0};
    stat(argv[1], &st);
    int size = st.st_size;

    //如果文件的大小大于读取块大小，则为每次最多读写BLOCK_SIZE大小
    if (size > BLOCK_SIZE) {
        size = BLOCK_SIZE;
    }

    //创建读写块buf
    char *buf = calloc(1, size);
    unsigned int index = 0;
    while (!feof(pr)) {//如果没有读写到文件末尾
        int res = fread(buf, 1, size, pr);//从pr文件读取buf块
        fwrite(buf, 1, res, pw);//将buf块写入pw文件
        index++;
    }

    free(buf);//释放buf读写块
    //关闭读写文件
    fclose(pw);
    pw = NULL;
    fclose(pr);
    pr = NULL;

    printf("index=%u\n", index);

    return 0;
}

int main777() {
    FILE *p = fopen("/Users/qitmac0000562/CLionProjects/CPlusKnowledge/src/c/day06/test/f.txt", "w");
    if (p) {
        while (1) {
            printf("please input： \n");
            char buf[100] = {0};
            scanf("%s", buf);
            if (strcmp(buf, "exit") == 0)
                break;
            fputs(buf, p);
            fflush(p);
        }
        fclose(p);
        p = NULL;
    }

    return 0;
}