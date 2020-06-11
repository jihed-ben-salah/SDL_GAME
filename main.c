
/**
* @file main.c
* @brief Tester programme
* @author Bechir Mennai
* @version 1.0
* @date Juin 01, 2020
*
* Tester programme pour deplacement aleatoire
*
*/

#include<SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include"entite.h"

   int main(){

	SDL_Surface *screen;
        SDL_Surface *background;
	SDL_Event even;
        SDL_Rect positionecran;
	screen = SDL_SetVideoMode(1280,640,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	entite_sc e;
	Entite_Init(&e,350,380);
	

	int running = 1;
   
   // Ajouter background
 
   background=IMG_Load("background.bmp");
    if(background==NULL)
    {
        printf("Unable to load background: %s\n",SDL_GetError());
        return 1;
    }
    positionecran.x=0;
    positionecran.y=0;

	while(running){
   
		while(SDL_PollEvent(&even)){
			if(even.type == SDL_QUIT || even.key.keysym.sym == SDLK_ESCAPE){
				running = 0;
			}
		}

		SDL_FillRect(screen,NULL,0x000000);
                SDL_BlitSurface(background,NULL,screen,&positionecran);
                deplacement_aleatoire (&e,&screen);
		SDL_Delay(10);
                SDL_Flip(screen);
	}	
	SDL_Quit();
}
