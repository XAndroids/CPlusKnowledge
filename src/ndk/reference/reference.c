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
    jmethodID jtestCreateMethod = (*env)->GetMethodID(env, testCls, "<init>", "()V");//GetMethodID不是局部引用，jmethodID返回结构体
    jobject testObj = (*env)->NewObject(env, testCls, jtestCreateMethod);
    jmethodID jtestMethod = (*env)->GetMethodID(env, testCls, "PrintfTest", "()V");
    (*env)->CallObjectMethod(env, testObj, jtestMethod);

    //局部引用再不使用时，显示的使用DeleteLocalRef提前释放所指向的引用，比便于GC回收
    (*env)->DeleteLocalRef(env, testCls);
    (*env)->DeleteLocalRef(env, testObj);
}

JNIEXPORT jstring JNICALL
Java_com_java_xknowledge_se_jni_reference_Reference_newString(JNIEnv *env, jobject jobj, jint len) {
    jcharArray elemArray;
    jchar *chars = NULL;
    jstring j_str = NULL;

    //定义静态局部变量，局部方法执行完了也不释放，直到程序结束！！！
    static jclass cls_string = NULL;
    static jmethodID jmetid = NULL;

    //第二次执行该方法时，cls_string还保存(*env)->FindClass(env, "java/lang/String");返回的引用地址，故不执行if里逻辑
    if (cls_string == NULL) {
        printf("cls_string is null \n");
        cls_string = (*env)->FindClass(env, "java/lang/String");
        if (cls_string == NULL) {
            return NULL;
        }
    }

    if (jmetid == NULL) {
        printf("jmetid is null \n");
        jmetid = (*env)->GetMethodID(env, cls_string, "<init>", "([C)V");
        if (jmetid == NULL) {
            return NULL;
        }
    }
    printf("this is a line -------------\n");

    elemArray = (*env)->NewCharArray(env, len);
    printf("this is a line2 -------------\n");
    printf("this is a %d,%d,%d\n", cls_string, jmetid, elemArray);
    //在第二次执行时，cls_string虽然保存了上一次返回的局部变量地址，但是第一方法执行完毕后局部变量被回收，故出现"野指针"！！！
    j_str = (*env)->NewObject(env, cls_string, jmetid, elemArray);
    printf("this is a line3 -------------\n");


    (*env)->DeleteLocalRef(env, elemArray);
    elemArray = NULL;
    //故每次执行完函数之后，我们都DeleteLocalRef主动回收局部变量，尤其是静态局部变量。就不会出现野指针了！！
    (*env)->DeleteLocalRef(env, cls_string);
    cls_string = NULL;
    jmetid = NULL;

    printf("end of function \n");
    return j_str;
}

JNIEXPORT jstring JNICALL Java_com_java_xknowledge_se_jni_reference_Reference_JCallC(JNIEnv *env, jobject obj) {
    return Java_com_java_xknowledge_se_jni_reference_Reference_newString(env, obj, 1024);
}