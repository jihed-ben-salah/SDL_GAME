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

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_image.h"
#include "background.h"
#include "ennemi.h"


int main (void)
{
        
        SDL_Surface *screen;
        SDL_Surface *over;
        SDL_Rect position_over;
   

        int done = 0; 
	int i=0;
	int keysHeld[323] = {0}; // everything will be initialized to false
  
        SDL_Event event;        

        // Déclaration Structure ;
        Background Back;
        Ennemi E;

        // Load
        loadBackground(&Back);
        Load_ennemi(&E);


        // Initialisation      
        initBackground(&Back);
        initialiserennemi(&E,1300,300);


        // INIT_VIDEO
        if(SDL_Init(SDL_INIT_VIDEO)!=0)
        {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
        }


        // Creation screen

        screen=SDL_SetVideoMode(1600,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
        if(screen==NULL)
        {
                printf("Unable to set video mode : %s",SDL_GetError());
                return 1;
        }
        

        // program Game loop
	 SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
	   
            while(!done) {

		while (SDL_PollEvent(&event)) 
                    {
			
		      switch (event.type) {                       

				
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				break;
			
                        }

			// exit if ESCAPE is pressed
			if (keysHeld[SDLK_ESCAPE])
				done = 1;
                        
		}

		Dep_Alea_Ennemi(&E);
 
                //Blit Hero et Background et Ennemi et Text
                
                blitBackground(&Back,screen);
                blit_Ennemi(E,screen); 
		SDL_Flip(screen);
		

	}

	// Liberation memoire
      
	freeBackground(&Back);
        free_Ennemi(&E);

	return 0;

}



