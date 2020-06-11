#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
 #include "roto.h"

int main()
{
    SDL_Surface *ecran = NULL, *image = NULL;
 
    SDL_Event event;
   char pause;
    int continuer = 1;
    
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(660, 441, 32, SDL_HWSURFACE);
    image = SDL_LoadBMP("image.bmp");
 
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
           
        }
   roto(ecran,image,event);
       

    }
 
    SDL_FreeSurface(ecran);
     pause=getchar();
    SDL_FreeSurface(image);

    SDL_Quit();
 
    return 0;
}
