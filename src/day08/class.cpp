//
// Created by QITMAC0000562 on 2020/10/17.
//
#include <iostream>

using namespace std;

class A1 {
public:
    int a = 3;
    int b = 4;

    void get() {
        cout << "b: " << b << endl;
    }

    void print() {
        cout << "A print:b " << b << endl;
    }
};

class B1 : public A1 {
public:
    int b = 1;
    int c = 2;

    void getChild() {
        cout << "b: " << b << endl;
    }

    void print() {
        cout << "B print:b " << b << endl;
    }
};

int main150() {
    cout << "同名方法和同名成员" << endl;
    B1 b1;
    b1.print();

    //同名方法
    b1.A1::print();
    b1.B1::print();//默认b1.print()

    //同名成员变量
    b1.b = 10;
    b1.print();
    //修改A类（父类）b变量的值
    b1.A1::b = 20;
    b1.A1::print();
    b1.B1::b = 30;
    b1.B1::print();

    return 0;
}

//C++的多继承
//java extends 单继承 implements 接口实现多个
class Base11 {
public:
    Base11(int b1) : b1(b1) {//最好的方式是使用初始化列表

    }

    void printB11() {
        cout << "b1:" << b1 << endl;
    }

private:
    int b1;
};

class Base21 {
public:
    Base21(int b2) : b2(b2) {//最好的方式是使用初始化列表

    }

    void printB21() {
        cout << "b2:" << b2 << endl;
    }

private:
    int b2;
};

class Child11 : public Base11, public Base21 {//C++多继承语法
public:
    Child11(int b1, int b2, int c) : Base11(b1), Base21(b2), c(c) {
        //Base1(b1)//这是错误的
    }

    void printC() {
        cout << "c: " << c << endl;
    }

private:
    int c;
};

int main151() {
    cout << "C++多继承" << endl;
    Child11 c1(1, 2, 3);
    c1.printC();
    c1.printB11();
    c1.printB21();

    return 0;
}

class B_ {
public:
    int b;

    void print() {
        cout << "B_ b " << b << endl;
    }
};

class Base1_ : virtual public B_ {

};

class Base2_ : virtual public B_ {

};

class C : public Base1_, public Base2_ {

};

int main152() {
    cout << "C++多继承二义性" << endl;
    C c;
    //此时访问的b是来源于Base1_还是Base2_？
    c.b = 100;//Non-static member 'b' found in multiple base-class subobjects of type 'B_':，添加virtual关键字解决
    c.Base1_::b = 20;
    c.print();
//    c.b = 200;//此时既可以通过Base1_访问，也可以通过Base2_访问
    c.Base2_::b = 30;
    c.print();
    return 0;
}

//析构函数
class Test0 {
public:
    Test0() {
        cout << "Test 构造函数" << endl;
    }

    //C++继承 析构函数
    //Test 构造函数
    //Test02 构造函数
    //Test 析构函数
    //如果不增加virtual，无法正常析构子类对象
    ~Test0() {//虚析构函数
        cout << "Test 析构函数" << endl;
    }
};

class Test01 : public Test0 {
public:
    Test01() {
        cout << "Test01 构造函数" << endl;
    }

    ~Test01() {
        cout << "Test01 析构函数" << endl;
    }
};

class Test02 : public Test0 {
public:
    Test02() {
        cout << "Test02 构造函数" << endl;
    }

    ~Test02() {
        cout << "Test02 析构函数" << endl;
    }
};

void objTest(Test0 *test0) {
    delete test0;
}

int main153() {
    cout << "C++继承 析构函数" << endl;
    Test02 *test02 = new Test02;
    objTest(test02);
//    delete test02;//直接delete不添加virtual关键字，也能正常析构
    return 0;
}

class Parent {
public:
    Parent(int a = 0) : a(a) {

    }

    virtual void print() {//只有虚函数才能产生多态
        cout << "parent 1" << endl;
    }

    virtual void print2() {//只有虚函数才能产生多态
        cout << "parent print2 2" << endl;
    }

private:
    int a = 0;
};

class D : public Parent {//虚函数在类上，解决环形继承问题
public:
    D(int a = 0, int b = 0) : Parent(a), b(b) {

    }

    void print() {
        cout << "child 1" << endl;
    }

    void print2() {
        cout << "child print2 2" << endl;
    }

private:
    int b = 0;
};

void objectTest1(Parent *parent) {
    parent->print();
    parent->print2();
}

int main154() {
    cout << "C++继承 多态" << endl;
    Parent p1;
    D child1;
    objectTest1(&p1);
    objectTest1(&child1);
    return 0;
}

