cmake_minimum_required(VERSION 3.6)
project(apue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11 -x c -ansi")

set(SOURCE_FILES main.c chapter1/tee.c chapter1/pid.c)
add_executable(apue ${SOURCE_FILES})