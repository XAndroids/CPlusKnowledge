//
// Created by QITMAC0000562 on 2020/11/14.
//

#include "string.h"
/**
 * JNI中的字符换
 * 参考： 享学一期《JNI签名问题与访问java成员函数》
 */
JNIEXPORT jstring JNICALL Java_com_java_xknowledge_se_jni_string_StringTest_sayHello
        (JNIEnv *env, jclass jcls, jstring jstr) {
    //要使用Java中的String参数，JNI转换成jstring，再GetStringUTFChars转换成char *
    const char *c_str = NULL;
    jboolean isCopy;
    c_str = (*env)->GetStringUTFChars(env, jstr, &isCopy);
    printf("isCopy:%d\n", isCopy);

    //异常处理
    if (c_str == NULL) {
        return NULL;
    }

    //进行子串拼接
    printf("C_str: %s \n", c_str);
    char buf[128] = {0};
    sprintf(buf, "Hello,你好 %s", c_str);
    printf("c_str: %s \n", buf);

    //释放内存
    (*env)->ReleaseStringUTFChars(env, jstr, c_str);

    //向Java中返回字符串，NewStringUTF返回字符串
    return (*env)->NewStringUTF(env, buf);
}