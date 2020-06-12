#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "hero_deux.h"


void loadhero_deux(hero_deux *H)
{

H->personnagehero_deux=IMG_Load("1.png");

if(H->personnagehero_deux==NULL)
    {
        printf("Unable to load on H->personnage: %s\n",SDL_GetError());
        
    }


}


void initialiser_hero_deux(hero_deux *H)
{

H->posimagehero_deux.x=150;
H->posimagehero_deux.y=460;
H->posimagehero_deux.w=hero_deux_WIDTH;
H->posimagehero_deux.h=hero_deux_HEIGHT;

H->poshero_deux.x=0;
H->poshero_deux.y=0;
H->poshero_deux.w=hero_deux_WIDTH;
H->poshero_deux.h=hero_deux_HEIGHT;

H->viehero_deux=100;

}


void blithero_deux(hero_deux H,SDL_Surface *screen)
{

  SDL_BlitSurface(H.personnagehero_deux,&H.poshero_deux,screen,&H.posimagehero_deux);

}


void animateheroD(hero_deux *H)
{
H->poshero_deux.x+=hero_deux_WIDTH;
H->poshero_deux.x=H->poshero_deux.x % (hero_deux_WIDTH *6);
H->poshero_deux.y=0;
}


void animateheroG(hero_deux *H)
{
H->poshero_deux.x+=hero_deux_WIDTH;
H->poshero_deux.x=H->poshero_deux.x % (hero_deux_WIDTH *6);
H->poshero_deux.y=hero_deux_HEIGHT;
}


void MoveheroD(hero_deux *H)
{

H->posimagehero_deux.x+=20;

}


void MoveheroG(hero_deux *H)
{

H->posimagehero_deux.x-=20;

}


void free_hero_deux(hero_deux *H)
{

 SDL_FreeSurface(H->personnagehero_deux);

}


