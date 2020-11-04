//
// Created by QITMAC0000562 on 2020/10/15.
//

#include <iostream>

using namespace std;
//运算符重载分类
//1.运算符重载为成员函数
//2.运算符重载为全局函数（友元）

//运算符 需要的操作数
//1. 一元运算符 ++ -- 前置/后置
//2. 二元运算符 数学运算符（+ - * /)
//ObjectL op ObjectR
//重载成员函数
//ObjectL.operator op(ObjectR)
//重载友元函数
//operator op(ObjectL,ObjectR)
class Complex1 {
public:
    int a;
    int i;

    Complex1(int a = 0, int i = 0) {
        this->a = a;
        this->i = i;
        cout << "有参构造函数" << a << " " << i << endl;
    }

    ~Complex1() {
        cout << "析构函数" << a << " " << i << endl;
    }

    void print() {
        cout << "Complex: (" << a << "+" << i << ")" << endl;
    }

    //所有的运算符，C++编译器已经给实现了一套，故称为重载
    //重载为成员函数，二元运算符的重载
    Complex1 operator-(Complex1 &c) {
        Complex1 tmp(this->a - c.a, this->i - c.i);
        return tmp;
    }

    //前置-- 重载为成员函数
    Complex1 &operator--() {
        this->a--;
        this->i--;
        return *this;
    }

private:
    friend Complex1 myAdd(Complex1 c1, Complex1 c2);

    friend Complex1 operator+(Complex1 c1, Complex1 c2);

    friend Complex1 &operator++(Complex1 &c1);

    friend Complex1 operator++(Complex1 &c, int);

    friend ostream &operator<<(ostream &out, Complex1 &c);
};

Complex1 myAdd(Complex1 c1, Complex1 c2) {
    Complex1 tmp(c1.a + c2.a, c1.i + c2.i);
    return tmp;
}

//重载成友元函数
Complex1 operator+(Complex1 c1, Complex1 c2) {//看成是一个函数
    Complex1 tmp(c1.a + c2.a, c1.i + c2.i);
    return tmp;
}

//前置++友元函数
Complex1 &operator++(Complex1 &c) {
    c.a++;
    c.i++;
    return c;//返回本身
}

//后置++友元函数
Complex1 operator++(Complex1 &c, int) {//避免和前置++的冲突，使用占位参数区分
    //后置
    //1.返回Complex变量本身
    //2.+1 -1
    Complex1 tmp = c;//范湖局部（函数栈）的引用 指针 都是不可以的，可能报错
    c.a++;
    c.i++;
    return tmp;//先使用临时变量保存，运算完之后返回
}

//如果需要转换成成员函数，必须在ostream对象添加重载函数
//当我们无法修改左操作数的时候，只能通过友元重载
ostream &operator<<(ostream &out, Complex1 &c) {
    out << "Complex1: (" << c.a << "+" << c.i << "i)" << endl;
    return out;
}

int main120() {
    cout << "运算符重载" << endl;
    Complex1 c3(2, 5), c4(1, 2);
    Complex1 result;
    result = c3 - c4;
    result.print();

    Complex1 c5(4, 4);
    ++c5;
    c5.print();
    --c5;
    c5.print();
    return 0;
}

int main121() {
    cout << "后置++ --" << endl;
    //前置和后置的区别？
    //c++：c+1，返回c
    //++c：返回c，c+1

    //前置和后置推算的的一样的：Complex1& operator ++(Complex1 &c);
    Complex1 c6(3, 5);
    c6.print();
    ++c6;
    c6.print();
    Complex1 c7 = c6++;
    c7.print();//c6++先返回c6，在++，故c7还是(4+6)，c6为(5+7)
    c6.print();
    return 0;
}

int main122() {
    cout << "运算符重载加深" << endl;
    //1.友元函数
    //当我们无法修改左操作数的类时，只能使用友元函数
    //2.成员函数
    //= [] () -> 操作符，只能通过成员函数进行重载
    Complex1 c8(4, 5);
    cout << c8 << endl;
    //cout.<<(c8)
    //cout operator << (c8)
    //operator <<(osstream,Complex1)
    return 0;
}

class Name {
public:
    Name(char *pName) {
        size = strlen(pName);
        this->pName = (char *) malloc(size + 1);
        strcpy(this->pName, pName);
    }

    Name(const Name &name) {
        size = name.size;
        this->pName = (char *) malloc(size + 1);
        strcpy(this->pName, name.pName);
    }

    ~Name() {
        if (pName != nullptr) {
            free(pName);
            pName = nullptr;
            size = 0;
        }
    }

    //FIXME 重载成功了吗？Debug没有执行进入到该函数？
    Name &operator=(Name &obj) {
        if (this->pName != nullptr) {
            delete[] pName;
            size = 0;
        }
        size = obj.size;
        pName = new char[size + 1];
        strcpy(pName, obj.pName);
        return *this;
    }

protected:
    char *pName;
    int size;
};

//=不能是友元重载
//Name &operator=(Name &obj) {//Overloaded 'operator=' must be a binary operator (has 1 parameter)
//
//}

void objectTest2() {
    Name obj1("ass");
    Name obj2 = obj1;//默认copy构造函数 浅拷贝
//    obj2 operator = (obj1)
//     Name& operator = (Name&)
}

int main123() {
    cout << "=运算符重载" << endl;
    objectTest2();
    cout << "main结束" << endl;
    return 0;
}

class Test {
public:
    Test() {
        cout << "无参构造函数" << endl;
    }

    Test(int i) {
        cout << "有参构造函数" << endl;
    }

    //new 运算符的重载
    void *operator new(size_t size) {
        cout << "new" << endl;
        void *p = malloc(size);
        return p;
    }
};

int main124() {
    cout << "new 运算符重载" << endl;
    Test *t = new Test;
    return 0;
}

