cmake_minimum_required(VERSION 3.17)
project(CPlusKnowledge)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPlusKnowledge src/cplus/day01/main.cpp src/cplus/day01/main.cpp src/cplus/day01/ref.cpp src/cplus/day02/ref.cpp src/cplus/day02/method_1.cpp
        src/cplus/day02/method_2.cpp src/cplus/day02/method_3.cpp src/cplus/day02/method_4.cpp src/cplus/day02/MyTeacher.cpp src/cplus/includes/MyTeacher.h
        src/cplus/day02/classmain.cpp src/cplus/day03/mainclass.cpp src/cplus/day04/classconstr.cpp src/cplus/day05/classstaic.cpp
        src/cplus/day06/class.cpp src/cplus/day07/class.cpp src/cplus/day08/class.cpp src/c/day01/main.c)