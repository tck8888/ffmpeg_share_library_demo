#include <jni.h>
#include <string>

extern "C" {
#include "libavcodec/avcodec.h"

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_tck_ffmpeg_share_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string hello = av_version_info();
    return env->NewStringUTF(hello.c_str());
}