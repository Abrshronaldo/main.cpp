




#include <jni.h>
#include<iostream>
extern "C"
  JNIEXPORT jstring JNICALL
Java_M_stringFromJNI(JNIEnv* env, jobject ,jobject data) {

std::cout<<"ddd";
    return env->NewStringUTF("Hello from C++");
}
                                                 
                                         
