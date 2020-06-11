#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
 #include "roto.h"
void roto(SDL_Surface *ecran,SDL_Surface *image,SDL_Event event)
   {int tempsPrecedent = 0;
    int tempsActuel = 0;
    double angle = 0;
    double zoom = 1;
    int TEMPS =30;
    SDL_Rect rect;
    SDL_Surface *rotation=NULL;
int i;
for(i=0;i<100;i++)
{
       SDL_PollEvent(&event);
      tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle +=3; //On augmente l'angle pour que l'image tourne sur elle-même.
 
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation=rotozoomSurface(image, angle, zoom, 1); //On transforme la surface image.
        
        //On repositionne l'image en fonction de sa taille.
        rect.x =  300-rotation->w / 2;
        rect.y =  280- rotation->h / 2;
 
        SDL_BlitSurface(rotation , NULL, ecran, &rect); //On affiche la rotation de la surface image.
        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle.
 
       
 
         SDL_Flip(ecran);
}
}




















