

cmake_minimum_required(VERSION 3.10)
project(HelloWorldApp)
find_package(JNI REQUIRED)

add_library(native-lib SHARED native-lib.cpp)

target_include_directories(native-lib PRIVATE ${JNI_INCLUDE_DIRS})

