//
// Created by QITMAC0000562 on 2020/11/13.
//
#include "../jni.h"

void func1(JNIEnv *env, jobject jobject) {
    printf("dynamicNative1");
}

jstring func2(JNIEnv *env, jobject jobject) {
    return (*env)->NewStringUTF(env, "hello everybody 2");
}

jint getRandom(JNIEnv *env, jobject jobject){
    printf("return");
    return 100;
}

//需要动态注册native方法的类名
static const char *mClassName = "com/java/xknowledge/se/jni/dynamic/Register";
//需要动态注册的方法数组
static const JNINativeMethod mMethods[] = {
        {"dynamicFunc1", "()V",                  (void *) func1},
        {"dynamicFunc2",  "()Ljava/lang/String;", (void *) func2},
        {"getRandom",  "()I", (void *) getRandom},
};

//在System.load()时候调用JNI_OnLoad
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    printf("hello dynamic0");
    JNIEnv *env = NULL;
    //获得JNIEnv
    int r = (*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_4);
    if (r != JNI_OK) {
        return -1;
    }
    //反射获取native方法类
    jclass mainActivityCls = (*env)->FindClass(env, mClassName);
    //将动态注册方法注册
    r = (*env)->RegisterNatives(env, mainActivityCls, mMethods, 3);
    if (r != JNI_OK) {
        return -1;
    }
    printf("hello dynamic");
    return JNI_VERSION_1_4;
}