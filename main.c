#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_image.h"
#include "background.h"
#include "hero1.h"
#include "hero_deux.h"

int main (void)
{
        
        SDL_Surface *screen;   

        int done = 0; 
	int keysHeld[323] = {0}; // everything will be initialized to false
  
        SDL_Event event;

        // Déclaration Structure ;
        Hero H; 
        hero_deux H2;
        Background Back;

        // Load
        loadHero(&H);
        loadBackground(&Back);
        loadhero_deux(&H2);

        // Initialisation      
        initBackground(&Back);
        initialiser_hero(&H);
        initialiser_hero_deux(&H2);

        // INIT_VIDEO
        if(SDL_Init(SDL_INIT_VIDEO)!=0)
        {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
        }


        // Creation screen

        screen=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
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
			if(keysHeld[SDLK_RIGHT]) 
                        {    
    
                             MoveheroR(&H,&Back); // Move Right
                             animateheroR(&H);
			}
                        
                        if  (keysHeld[SDLK_LEFT])
                        {    

                             MoveheroL(&H,&Back); // Move Left
                             animateheroL(&H);
                             
			}

                         // HERO 2
			if(keysHeld[SDLK_d]) 
                        {    
    
                             MoveheroD(&H2); // Move Right
                             animateheroD(&H2);
			}
                        
                        if  (keysHeld[SDLK_q])
                        {    

                             MoveheroG(&H2); // Move Left
                             animateheroG(&H2);
                             
			}
            

		}


		//Blit Hero et Background et Ennemi et Text
                
                blitBackground(&Back,screen);
                blithero(H,screen);
                blithero_deux(H2,screen);
		SDL_Flip(screen);
		

	}

	// Liberation memoire
      
	freeBackground(&Back);
        //free_Hero(&H);
        free_hero_deux(&H2);

	return 0;

}



