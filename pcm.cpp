//
// Created by justin on 16-3-3.
//

#include <stdio.h>
#include <stdlib.h>
#include "pcm.h"

void pcm::simplest_pcm161e_split(char *url) {

    FILE* soundFp = fopen(url,"rb+");
    FILE* leftFp = fopen("/home/justin/Desktop/yuvtest/sound/left.pcm","wb+");
    FILE* rightFp = fopen("/home/justin/Desktop/yuvtest/sound/right.pcm","wb+");

    unsigned char* sample = (unsigned char *) malloc(4);

    while(!feof(soundFp)){

        fread(sample,1,4,soundFp);
        fwrite(sample,1,2,leftFp);
        fwrite(sample+2,1,2,rightFp);

    }

    free(sample);
    fclose(soundFp);
    fclose(leftFp);
    fclose(rightFp);
}

void pcm::simplest_pcm16le_halfvolumeleft(char *url) {

    FILE * soundfp = fopen(url,"rb+");
    FILE * outfp = fopen("/home/justin/Desktop/yuvtest/sound/halfvolumnleft.pcm","wb+");

    unsigned char* sample = (unsigned char*) malloc(4);

    while(!feof(soundfp)){

        short* tempsample = NULL;
        fread(sample,1,4,soundfp);

       // *sample = *sample/2;
        tempsample = (short *) sample;
        *tempsample = *tempsample/2;

        fwrite(sample,1,2,outfp);
        fwrite(sample+2,1,2,outfp);
    }

    free(sample);
    fclose(soundfp);
    fclose(outfp);

}

void pcm::simplest_pcm16le_doublespeed(char *url) {

    FILE* soundFilefp = fopen(url,"rb+");

    FILE* outFp = fopen("/home/justin/Desktop/yuvtest/sound/doublspeed.pcm","wb+");

    unsigned char* data = (unsigned char *) malloc(4);
    int cnt = 0;

    while (!feof(soundFilefp)){

        fread(data,1,4,soundFilefp);

        if(cnt%2==0){
            fwrite(data,1,2,outFp);
            fwrite(data+2,1,2,outFp);
            //fwrite(data,1,4,outFp);
        }
        cnt++;
    }

    free(data);
    fclose(soundFilefp);
    fclose(outFp);
}
