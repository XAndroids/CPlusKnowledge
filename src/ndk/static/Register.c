//
// Created by QITMAC0000562 on 2020/11/12.
//
#include "Register.h"
/**
 * JNI静态注册
 * 参考： 享学一期《JNI开发之JNI编译与运行》
 */
//JNIEXPORT 与 JNICALL 都是JNI的关键字，表示此函数是要被JNI调用的
//成员方法jobject，代表成员方法的object对象
JNIEXPORT jstring JNICALL Java_com_java_xknowledge_se_jni_static1_Register_HelloWorld
        (JNIEnv *env, jobject jobject) {
    return (*env)->NewStringUTF(env, "hello every body");
}

//静态成员方法jclass对象，代表静态成员方法的class对象
JNIEXPORT jstring JNICALL Java_com_java_xknowledge_se_jni_static1_Register_HelloWorldStatic
        (JNIEnv *env, jclass jclass) {
    return (*env)->NewStringUTF(env, "hello every body static");
}