//
// Created by QITMAC0000562 on 2020/11/14.
//
#include "invoke.h"
/**
 * 从C/C++调用Java的类、属性和方法
 * 参考： 享学一期《JNI签名问题与访问java成员函数》
 */
JNIEXPORT jstring JNICALL Java_com_java_xknowledge_se_jni_invoke_Invoker_invoke
        (JNIEnv *env, jobject jobject1) {
    //GetStaticMethodID获取Test的静态成员方法PrintfStaticTest的方法ID，通过CallStaticObjectMethod调用该方法
    jclass testCls = (*env)->FindClass(env, "com/java/xknowledge/se/jni/invoke/Test");
    jmethodID jtestStaticMethod = (*env)->GetStaticMethodID(env, testCls, "PrintfStaticTest", "()V");
    (*env)->CallStaticObjectMethod(env, testCls, jtestStaticMethod);

    //GetMethodID获取Test的成员方法PrintfTest的方法ID，通过CallObjectMethod调用该方法
    //注意调用构造方法，方法名称"<init>"
    jmethodID jtestCreateMethod = (*env)->GetMethodID(env, testCls, "<init>", "()V");
    jobject testObj = (*env)->NewObject(env, testCls, jtestCreateMethod);
    jmethodID jtestMethod = (*env)->GetMethodID(env, testCls, "PrintfTest", "()V");
    (*env)->CallObjectMethod(env, testObj, jtestMethod);

    return (*env)->NewStringUTF(env, "hello every body");
}