//
// Created by QITMAC0000562 on 2020/10/11.
//

#include <iostream>

using namespace std;

int getA1() {
    int a;
    a = 10;
    return a;//FIXME 为什么a可以返回，难道也是值传递，copy??
}

int &getA2() {
    int a;
    a = 20;
    return a;//warning: reference to stack memory associated with local variable 'a' returned [-Wreturn-stack-address]
}

int *getA3() {
    int a;
    a = 30;
    return &a;//warning: address of stack memory associated with local variable 'a' returned [-Wreturn-stack-address]
}

int main20() {
    int a1 = getA1();
    cout << "a1:" << a1 << endl;
    int a2 = getA2();//把栈上的引用或指针返回回来的时候，是有问题的，因为栈上的变量，方法调用完毕之后会被系统回收
    cout << "a2:" << a2 << endl;
    int *a3 = getA3();//FIXME 实际测试只是有warning，并没有不能运行？？
    cout << "a3:" << a3 << endl;
    return 0;
}

int getG1() {//返回的是变量a的数值
    static int a = 10;
    a++;
    return a;
}

int &getG2() {//返回的是变量b引用
    static int b = 20;
    b++;
    cout << "b:" << b << endl;
    printf("&b:%p\n", &b);
    return b;
}

int main21() {
    cout << "static" << endl;
    int g1 = getG1();//返回数值当右值
    cout << "g1:" << g1 << endl;
//    getG1() = 100;//函数返回数值无法当左值

    getG2() = 200;//返回引用当右指，返回的是引用，改变引用指定内存空间的值
    getG2();

    int g2 = getG2();//返回引用当右值，返回的是数值
    printf("&g2:%p\n", &g2);
    cout << "g2: " << g2 << endl;
}



