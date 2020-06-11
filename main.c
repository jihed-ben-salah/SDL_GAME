#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>



int main (void)
{
        

        SDL_Surface *screen,*mini;
     SDL_Rect posmap;

        // INIT_VIDEO
        if(SDL_Init(SDL_INIT_VIDEO)!=0)
        {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
        }


        // Creation screen

        screen=SDL_SetVideoMode(1000,736,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
        if(screen==NULL)
        {
                printf("Unable to set video mode : %s",SDL_GetError());
                return 1;
        }


        //music

       


     	minimap(mini);



       
        SDL_Quit();
	


	return 0;

}
