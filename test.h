#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED
typedef struct {
	SDL_Surface *backgroundImg;
        SDL_Rect backgroundPos;
    
}background;
typedef struct{

SDL_Surface * img;
SDL_Rect pos;
}entite_sc;
void initialiser_Background(background *Backg);
void initialiser_entite_secondaire (entite_sc *E );
void afficher_entite_secondaire (SDL_Surface * screen ,entite_sc *E,SDL_Rect *camera);
#endif // JEUX_H_INCLUDED