//C++抽象类
//java abstract
class Shape {//抽象类，这个抽象类是无法实例化的
public:
    virtual void area() = 0;// =0理解成关键字，表示这个函数是一个纯虚函数
    void print() {//抽象类中的普通函数
        cout << "Shape" << endl;
    }
};

class Circle : public Shape {
public:
    Circle(int r) : r(r) {

    }

    void area() {
        cout << "Circle area: " << 3.14 * r * r << endl;
    }

private:
    int r;
};

//重写 重载 重定义
//重写，发生在两个类之间
//    虚函数重写 发生多态
//    非虚函数重写，重定义
//重载必须发生在同一个类之间
class Tri : public Shape {
public:
    Tri(int a, int h) : a(a), h(h) {

    }

    void area() {
        cout << "Tri area: " << a * h / 2 << endl;
    }

    //重写父类的print()
    void print() {
        cout << "Tri" << endl;
    }

    //重载自己的print()
    void print(int a) {
        cout << "a: " << a << endl;
    }

private:
    int a;
    int h;
};

void getArea(Shape *shape) {
    shape->area();
    shape->print();
}

int main155() {
    cout << "C++继承 抽象类" << endl;
    Shape *base = nullptr;

    Circle c1(10);
    Tri t1(1, 2);
    t1.print(3);
    t1.Tri::print();//直接调用重定义函数

    base = &c1;
    c1.area();//多态
    c1.print();

    getArea(&t1);
    return 0;
}

//C++类型转换
class F1 {
public:
    virtual void func() {};//必须得有virtual函数，才能向下转型
};

class G1 : public F1 {

};

void func(int *i) {
}

//C风格：(T)expre
//函数风格：T(expre)
//C++风格：
// static_cast<T>(expre)
// dynamc_cast<T>(expre)
// const_cast<T>(expre)
// reinterpret_cast<T>(expre)
int main156() {
    cout << "C++类型转换" << endl;
    double d = 3.14;
    int a = (int) d;//c语言风格
    int b = int(d);//函数风格
    int b1 = static_cast<int>(d);//C++独有风格

    int a1 = 3;
    const int b2 = (const int) a1;
    const int c1 = static_cast<const int>(a1); //显示的类型转换，更清晰

    F1 *f1 = new F1();
    G1 *g1 = new G1();
    F1 *f2 = dynamic_cast<F1 *>(g1);//向上转型
    cout << "f2: " << f2 << endl;
    G1 *g2 = dynamic_cast<G1 *>(f1);//向下转型失败，'F1' is not polymorphic，必须得有virtual函数
    cout << "g2: " << g2 << endl;//g2: 0x0，虽然转换成功编译通过了，但是是空指针，可以用于判断是子类还是父类，是唯一的作用

    const int f = 10;
    func(const_cast<int *>(&f));//No matching function for call to 'func'，通过类型转换去除const

    int e = 0x76;//ASSCI v
    printf("a = %d,addr=%p\n", e, &e);
    int *ap = &e;
    char *g = reinterpret_cast<char *>(ap);//指针类型转换
    printf("c=%c,addr=%p\n", *g, g);

    return 0;
}

//C++的异常
class H {
public:
    ~H() {
        cout << "~H" << endl;
//        throw 1;//析构函数不要抛出异常
        cout << "~H end" << endl;
    }
};

void f1() throw(int) {
    cout << "f1 start" << endl;
    int a;
    throw 2;
    cout << "f1 end" << endl;
}

void f2() throw(int) {
    cout << "f2 start" << endl;
    H h;
    f1();
    cout << "f2 end" << endl;
}

void f3() {
    cout << "f3 start" << endl;
    try {
        f2();
    } catch (int i) {
        cout << "exception: " << i << endl;
    }
    cout << "f3 end" << endl;
}

int main157() {
    cout << "C++异常" << endl;
    f3();
    return 0;
}

//C++模板，类似Java的泛型
template<typename T>
//模板函数
void swap1(T &a, T &b) {
    T temp(a);
    a = b;
    b = temp;
}

class Printer {
public:
    template<typename T>
    void print(const T &t) {
        cout << t << endl;
    }
};

int main158() {
    cout << "C++模板类" << endl;
    int i = 1;
    int j = 2;
    swap1(i, j);
    cout << "i: " << i << " j: " << j << endl;

    double n = 1.0;
    double m = 2.0;
    swap1(n, m);
    cout << "n: " << n << " m: " << m << endl;

    Printer printer;
    printer.print(i);
    printer.print(n);
    return 0;
}