//
// Created by QITMAC0000562 on 2020/11/14.
//
#include "../jni.h"
/**
 * JNI动态注册
 * 参考： 享学一期《JNI开发之JNI编译与运行》
 */
JNIEXPORT jstring JNICALL Java_com_java_xknowledge_se_jni_static1_Register_HelloWorld
        (JNIEnv *env, jobject jobject) {
    //由于C++中的JNIENV是在C语言的基础上，进一步进行了封装，故使用JEIENV调用是不需要在使用指针*符号和传递this
    return env->NewStringUTF("hello every body");
}