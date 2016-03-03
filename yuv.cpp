//
// Created by justin on 16-3-3.
//

#include "yuv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yuv::simplest_yuv420_split(char* url, int w, int h, int num){

    FILE* fp = fopen(url,"rb+");

    FILE * fp1 = fopen("/home/justin/Desktop/yuvtest/output_420y.y","wb+");
    FILE * fp2 = fopen("/home/justin/Desktop/yuvtest/output_420u.y","wb+");
    FILE * fp3 = fopen("/home/justin/Desktop/yuvtest/output_420v.y","wb+");

    unsigned char* pic = (unsigned char*) malloc(w*h*3/2);

    int i = 0;
    for(i = 0 ; i < num ; i++){

        fread(pic,1,w*h*3/2,fp);

        //Y
        fwrite(pic,1,w*h,fp1);

        //U
        fwrite(pic+w*h, 1,w*h/4,fp2);

        //v
        fwrite(pic+w*h*5/4,1,w*h/4,fp3);

    }

    free(pic);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}

void yuv::simple_yuv420_gray(char* url,int w,int h,char* out){
    FILE* fp  = fopen(url, "rb+");
    FILE* fout = fopen(out,"wb+");

    unsigned char* pic = (unsigned char *) malloc(w * h * 3 / 2);

    fread(pic,1,w*h*3/2,fp);
    memset(pic+w*h,128,w*h/2);
    fwrite(pic,1,w*h*3/2,fout);

    free(pic);
    fclose(fp);
    fclose(fout);

}

/**
 * not pass
 */
void yuv::simple_yuv420_half_bright(char* url,int w,int h,char* out){

    FILE *fp = fopen(url,"rb+");
    FILE *fout = fopen(out,"wb+");

    unsigned char* pic = (unsigned char*)malloc(w*h*3/2);
    fread(pic,1,w*h*3/2,fp);

    int i = 0;
    for(i = 0 ; i < w*h; i++){
        unsigned char temp = pic[i] / 2;
        pic[i] = temp;
    }

    fwrite(pic,1,w*h*3/2,fout);
    free(pic);
    fclose(fp);
    fclose(fout);
}

void yuv::simplest_yuv420_border(char* url, int w , int h , int border, char* out){

    FILE *fp = fopen(url,"rb+");
    FILE *fout = fopen(out,"wb+");
    unsigned char* pic = (unsigned  char*)malloc(w*h*3/2);
    fread(pic,1,w*h*3/2,fp);
    int i = 0 , j = 0;
    for(i = 0 ; i < h ; i++){
        for( j = 0 ; j < w ; j ++){
            if(i < border || i > h- border || j < border || j > w - border){
                pic[i*w+j] = 255;
                //     pic[i*w+j] = 110;
            }
        }
    }
    fwrite(pic,1,w*h*3/2,fout);
    free(pic);
    fclose(fp);
    fclose(fout);
}

void yuv::simplest_yuv420_graybar(char* out, int w, int h, int interval){

    FILE* fout = fopen(out,"wb+");

    unsigned char* yuvY = (unsigned char*)malloc(w*h);
    unsigned char* yuvU = (unsigned char*)malloc(w*h/4);
    unsigned char* yuvV = (unsigned char*)malloc(w*h/4);

    int unitColor= 255/(w/interval);

    int i = 0 , j = 0 ;
    for(i = 0 ; i < h ; i ++){
        for (j = 0; j < w ; ++j) {
            yuvY[i*w+j]=j/interval* unitColor;
        }
    }

    for(i=0;i<w*h/4;i++){
        yuvU[i] = 128;
    }
    for (i = 0; i < w*h/4; ++i) {
        yuvV[i] = 128;
    }

    fwrite(yuvY,1,w*h,fout);
    fwrite(yuvU,1,w*h/4,fout);
    fwrite(yuvV,1,w*h/4,fout);


    free(yuvY);
    free(yuvU);
    free(yuvV);

    fclose(fout);


}

