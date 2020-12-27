package com.tck.ffmpeg.share

/**
 *
 * description:

 * @date 2020/12/27 22:30

 * @author tck88
 *
 * @version v1.0.0
 *
 */
class FFmpegBasicHandler {
    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }


    /**
     * 删除文件
     */
    external fun ffmpegDeleteFile(path: String): Int

    external fun ffmpegRenameFile(srcFile: String, dstFile: String): Int

    external fun ffmpegListFiles(path: String): List<String>?

}