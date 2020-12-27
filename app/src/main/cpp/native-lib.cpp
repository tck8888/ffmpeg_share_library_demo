#include <jni.h>
#include <string>

extern "C" {
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"

}

extern "C"
JNIEXPORT jint JNICALL
Java_com_tck_ffmpeg_share_FFmpegBasicHandler_ffmpegDeleteFile(JNIEnv *env, jobject thiz,
                                                              jstring path) {

    int ret = 0;
    avpriv_io_delete("");
    if (ret < 0) {
        av_log(NULL, AV_LOG_ERROR, "Failed to delete file %s \n ", "");
        return -1;
    }

    //删除成功

    return 0;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_tck_ffmpeg_share_FFmpegBasicHandler_ffmpegRenameFile(JNIEnv *env, jobject thiz,
                                                              jstring src_file, jstring dst_file) {
    int ret = 0;
    ret = avpriv_io_move("", "");
    if (ret < 0) {
        av_log(NULL, AV_LOG_ERROR, "Failed to rename  %s \n to %s", "");
        return -1;
    }
    //重命名成功

    return 0;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_tck_ffmpeg_share_FFmpegBasicHandler_ffmpegListFiles(JNIEnv *env, jobject thiz,
                                                             jstring path) {

    AVIODirContext *ctx = NULL;
    AVIODirEntry *entry = NULL;
    int ret;
    ret = avio_open_dir(&ctx, "./", NULL);

    if (ret < 0) {
        av_log(NULL, AV_LOG_ERROR, "cant open dir:%s \n", av_err2str(ret));
        return NULL;
    }

    while (true) {
        ret = avio_read_dir(ctx, &entry);
        if (ret < 0) {
            av_log(NULL, AV_LOG_ERROR, "cant read dir:%s  \n", av_err2str(ret));
            goto __fail;
        }
        if (!entry) {
            break;
        }

        av_log(NULL, AV_LOG_INFO, "%12" PRId64"%s \n", entry->size, entry->name);

        avio_free_directory_entry(&entry);
    }
    __fail:
    avio_close_dir(&ctx);

    return NULL;
}