#ifndef MINIMAP_H
#define MINIMAP_H
#include "background.h"
#include "hero.h"

typedef struct {
	SDL_Surface *minimap_Img;
        SDL_Rect minimap_Pos;
       SDL_Surface *Dot;
SDL_Rect Dot_Pos;
       
  
}minimap;


void loadminimap(minimap *mini);
void initialiser_minimap(minimap *mini);
void afficher_minimap(minimap *mini,SDL_Surface *screen,background back,Hero h);
void free_minimap(minimap *mini);
#endif
