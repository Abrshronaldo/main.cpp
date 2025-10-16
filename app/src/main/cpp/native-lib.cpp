




#include <jni.h>

extern "C"
  JNIEXPORT jstring JNICALL
Java_M_stringFromJNI(JNIEnv* env, jobject ,jobject data) {


    return env->NewStringUTF("Hello from C++");
}
                                                 
                                         
