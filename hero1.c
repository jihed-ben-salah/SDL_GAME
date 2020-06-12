#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>       
#include "hero1.h"
#include "hero_deux.h"
#include "background.h"


void loadHero(Hero *H)
{

H->personnage=IMG_Load("Hero.png");

if(H->personnage==NULL)
    {
        printf("Unable to load on H->personnage: %s\n",SDL_GetError());
        
    }


}


void initialiser_hero(Hero *H)
{

H->posimage.x=0;
H->posimage.y= 455;

H->posimage.w=Hero_WIDTH;
H->posimage.h=Hero_HEIGHT;


H->poshero.x=0;
H->poshero.y=0;
H->poshero.w=Hero_WIDTH;
H->poshero.h=Hero_HEIGHT;

H->vie=100;

}


void blithero(Hero H,SDL_Surface *screen)
{

  if (H.vie!=0)
  SDL_BlitSurface(H.personnage,&H.poshero,screen,&H.posimage);

}


void animateheroR(Hero *H)
{
H->poshero.x+=Hero_WIDTH;
H->poshero.x=H->poshero.x % (Hero_WIDTH *4);
H->poshero.y=0;
}


void animateheroL(Hero *H)
{
H->poshero.x+=Hero_WIDTH;
H->poshero.x=H->poshero.x % (Hero_WIDTH *4);
H->poshero.y=Hero_HEIGHT;
}



void MoveheroR(Hero *H,Background *back)
{

H->posimage.x+=25;

}


void MoveheroL(Hero *H,Background *back)
{

H->posimage.x-=25;

}



void free_Hero(Hero *H)
{

 SDL_FreeSurface(H->personnage);

}