//
// Created by QITMAC0000562 on 2020/11/12.
//
#include "Register.h"
/**
 * JNI静态注册
 * 参考： 享学一期《JNI开发之JNI编译与运行》
 */
JNIEXPORT jstring JNICALL Java_com_java_xknowledge_se_jni_Register_HelloWorld
        (JNIEnv *env, jobject jobject) {
    return (*env)->NewStringUTF(env, "hello every body");
}