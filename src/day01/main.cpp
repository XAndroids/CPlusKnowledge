#include <iostream>

using namespace std;//使用std标准命名空间

int main01() {
    cout << "C语言求圆的面积" << endl;
    double r = 0;
    double s = 0;

    cout << "请输入圆的半径:";
    cin >> r;

    cout << "r的值是:" << r << endl;
    s = 3.14 * r * r;
    cout << "圆的面积" << s << endl;
    return 0;
}

//C++求圆的面积
class MyCicle {
public:
    double m_s;//圆的面积
    double m_r;//圆的半径
public:
    void setR(double r) {
        m_r = r;
    }

    double getR() {
        return m_r;
    }

    double getArea() {
        m_s = 3.14 * m_r * m_r;
        return m_s;
    }
};

int main02() {
    cout << "C++求圆的面积" << endl;
    MyCicle c1;
    double r1;

    cout << "请输入圆的半径:";
    cin >> r1;

    c1.setR(r1);
    cout << "圆的面积:" << c1.getArea() << endl;
    return 0;
}

//namespace 指标识符的各种可见范围
//自定义命名空间nameSpaceA
namespace nameSpaceA {
    int a = 10;
}

namespace nameSpaceB {
    int a = 20;
    namespace nameSpaceC {//命名空间可以嵌套
        struct Teacher {
            char name[20];
            int age;
        };
    }
}

int main03() {
    cout << "命名空间" << endl;
    cout << "nameSpaceA:" << nameSpaceA::a << endl;//使用命名空间nameSpaceA
    using namespace nameSpaceA;
//    cout << "nameSpaceA:" << a << endl;// using namespace nameSpaceA已经引用命名空间，可直接访问a
    using namespace nameSpaceB;

    cout << "nameSpaceA:" << nameSpaceA::a << endl;//用于nameSpaceA和nameSpaceB都声明了a，且都using使用了
    cout << "nameSpaceB:" << nameSpaceB::a << endl;//所以使用nameSpaceA::a避免命名冲突

    nameSpaceB::nameSpaceC::Teacher t1;//使用嵌套命名空间
    t1.age = 33;

    using namespace nameSpaceC;//引用嵌套命名空间
    Teacher t2;
    t2.age = 34;
    return 0;
}

//新增bool
//C++中的bool类型，要么是true，要么是false
//bool 理论上只占用一个字节 = 8bit
//如果多个bool变量定义在一起的时候，可能各自占一个bit
//取决于编译器的实现
//true代表真值，编译器内部1表示
//false代表假值，编译器内部0表示
//C++编译器在赋值的时候将非0转换为true，0转化为false
int main04() {
    cout << "bool 类型" << endl;
    bool b1 = true;//c++编译器
    cout << "sizeof(bool):" << sizeof(b1) << endl;
    b1 = 10;//bool值要么是1，要么是0。10和-1是非0值，故为1，0则为0
    cout << "b1:" << b1 << endl;
    b1 = -1;
    cout << "b1:" << b1 << endl;
    b1 = 0;
    cout << "b1:" << b1 << endl;
    return 0;
}

//c/c++ const
/**
 * const的好处
 * 1.指针函数参数，可以有效提高代码可读性，减少bug
 * 2.清楚的区分参数是输入还是输出特性
 */
struct Teacher {
    char name[20];
    int age;
};

int operatorT1(const Teacher *pT) {//常量指针，表示是一种输入参数，不能改变它指向的值
//    pT->age = 23;//无法改变常量指针的值
    cout << pT->age << endl;
    pT = NULL;//可以改变指针的指向
}

int operatorT2(Teacher *const pT) {//指针常量，不能改变指针指向，可以改变指向内存的值
    pT->age = 2;
//    pT = NULL;//指针常量无法改变指针指向
}

int main05() {
    cout << "const的基本用法" << endl;
    const int a = 10;
    int const b = 20;//一样使用

    const int *c;//常量指针，const修饰的是指针所指向的变量
    c = &a;//指针指向可以修改
//    *c = 30;//所指向的内存空间不能被修改

    int a1 = 1;
    int *const d = &a1;//指针常量，const修饰的是指针本身，指向不可改变
//    d = &a;//指针的指向不可以改变

    const int *const e = &a1;//常量指针常量，指针的指向不能变，所指的内存空间也不能变
//    e = &a;//指针指向不能变
//    *e = 30;//所指的内存空间也不能变
    return 0;
}

//const 和 #define相同和不同的地方
/*
 * #define 是在编译预处理阶段，只是简单的文本替换
 * const 是由编译器处理，提供类型检查和作用域检查
*/
void fun1() {
#define f 10
    const int g = 20;
//#undef f//卸载，如果卸载了就无法使用
}

void fun2() {
    printf("f = %d \n", f);//#局部定义的define宏可以全局访问
//    printf("g = %d \n", g);//局部变量g无法访问
}

#define d1 20

int main06() {
    cout << "const 和 #define" << endl;
    int a = 10;
    int b = 20;
//    int array[a + b];//linux内核可以，gcc编译器支持

    const int c = 10;
    const int d = 20;
    int array2[c + d];
    int array3[c + d1];//const和#define都代表一个常量使用

    fun1();
    fun2();
    return 0;
}