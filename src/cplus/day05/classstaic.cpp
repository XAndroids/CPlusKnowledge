//
// Created by QITMAC0000562 on 2020/10/14.
//

#include <iostream>

using namespace std;//使用命名空间std标准的

class Test {
public:
    void printC() {//非静态函数，可以访问静态的变量 或者静态函数
        cout << "c: " << c << endl;
        getC();
    }

    void addC() {
        c = c + 1;
    }

    static int getC() {//静态成员函数
        cout << "c: " << c << endl;
//        cout << "a: " << a << endl;//静态成员函数，不能调用普通成员函数 或者普通成员变量
        return c;
    }

private:
    int a;
    int b;//成员变量 是每个对象 都有一份
    static int c;//静态成员变量，类的多个对象共享
};

//私有/公开的静态成员初始化
int Test::c = 1;

int main110() {
    cout << "static" << endl;
    //静态成员变量初始化
//    Test::c = 10;//公开的静态成员初始化，无法初始化私有的；
    //静态成员函数调用
    Test test1;
    test1.getC();//1.通过对象访问
    Test::getC();//2.通过类访问
    return 0;
}

class Test1 {
public:
    friend class Test2;//友元类 Test2是Test1的友元类
    //在Test2中可以访问Test1类的私有成员变量，私有函数（private/protected）

    int c;

    Test1() {

    }

    Test1(int a, int b) {
        this->a = a;
        this->b = b;
    }

    void add() {
        a = a + b;
        cout << "a: " << a << endl;
    }

private:
    friend void add1(Test1 test);//友元函数声明，随意放在public或者private中
    friend void print1();

    int a;
    int b;
    static int d;

    void print() {
        cout << "a: " << a << " ,b: " << b << " ,c: " << c << endl;
    }
};

//在类的外部类里面的私有成员变量
//1.友元函数是没有this指针
//2.如果要访问类的非静态成员，需要对象做参数
//3.如果要访问类的静态成员，不需要对象做参数
//4.如果参数是全局对象，则不需要对象做参数

//为什么要设计友元函数 友元类
//1.java反射 直接修改类的私有属性
//2.开了一个后门
void add1(Test1 test) {
    test.a = test.a + test.b;
    cout << "a: " << test.a << test.c << endl;
//    cout << "d: " << Test1::d <<endl;
}

Test1 gTest;

void print1() {
    //如果要访问类的静态成员d，不需要对象做参数
    //如果参数是全局对象gTest，则不需要对象做参数
//    cout << "gTest.a: " << gTest.a << Test1::d << endl;
}

class Test2 {
public:
    void setA(int a) {
        test1.a = a;//Test2声明为Test1的友元类，故可以访问私有成员
        test1.c = a;
    }

    void print() {
        cout << "t1.a:" << test1.a << endl;
        test1.print();
    }

private:
    Test1 test1;
};

//类的友元函数
//1.定义在类的外部
//2.有权访问类的所有private/protected成员
int main111() {
    cout << "友元函数 友元类" << endl;
    Test1 test1;
//    Test1::d = 10;//无法访问静态私有成员，main()非友元函数
    add1(test1);

    Test2 test2;
    test2.setA(2);
    test2.print();
    return 0;
}

//运算符重载
//可以使用用户自定义的数据，使用起来更简单
//java String "abc" + "def"
//C/C++ stract
class Complex {
public:
    int a;
    int i;

    Complex(int a = 0, int i = 0) {
        this->a = a;
        this->i = i;
    }

    void print() {
        cout << "Complex: (" << a << "+" << i << ")" << endl;
    }

private:
    friend Complex myAdd(Complex c1, Complex c2);
    //友元重载+号运算符
    friend Complex operator+(Complex c1, Complex c2);
};

//Complex 相加 外部全局函数实现
Complex myAdd(Complex c1, Complex c2) {
    Complex tmp(c1.a + c2.a, c1.i + c2.i);
    return tmp;
}

//Complex + 运算符号重载，友元函数实现
Complex operator+(Complex c1, Complex c2) {//看成是一个函数
    Complex tmp(c1.a + c2.a, c1.i + c2.i);
    return tmp;
}

int main112() {
    cout << "运算符重载" << endl;
    int a = 0;
    int b = 0;
    int c;
    c = a + b;//基础数据类型 如何运算  C++编译器是不是已经定义好了的

    //复数 实数 + 虚数 a + i  加法 (a1+i1) +  (a2+i2) = (a1+a2) + (i1+i2)
    Complex c1(1, 2);
    c1.print();
    Complex c2(2, 4);
//    Complex sum = myAdd(c1, c2);
//    sum.print();
    Complex sum = c1 + c2;// 函数调用
    sum.print();

    //是不是所有运算符可以重载
    //不是
    //不可以重载的运算符
    //1. .成员访问运算符
    //2. .*,->*成员指针访问运算符
    //3. ::域运算符
    //4. sizeof 长度运算符
    //5. ?: 三目运算符
    //6. #预处理符
    // new/delet new[] delete[] 可以的
    return 0;
}





