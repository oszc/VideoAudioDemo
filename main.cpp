#include "yuv.h"
#include "pcm.h"



int main() {
    //yuv myYuv;

    //myYuv.simplest_yuv420_split("/home/justin/ClionProjects/VideoAudioDemo/lena_256x256_yuv420p.yuv",256,256,1);
    //simple_yuv420_gray("/home/justin/ClionProjects/VideoAudioDemo/lena_256x256_yuv420p.yuv",256,256,"/home/justin/Desktop/yuvtest/output_420gray.yuv");
    //simple_yuv420_half_bright("/home/justin/ClionProjects/VideoAudioDemo/lena_256x256_yuv420p.yuv",256,256,"/home/justin/Desktop/yuvtest/output_420half_bright.yuv");
    //simplest_yuv420_border("/home/justin/ClionProjects/VideoAudioDemo/lena_256x256_yuv420p.yuv",256,256,20,"/home/justin/Desktop/yuvtest/output_420_border_bright.yuv");
    //simplest_yuv420_graybar("/home/justin/Desktop/yuvtest/output_420_graybar_800*200.yuv",800,200,20);
    //simplest_rgb24_split("/home/justin/ClionProjects/VideoAudioDemo/cie1931_500x500.rgb",500,500);
    //myYuv.simplest_rgb24_to_bmp("/home/justin/ClionProjects/VideoAudioDemo/lena_256x256_rgb24.rgb",256,256,"/home/justin/Desktop/yuvtest/output_420_border_bright.bmp");
    pcm myPcmProcess;
    myPcmProcess.simplest_pcm161e_split("/home/justin/ClionProjects/VideoAudioDemo/resource/NocturneNo2inEflat_44.1k_s16le.pcm");
    return 0;
}