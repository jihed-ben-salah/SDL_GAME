#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "collision.h"
typedef struct score
{SDL_Surface *ima;
SDL_Rect pos;
int valeur;
}score;
typedef struct hero
{ SDL_Surface *sprite_right;
SDL_Surface *sprite_left;
SDL_Rect positionsprite;
SDL_Rect left[8];
SDL_Rect right[8],camera;
SDL_Surface *vie,*temps;
int verif;
score Score;
}hero;

//FADHEL PERSO
void initialiser_hero(hero *h);
void Afficher(hero h,SDL_Surface *screen);
void Deplacement_hero(hero h,SDL_Event E);
int Animation_hero(hero *h,SDL_Surface *screen,background *Back,SDL_Surface *BackMasque);

