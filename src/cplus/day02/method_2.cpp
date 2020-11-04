//
// Created by QITMAC0000562 on 2020/10/11.
//

#include <iostream>

using namespace std;

void myPrint(int x = 1) {
    cout << "x:" << x << endl;
}

//当有已经开始有默认参数后，后面的参数都必须有默认参数
//void myPrint2(int a,int b,int c = 1,int d= 2,int e) 不可以这么玩
void myPrint2(int a, int b, int c = 1, int d = 2) {
    cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;
}

//1.如果你填写参数，使用你填写的，不填写默认
//2.在默认参数规则中，如果默认参数出现，那么右边都必须有默认参数
int main40() {
    cout << "函数的默认参数" << endl;
    myPrint();
    myPrint(4);

    myPrint2(1, 2, 3, 4);
    myPrint2(5, 6);
    myPrint2(7, 8, 9);
    return 0;
}

//函数占位参数
void myPrint3(int a, int b, int) {//占位参数只有参数类型，没有参数名称
    cout << "a: " << a << " b: " << b << endl;
}

int main41() {
    cout << "函数占位参数" << endl;
    //myPrint3(1, 3)传递两个参数，不传递占位参数报错
    myPrint3(1, 3, 3);
    return 0;
}

//函数默认参数和占位参数结合
void myPrint4(int a, int b, int = 0) {
    cout << "a: " << a << " b: " << b << endl;
}

//占位参数的意义？
//1.为后面程序留下线索（参数扩展）；
//2.兼容C语言可能出现的不兼容写法；
int main42() {
    cout << "函数占位参数和默认参数结合" << endl;
    myPrint4(3, 4);//占位参数有默认值，可以调用
    myPrint4(3, 4, 5);
    return 0;
}
