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