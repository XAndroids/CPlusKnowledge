//
// Created by QITMAC0000562 on 2020/11/14.
//
#include "reference.h"
/**
 * JNI引用
 * 参考： 享学一期《JNI签名问题与访问java成员函数》
 */
JNIEXPORT void JNICALL Java_com_java_xknowledge_se_jni_reference_Reference_callJavaStaticMethod
        (JNIEnv *env, jobject jobje) {
    //绝大部分JNI接口（如FindClass、NewObject等返回的都是局部引用
    jclass testCls = (*env)->FindClass(env, "com/java/xknowledge/se/jni/reference/Test");
    jmethodID jtestStaticMethod = (*env)->GetStaticMethodID(env, testCls, "PrintfStaticTest", "()V");
    (*env)->CallStaticObjectMethod(env, testCls, jtestStaticMethod);

    //局部引用再不使用时，显示的使用DeleteLocalRef提前释放所指向的引用，比便于GC回收
    (*env)->DeleteLocalRef(env, testCls);
}

JNIEXPORT void JNICALL Java_com_java_xknowledge_se_jni_reference_Reference_callJavaInstanceMethod
        (JNIEnv *env, jobject jobje) {
    //绝大部分JNI接口（如FindClass、NewObject等返回的都是局部引用
    jclass testCls = (*env)->FindClass(env, "com/java/xknowledge/se/jni/reference/Test");
    jmethodID jtestCreateMethod = (*env)->GetMethodID(env, testCls, "<init>", "()V");
    jobject testObj = (*env)->NewObject(env, testCls, jtestCreateMethod);
    jmethodID jtestMethod = (*env)->GetMethodID(env, testCls, "PrintfTest", "()V");
    (*env)->CallObjectMethod(env, testObj, jtestMethod);

    //局部引用再不使用时，显示的使用DeleteLocalRef提前释放所指向的引用，比便于GC回收
    (*env)->DeleteLocalRef(env, testCls);
    (*env)->DeleteLocalRef(env, testObj);
}