void yuv::simplest_rgb24_split(char* url, int w, int h){

    FILE* imgFp = fopen(url,"rb+");
    FILE * fpR = fopen("/home/justin/Desktop/yuvtest/output_r.y","wb+");
    FILE * fpG = fopen("/home/justin/Desktop/yuvtest/output_g.y","wb+");
    FILE * fpB = fopen("/home/justin/Desktop/yuvtest/output_b.y","wb+");

    unsigned char* imgData = (unsigned char *) malloc(w * h * 3);
    /*
    unsigned char* imgR= malloc(w*h);
    unsigned char* imgG= malloc(w*h);
    unsigned char* imgB= malloc(w*h);
     */


    fread(imgData,1,w*h*3,imgFp);

    int i = 0;

    for ( i = 0; i < w * h * 3; i+=3) {

        /*
        imgR[i]=imgData+i;
        imgG[i]=imgData+i+1;
        imgB[i]=imgData+i+2;
         */
        fwrite(imgData+i,1,1,fpR);
        fwrite(imgData+i+1,1,1,fpG);
        fwrite(imgData+i+2,1,1,fpB);
    }

    /*
    fwrite(imgR,1,w*h,fpR);
    fwrite(imgG,1,w*h,fpG);
    fwrite(imgB,1,w*h,fpB);
     */

    free(imgData);
    /*
    free(imgR);
    free(imgG);
    free(imgB);
     */
    fclose(imgFp);
    fclose(fpR);
    fclose(fpG);
    fclose(fpB);
}

/**
 * Convert RGB24 file to BMP file
 * @param rgb24path    Location of input RGB file.
 * @param width        Width of input RGB file.
 * @param height       Height of input RGB file.
 * @param url_out      Location of Output BMP file.
 */
int yuv::simplest_rgb24_to_bmp(const char *rgb24path,int width,int height,const char *bmppath){
    typedef struct
    {
        long imageSize;
        long blank;
        long startPosition;
    }BmpHead;

    typedef struct
    {
        long  Length;
        long  width;
        long  height;
        unsigned short  colorPlane;
        unsigned short  bitColor;
        long  zipFormat;
        long  realSize;
        long  xPels;
        long  yPels;
        long  colorUse;
        long  colorImportant;
    }InfoHead;

    int i=0,j=0;
    BmpHead m_BMPHeader={0};
    InfoHead  m_BMPInfoHeader={0};
    char bfType[2]={'B','M'};
    int header_size=sizeof(bfType)+sizeof(BmpHead)+sizeof(InfoHead);
    unsigned char *rgb24_buffer=NULL;
    FILE *fp_rgb24=NULL,*fp_bmp=NULL;

    if((fp_rgb24=fopen(rgb24path,"rb"))==NULL){
        printf("Error: Cannot open input RGB24 file.\n");
        return -1;
    }
    if((fp_bmp=fopen(bmppath,"wb"))==NULL){
        printf("Error: Cannot open output BMP file.\n");
        return -1;
    }

    rgb24_buffer=(unsigned char *)malloc(width*height*3);
    fread(rgb24_buffer,1,width*height*3,fp_rgb24);

    m_BMPHeader.imageSize=3*width*height+header_size;
    m_BMPHeader.startPosition=header_size;

    m_BMPInfoHeader.Length=sizeof(InfoHead);
    m_BMPInfoHeader.width=width;
    //BMP storage pixel data in opposite direction of Y-axis (from bottom to top).
    m_BMPInfoHeader.height=-height;
    m_BMPInfoHeader.colorPlane=1;
    m_BMPInfoHeader.bitColor=24;
    m_BMPInfoHeader.realSize=3*width*height;

    fwrite(bfType,1,sizeof(bfType),fp_bmp);
    fwrite(&m_BMPHeader,1,sizeof(m_BMPHeader),fp_bmp);
    fwrite(&m_BMPInfoHeader,1,sizeof(m_BMPInfoHeader),fp_bmp);

    //BMP save R1|G1|B1,R2|G2|B2 as B1|G1|R1,B2|G2|R2
    //It saves pixel data in Little Endian
    //So we change 'R' and 'B'
    for(j =0;j<height;j++){
        for(i=0;i<width;i++){
            char temp=rgb24_buffer[(j*width+i)*3+2];
            rgb24_buffer[(j*width+i)*3+2]=rgb24_buffer[(j*width+i)*3+0];
            rgb24_buffer[(j*width+i)*3+0]=temp;
        }
    }
    fwrite(rgb24_buffer,3*width*height,1,fp_bmp);
    fclose(fp_rgb24);
    fclose(fp_bmp);
    free(rgb24_buffer);
    printf("Finish generate %s!\n",bmppath);
    return 0;
}
