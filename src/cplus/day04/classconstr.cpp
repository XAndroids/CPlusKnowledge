//
// Created by QITMAC0000562 on 2020/10/13.
//

#include <iostream>

using namespace std;

class A {
public:
    A(int a) {//实现了构造函数后，系统不默认的构造函数，Call to implicitly-deleted default constructor of 'B'
        m_a = a;
        cout << "构造函数: " << m_a << endl;
    }

    ~A() {
        cout << "析构函数" << endl;
    }

    int getMA() {
        return m_a;
    }

private:
    int m_a;
};

/**
 * 构造函数的初始化列表
 * 语法:ClassName():m1(xxx),m2(xxx),m3(xxx)
 * 1.为了给B类中组合一个A类对象（A类有有参数的构造函数）
 * 2.初始化const type常变量，必须使用初始化列表
 */
class B {
public:
    //外部传入初始化
//    B(int b, A a) : m_a(2), m_b(12) {//构造函数的初始化列表 默认值
//        m_b = b;
//        m_a = a;
//    }

    B() : m_a(2), m_b(1), m_a2(2), m_a1(4), c(32) {//初始化列表一定要注意顺序问题，是一种错误的习惯
//        m_a = A(2);//Constructor for 'B' must explicitly initialize the member 'm_a' which does not have a default constructor
        m_b = 3;
//        c = 3;//Cannot assign to non-static data member 'c' with const-qualified type 'const int'
    }

    B(int b) : m_a(2), m_a2(3), m_a1(4), c(5) {//正确的初始化列表顺序应该和声明的变量的顺序是一致的

    }

    void print() {
        cout << m_a.getMA() << " " << m_b << endl;
    }

private:
    int m_b;
    A m_a;
    A m_a2;//复杂类型初始化，并且该类型提供了构造函数，则必须在初始化列表中声明构造函数，因为编译器它不知道要调用哪个构造函数
    A m_a1;
    const int c;//常变量java final
};

//我们要初始化B的b1的时候，那么我们必须先初始化B类的成员变量A类型 m_a
//默认构造函数
/**
 * 1.默认的无参构造函数，当我们类没有定义构造函数时，C++编译器默认会提供一个无参构造函数，函数体是空实现
 * 2.当我们写了构造函数之后，系统就不会给我们提供默认的无参的构造函数了
 * 3.默认拷贝构造函数，只要你写了构造函数，C++就不会提供默认的
 */
int main91() {
    cout << "多个对象构造和析构" << endl;
    B b1;

//    B b2(4, A(45));//外部传值初始化
//    b2.print();

    int b(12);
    bool bb(true);
    float f(3.14);
    float f1 = 1.2;
    cout << "b: " << b << " bb: " << bb << " f: " << f << endl;

    //初始化列表顺序研究
    B b2(2);
    return 0;
}

//构造函数再去调用构造函数是一种危险的行为
class Test1 {
public:
    Test1(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    Test1(int a, int b) {
        this->a = a;
        this->b = b;
        Test1(a, b, 10);//构造函数里面调用另外一个构造函数，新产生一个匿名对象
    }

    void print() {
        cout << a << " " << b << " " << c << endl;
    }

    ~Test1() {
        cout << "析构函数" << endl;
    }

private:
    int a;
    int b;
    int c;//int默认值是0，但是不要相信编译器给的默认值
};

//如何在C++里面正确的初始化一个对象
int main92() {
    cout << "构造函数研究" << endl;
    //在栈上面创建对象和释放对象
    Test1 t1(1, 2);
    t1.print();
    return 0;
}


//new delete/new[] delete[]
//对象的动态创建和释放
//在栈上创建对象 和释放对象 与 在堆上创建对象和释放对象 的区别
//栈
//1.在栈上创建的对象，一经创建，对象的大小是无法改变的
//2.在栈上的对象，系统自动创建和销毁
//堆
//1.堆上申请的内存空间 是可以动态调整的
//2.堆上申请的空间，必须自己申请和释放
//malloc/calloc free C语言的 是函数
//new delete C++的语法 new delete它们是属于运算符 不是函数
int main93() {
    cout << "new delete基本语法" << endl;
//    sizeof(int);//这也是运算符

    int *p = (int *) malloc(sizeof(int));//在堆上申请一块内存空间
    *p = 10;
    cout << "*p: " << *p << endl;
    free(p);//释放内存
    p = nullptr;

    int *p1 = new int;
    *p1 = 20;
    cout << "*p1: " << *p1 << endl;
    delete p1;
    cout << "*p1: " << *p1 << endl;//释放并没有断开指针连接，只是设置标记，后续其它分配可以使用

    int *p2 = new int(30);//直接初始化30
    cout << "*p2: " << *p2 << endl;
    cout << "*p1: " << *p1 << endl;//在这里就有问题，p1的内存空间，被p2给使用了
    delete (p2);

    return 0;
}

int main94() {
    cout << "在堆上分配数组" << endl;
    //C语言写法
    int *array = (int *) malloc(sizeof(int) * 10);// int array[10]
    array[0] = 20;
    cout << "array[0]: " << array[0] << endl;
    free(array);

    //C++写法
    int *array1 = new int[10];
    array1[2] = 30;
    cout << "array1[2]: " << array1[2] << endl;
//    delete array1; //不对
    delete[] array1;//这才是正确的释放数组

    //new/delete 与 new[]/delete[]是两组不同的运算符
    return 0;
}

//复杂类型
class Test2 {
public:
    Test2(int a) {
        m_a = a;
        cout << "构造函数 " << m_a << endl;
    }

    void print() {
        cout << m_a << endl;
    }

    ~Test2() {
        cout << "析构函数 " << m_a << endl;
    }

private:
    int m_a;
};

int main95() {
    cout << "在堆上分配复杂类型对象" << endl;
    //C
    //print 0 0
    Test2 *test2 = (Test2 *) malloc(sizeof(Test2));
    test2->print();
    free(test2);//没有调用构造和析构函数

    //C++
    //有参构造函数 20 0
    //print 20 0
    //析构函数 20 0
    Test2 *test3 = new Test2(20);//自动调用构造函数
    test3->print();
    delete test3;//自动调用析构函数

    return 0;
}