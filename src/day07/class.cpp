//
// Created by QITMAC0000562 on 2020/10/16.
//

#include <iostream>

using namespace std;

//Java 继承 extends
//C++ OOP
//class Child : Parent{}//默认权限访问是private
//class Child : [权限访问 private/protected/public] Parent{}
//访问控制权限，控制子类(派生类)可以访问父类(基类)中的所有的非私有成员变量
class Parent {
public:
    int a;//所有人都可以用

    void print() {
        cout << "a: " << a << " b: " << b << " c: " << c << endl;
    }

protected:
    int b;//自己家里人可以用
private:
    int c;//自己可以用
};

//默认私有继承
class Child : Parent {//如果是默认的继承访问权限，父类public/private/proteced的成员和方法都无法访问
    void test() {
        this->a = 1;
        this->b = 2;
//        this->c = 3;//'c' is a private member of 'Parent'
    }
};

//私有继承
class Child1 : private Parent {//继承访问权限默认是private

public:
    void test() {
        this->a = 1;
        this->b = 2;
//        this->c = 3;//'c' is a private member of 'Parent'
    }
};

//保护继承
class Child2 : protected Parent {
public:
    void test() {
        this->a = 1;
        this->b = 2;
//        this->c = 3;//'c' is a private member of 'Parent'
    }
};

//公有继承
class Child3 : public Parent {
public:
    void test() {
        this->a = 1;
        this->b = 2;
//        this->c = 3;//'c' is a private member of 'Parent'
    }
};

//结构体继承
struct Base {
private:
    int a;
protected:
    int b;
public:
    int c;
};

struct B1 : Base {//默认的public继承

};

/**
 * public 修饰的成员变量 函数 在类的内部，类的外部都能使用
 * protected 修饰的成员变量 函数 在类的内部使用，在继承子类中可以使用，其它 类的外部都不能使用
 * private 修饰的成员变量 函数 在类的内部使用，其它 情况下不能使用
 */
//派生类访问控制
//1 protected 修饰成员 主要是为了在家族中使用
//在实际项目中 全部用public
int main140() {
    cout << "继承" << endl;
    Child child;
//    child.a = 10;//'a' is a private member of 'Parent'
//    child.b = 10;//'b' is a private member of 'Parent'
//    child.c = 10;//'c' is a private member of 'Parent'

    // 外部可见性 private继承： 父类public protected private -> 不可见
    Child1 child1;
//    child1.a;//'a' is a private member of 'Parent'
//    child1.b;//'b' is a private member of 'Parent'
//    child1.c;//'c' is a private member of 'Parent'

    // 外部可见性 protected继承： 父类public protected private -> 不可见
    Child2 child2;
//    child2.a;//'a' is a protected member of 'Parent'
//    child2.b;//'b' is a protected member of 'Parent'
//    child2.c;//'c' is a private member of 'Parent'

    // 外部可见性 public继承： 父类public -> 可见，protected private -> 不可见
    Child3 child3;
//    child3.a;
//    child3 .b;//'b' is a protected member of 'Parent'
//    child3.c;//'c' is a private member of 'Parent'

    B1 b1;
//    b1.a = 10;//'a' is a private member of 'Base'
//    b1.b = 20;//'b' is a protected member of 'Base'
    b1.c = 30;
    return 0;
}

//C++类型的兼容性，多态
class parent {
public:
    parent() {
//        cout << "构造 我是爸爸" << endl;
    }

    parent(const parent &p) {
//        cout << "copy构造 我是爸爸..." << endl;
    }

    ~parent() {
//        cout << "析构 我是爸爸" << endl;
    }

    virtual void print() {//添加virtual关键字，体现多态
        cout << "我是爸爸" << endl;
    }

private:
    int a;
};


class child : public parent {
public:
    //覆盖父类print()方法
    void print() {
        cout << "我是儿子" << endl;
    }

    void print1() {
        cout << "我是儿子： " << c << endl;
    }

private:
    int c;
};

void testPrint(parent *base) {
    base->print();
}

void testPrint(parent &base) {
    base.print();
}

int main141() {
    cout << "兼容性问题，多态" << endl;
    parent p1;
    p1.print();

    child c1;
    c1.print();//调用父类
    c1.print1();//调用子类

    //兼容性问题
    //使用基类型指针（引用）指向子类对象
    //Java面向对象
    parent *p = nullptr;
    p = &c1;
    p->print();//print()是调用那个，C++编译器是根据指针的类型来判断的，但添加virtual后没体现多态

    //指针作为参数
    testPrint(&p1);
    testPrint(&c1);//还是只看指针的类型
    //引用作为参数
    testPrint(p1);
    testPrint(c1);
    //引用作为参数

    //用子类对象初始化父类
    parent p2 = c1;//向上转型是可以的
//    child c2 = p1;//向下转型不行，No viable conversion from 'parent' to 'child'，在特定的语义环境下可以强转
    p2.print();
    return 0;
}

//继承的构造和析构
class Base1 {
public:
    Base1(int a = 0, int b = 0) {
        this->a = a;
        this->b = b;
        cout << "父类构造函数" << endl;
    }

    ~Base1() {
        cout << "父类析构函数" << endl;
    }

    void print() {
        cout << "父类: " << a << " " << b << endl;
    }

private:
    int a;
    int b;
};

class F {
public:
    F(int i) {
        this->i = i;
        cout << "F构造函数" << endl;
    }

    ~F() {
        cout << "析构函数F" << endl;
    }

private:
    int i;
};

class B2 : public Base1 {
public:
    //那些情况要使用初始化列表
    //1.成员变量是一个类类型，类还是有参数的构造函数
    //2.const变量
    //3.初始化父类的成员变量
    B2(int a = 0, int b = 0, int c = 0) : a(4), Base1(a, b) {//通过初始化列表，初始化父类对象
//        Base1(a, b);//新构建一个对象而已
        this->c = c;
        cout << "子类构造: " << c << endl;
    }

    ~B2() {
        cout << "子类析构: " << c << endl;
    }

private:
    int c;
    F a;
};

void testObj() {
    B2 b2(1, 2, 3);//先构造父类，再构造子类；先析构子类，再析构父类
    b2.print();
}

int main142() {
    cout << "继承中的构造析构问题" << endl;
    testObj();
    return 0;
}