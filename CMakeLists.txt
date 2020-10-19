cmake_minimum_required(VERSION 3.17)
project(CPlusKnowledge)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPlusKnowledge src/day01/main.cpp src/day01/main.cpp src/day01/ref.cpp src/day02/ref.cpp src/day02/method_1.cpp
        src/day02/method_2.cpp src/day02/method_3.cpp src/day02/method_4.cpp src/day02/MyTeacher.cpp src/includes/MyTeacher.h
        src/day02/classmain.cpp src/day03/mainclass.cpp src/day04/classconstr.cpp src/day05/classstaic.cpp
        src/day06/class.cpp src/day07/class.cpp src/day08/class.cpp)