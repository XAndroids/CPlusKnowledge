//
// Created by QITMAC0000562 on 2020/10/10.
//

#include <iostream>

using namespace std;

int main11() {
    cout << "引用的基本用法" << endl;
    int a = 10;
    //type & name = var;
    int &b = a;   //b就是一个引用，请不要用C的语法思考
    printf("b:%d\n", b);
    printf("b:%d\n", a);

    b = 100;//b修改值，就相当于修改a
    printf("b:%d\n", b);
    printf("b:%d\n", a);

    //相当于type * const 指针常量：指针一直指向原变量不能修改，指针指向的内存空间可以修改
//    int &c;//会报错，普通的引用必须要依附鞪变量，必须初始化
    return 0;
}

void myswap(int a, int b) {//参数值传递
    int tmp = a;
    a = b;
    b = tmp;
}

void myswap1(int *a, int *b) {//指针参数
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void myswap2(int &a, int &b) {//别名参数
    int tmp = a;
    a = b;
    b = tmp;
}

int main12() {
    cout << "基本类型的引用" << endl;
    int x, y;
    x = 10;
    y = 20;
    myswap(x, y);
    printf("x:%d, y:%d \n", x, y);
    myswap1(&x, &y);
    printf("x:%d, y:%d \n", x, y);
    myswap2(x, y);//a就是x的别名，b就是y的别名
    printf("x:%d, y:%d \n", x, y);
    return 0;
}

struct Teacher {
    char name[20];
    int age;
};

void printT(Teacher pT) {//值传递
    pT.age = 36;
    cout << pT.age << endl;
}

void printT1(Teacher *pT) {
    pT->age = 37;
    cout << pT->age << endl;
}

void printT2(Teacher &pT) {
    pT.age = 38;
    cout << pT.age << endl;
}

int main13() {
    cout << "复杂类型的引用" << endl;
    Teacher t1;
    t1.age = 35;
    printT(t1);//pT是形参，t1 copy一份数据给pT
    printf("t1.age:%d\n", t1.age);
    printT1(&t1);
    printf("t1.age:%d\n", t1.age);
    printT2(t1);//pT是t1的别名
    printf("t1.age:%d\n", t1.age);
    return 0;
}

void modifyA(int &a) {
    a = 11;
}

//modifyA函数C++编译器完成后，就如下modifyA1形式
//引用的本质就是常量指针
void modifyA1(int *const a) {
    *a = 12;
}

struct Teacher1 {
    char name[64];
    int age;//8
    int &a;//8
    int &b;//8
};

int main14() {
    cout << "引用的本质思考" << endl;
    int a = 10;
    int &b = a;
    modifyA(a);//函数调用的时候，不需要手动取a地址
    //对同一内存空间，可以取好几个名字吗？
    //引用就是取别名
    //从使用的角度，引用会让人误会其只是一个别名，没有自己的内存空间
    printf("&a:%p, &b:%p \n", &a, &b);
    modifyA1(&a);//指针我们需要手动取地址

    printf("sizeof(Teacher1):%lu= \n", sizeof(Teacher1));
    return 0;
}



