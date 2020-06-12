#ifndef HERO_H_
#define HERO_H_

#include "background.h"

#define SCREEN_W 1000
#define SCREEN_H 400

#define Hero_WIDTH 112
#define Hero_HEIGHT 210 

typedef struct
{
SDL_Surface *personnage;
SDL_Rect poshero;
SDL_Rect posimage;
int vie;
int direction;
}Hero; 


void loadHero(Hero *H,char *c);
void initialiser_hero(Hero *H,int i);
void blithero(Hero H,SDL_Surface *screen);
void animateheroR(Hero *H); 
void animateheroL(Hero *H); 
void MoveheroR(Hero *H);
void MoveheroL(Hero *H);
void free_Hero(Hero *H);


#endif
