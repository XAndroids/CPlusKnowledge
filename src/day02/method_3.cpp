//
// Created by QITMAC0000562 on 2020/10/11.
//

#include <iostream>

using namespace std;

void test(int a) {
    cout << "a: " << a << endl;
}

//参数类型不同重载
void test(char *a) {
    cout << "a: " << a << endl;
}

//参数个数不同重载
void test(int a, int b) {
    cout << "a: " << a << " b: " << b << endl;
}

//方法仅仅是返回值不同，不能重载
//Functions that differ only in their return type cannot be overloaded
//int test(int a, int b) {
//    cout << "a: " << a << " b: " << b << endl;
//    return 1;
//}

//函数重载
//1.函数名一致
//2.参数不同：个数和类型
int main50() {
    cout << "函数重载" << endl;
    test(1);
    test("aaaa");
    test(1, 3);
    return 0;
}

void test1(int a, int b) {
    cout << "a: " << a << " b: " << b << endl;
}

void test1(int a, int b, int c = 4) {
    cout << "a: " << a << " b: " << b << endl;
}

void test1(int a) {
    cout << "a: " << a << endl;
}

int main51() {
    cout << "函数重载和默认参数定义" << endl;
    test1(1);
    //函数调用存在二义性，不确定是调用void test1(int a, int b)还是void test1(int a, int b, int c = 4)
//    test1(1, 2);//Call to 'test1' is ambiguous
    test1(1, 2, 3);

    return 0;
}
