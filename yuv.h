//
// Created by justin on 16-3-3.
//

#ifndef VIDEOAUDIODEMO_YUV_H
#define VIDEOAUDIODEMO_YUV_H



class yuv {
public:int simplest_yuv420_split(char* url, int w, int h, int num);
    void simple_yuv420_gray(char* url,int w,int h,char* out);
    void simple_yuv420_half_bright(char* url,int w,int h,char* out);
    void simplest_yuv420_border(char* url, int w , int h , int border, char* out);
    void simplest_yuv420_graybar(char* out, int w, int h, int interval);
    void simplest_rgb24_split(char* url, int w, int h);
    int simplest_rgb24_to_bmp(const char *rgb24path,int width,int height,const char *bmppath);
};


#endif //VIDEOAUDIODEMO_YUV_H
