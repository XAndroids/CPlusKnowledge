cmake_minimum_required(VERSION 3.17)
project(CPlusKnowledge)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPlusKnowledge src/cplus/day01/main.cpp src/cplus/day01/main.cpp src/cplus/day01/ref.cpp src/cplus/day02/ref.cpp src/cplus/day02/method_1.cpp
        src/cplus/day02/method_2.cpp src/cplus/day02/method_3.cpp src/cplus/day02/method_4.cpp src/cplus/day02/MyTeacher.cpp src/cplus/includes/MyTeacher.h
        src/cplus/day02/classmain.cpp src/cplus/day03/mainclass.cpp src/cplus/day04/classconstr.cpp src/cplus/day05/classstaic.cpp
        src/cplus/day06/class.cpp src/cplus/day07/class.cpp src/cplus/day08/class.cpp src/c/day01/main.c src/c/day02/goto.c src/c/day02/main5.c
        src/c/day02/test.h src/c/day02/test2.h src/c/day02/main3.c src/c/day02/main1.c src/c/day02/main2.c src/c/day02/main4.c src/c/day02/main6.c
        src/c/day02/main7.c src/c/day02/main8.c src/c/day02/main9.c src/c/day03/main.c src/c/day03/main2.c src/c/day03/main3.c src/c/day04/main.c
        src/c/day04/main2.c src/c/day04/main3.c src/c/day05/main.c src/c/day05/main1.c src/c/day06/main.c src/c/day06/main2.c src/c/day06/main3.c
        src/c/day06/main4.c src/ndk/dynamic/dyReg.c src/ndk/jnienv/JNIEnv.cpp src/ndk/invoke/invoke.c src/ndk/invoke/invoke.h src/ndk/string/string.h src/ndk/string/string.c)

#创建firstLib库
add_library(firstLib SHARED src/ndk/static/Register.h src/ndk/static/Register.c)
add_library(firstdyLib SHARED src/ndk/dynamic/dyReg.c)
add_library(invokeLib SHARED src/ndk/invoke/invoke.h src/ndk/invoke/invoke.c)
add_library(stringLib SHARED src/ndk/string/string.h src/ndk/string/string.c)
add_library(referenceLib SHARED src/ndk/reference/reference.h src/ndk/reference/reference.c)