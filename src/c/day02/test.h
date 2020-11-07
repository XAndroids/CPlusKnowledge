//
// Created by QITMAC0000562 on 2020/11/6.
//
//一次性导入头文件

//一个头文件被引用两次，编译器会处理两次头文件内容，将产生错误
//为了防止这种情况，标准做法是把文件整个内容放在条件编译语句中
#ifndef CPLUSKNOWLEDGE_TEST_H //包装器#ifndef，当再次引入头文件时，条件为假，因为CPLUSKNOWLEDGE_TEST_H已定义，预处理会跳过文件整个内容
#define CPLUSKNOWLEDGE_TEST_H

//定义常量
#define ONE 1;
const int C_ONE = 1;

#endif //CPLUSKNOWLEDGE_TEST_H
