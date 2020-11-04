//
// Created by QITMAC0000562 on 2020/10/12.
//

#include <iostream>
#include <string.h>

using namespace std;

/**
 * 构造函数
 * 1.没有返回值
 * 2.函数名称和类名相同 className(){}
 * 析构函数
 * 1. 没有返回值
 * 2. 函数名称和类名相同 ~ClassName(){}
 */
class Test {
public:
    int i;

    Test() {//构造函数，初始化工作
        cout << "构造函数" << endl;
        a = 10;
        p = (char *) malloc(100);//给p变量在堆去分配一块内存
        strcpy(p, "adafsdf");
    }

    ~Test() {//析构函数，释放资源的工作，当对象被销毁之前，由编译器主动调用
        cout << "析构函数" << endl;
        if (p != nullptr) {//在堆上分配的内存空间，必须自己管理内存
            free(p);
            p = nullptr;
        }
    }

    void print() {//成员函数
        cout << "a: " << a << " p: " << p << endl;
    }

protected:
    int j;
private:
    int a;
    char *p;

    void test() {

    }
};

void objTest() {
    Test t1;//创建了一个对象
    t1.print();
}

int main80() {
    cout << "C++类与对象" << endl;
    objTest();
    return 0;
}

class Test2 {
public:
    void init(int a, int b) {
        m_a = a;
        m_b = b;
    }

    Test2() {//无参数构造函数
        m_a = 0;
        m_b = 0;
        cout << "无参构造函数 " << m_a << " " << m_b << endl;
    }

    Test2(int a) {//有参数的构造函数
        m_a = a;
        m_b = 0;
        cout << "有参构造函数 " << m_a << " " << m_b << endl;
    }

    Test2(int a, int b) {//有参数的构造函数
        m_a = a;
        m_b = b;
        cout << "有参构造函数 " << m_a << " " << m_b << endl;
    }

    Test2(const Test2 &obj) {//拷贝构造函数
        m_a = obj.m_a;
        m_b = obj.m_b;
        cout << "拷贝构造函数 " << m_a << " " << m_b << endl;
    }

    ~Test2() {
        cout << "析构函数 " << m_a << " " << m_b << endl;
    }

    void print() {
        cout << "print " << m_a << " " << m_b << endl;
    }

    int getA() {
        return m_a;
    }

private:
    int m_a;
    int m_b;
};

void objTest1() {
    Test2 tl;
}

void objTest2() {
    //C++编译器自动调用的构造函数
    //1. 括号法
    Test2 t1;//无参构造函数
    Test2 t2(1);//C++编译器自动调用对应的构造函数
    Test2 t3(1, 3);

    //2.=号法
    Test2 t4 = (2, 3, 4, 5);//= C++对"="功能增强，调用了构造函数
    Test2 t5 = 9;//这里不是把9赋值给t4，不是的，这里是调用了构造函数

    //3.直接调用构造函数，手动调用构造函数
    Test2 t6 = Test2(1, 2);
    t1 = t5;//把t5 copy给t1 赋值操作

    Test2 t7 = t5;//调用了拷贝函数
    Test2 t8(t5);
}

void objTest3() {
    Test2 t1;
    t1.init(1, 2);

    Test2 tArr[3];
    tArr[0].init(1, 2);
    tArr[1].init(2, 3);
    tArr[2].init(3, 4);
}

void copyTest(Test2 t) {
    cout << t.getA() << endl;
}

void objTest4() {
    Test2 t1(1, 2);
    Test2 t2 = t1;//1.= 调用拷贝构造函数
    Test2 t3(t2);//2.() 调用拷贝构造函数
    t2.print();
    cout << "t2初始化完毕" << endl;
    copyTest(t2);//3.当我们用t2实参初始化形参t的时候，会自动调用拷贝构造函数
}

Test2 getTest2() {
    Test2 t(4, 5);
    return t;
}

//objTest5
//有参构造函数 4 5
//getTest2调用完毕
//        print 4 5
//析构函数 4 5
void objTest5() {
    Test2 t1 = getTest2();//初始化 t1, 创建一个匿名对象，(扶正)从匿名转成了有名字了 t1
    cout << "getTest2调用完毕" << endl;
    t1.print();
}

//有参构造函数 1 2
//有参构造函数 4 5
//析构函数 4 5 getTest2的t被析构
//getTest2调用完毕
//        print 4 5
//析构函数 4 5
void objTest6() {
    Test2 t1(1, 2);//t1已经初始化了
    t1 = getTest2();//赋值
    cout << "getTest2调用完毕" << endl;
    t1.print();
}

int main81() {
    cout << "构造函数分类" << endl;
//    objTest1();
//    objTest2();
//    objTest3();
//    objTest4();// 当我们用t2 实参初始化形参t的时候，会自动调用拷贝构造函数
//    objTest5();
//    objTest6();
    return 0;
}

class Test3 {
public:
    int i;

    Test3() {//构造函数，初始化工作
        cout << "构造函数" << endl;
        a = 10;
        p = (char *) malloc(100);//给p变量在堆去分配一块内存
        strcpy(p, "adafsdf");
    }

    Test3(const char *arg) {
        a = 20;
        p = (char *) malloc(100);//给p变量在堆区分配了一块内存 colloc
        strcpy(p, arg);
        cout << "构造函数" << endl;
    }

    Test3(const Test3 &t) {//添加深拷贝函数之后，析构不会报错
        a = t.a;
        p = (char *) malloc(100);
        strcpy(p, t.p);
    }

    ~Test3() {//析构函数，释放资源的工作，当对象被销毁之前，由编译器主动调用
        cout << "析构函数" << endl;
        if (p != nullptr) {//在堆上分配的内存空间，必须自己管理内存
            free(p);
            p = nullptr;
        }
    }

    void print() {//成员函数
        cout << "a: " << a << " p: " << p << endl;
    }

protected:
    int j;
private:
    int a;
    char *p;

    void test() {

    }
};

void objTest7() {
    Test3 t1("asdf");
    Test3 t2 = t1;//没有深拷贝函数，默认调用浅拷贝，析构的时候报错CPlusKnowledge(64499,0x111bc75c0) malloc: *** error for object
    cout << "objTest7调用" << endl;
}

int main82() {
    cout << "浅拷贝和深拷贝" << endl;
    objTest7();
    cout << "main 调用" << endl;
    return 0;
}





