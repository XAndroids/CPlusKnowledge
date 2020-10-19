//
// Created by QITMAC0000562 on 2020/10/11.
//

#pragma once//只包含一次

//这个宏的作用是防止重复导入
//#ifndef CPLUSKNOWLEDGE_MYTEACHER_H
//#define CPLUSKNOWLEDGE_MYTEACHER_H

//类的声明
class MyTeacher {
private:
    int m_age;
    char m_name[32];
public:
    void setAge(int age);

    int getAge();
};


//#endif //CPLUSKNOWLEDGE_MYTEACHER_H
