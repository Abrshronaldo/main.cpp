




#include <jni.h>

extern "C"
  JNIEXPORT jstring JNICALL
stringFromJNI(JNIEnv* env, jobject /* this */) {
    return env->NewStringUTF("Hello from C++");
}
                                                 
                                         
