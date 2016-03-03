#include <stdlib.h>
#include <iostream>
#include <SDL/SDL.h>
#include <unistd.h>

using namespace std;

SDL_Surface *screen;

void display_bmp(char* fileName){

    SDL_Surface *image;

    image = SDL_LoadBMP(fileName);

    if(image == NULL){
        fprintf(stderr,"could not load %s: %s\n",fileName,SDL_GetError());
        return;
    }

    if(image->format->palette && screen->format->palette){
        SDL_SetColors(screen, image->format->palette->colors,0,image->format->palette->ncolors);
    }


    if(SDL_BlitSurface(image,NULL,screen,NULL)<0){
        fprintf(stderr,"BlitSurface error:%s\n",SDL_GetError());
    }

    SDL_UpdateRect(screen, 0, 0, image->w, image->h);

    sleep(10);

    SDL_FreeSurface(image);

}

int main() {

    printf("Initializing SDL\n");

    if((SDL_Init(SDL_INIT_VIDEO)==-1))
    {
        printf("Could not initialize SDL: %s.\n",SDL_GetError());
        return 1;
    }

    screen = SDL_SetVideoMode(512,512,8,SDL_SWSURFACE);
   // screen = SDL_CreateWindow("My Image Window", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL);




    if(screen == NULL){
        fprintf(stderr, "Could not set 640x480x8 video mode: %s\n",SDL_GetError());
        return -1;
    }


    display_bmp("/home/justin/ClionProjects/VideoAudioDemo/resource/lena512.bmp");

    printf("Quiting...\n");

    SDL_Quit();

    return 0;
}