
#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "hero.h"
void loadHero(Hero *H,char *c)
{

H->personnage=IMG_Load(c);
if(H->personnage==NULL)
    {
        printf("Unable to load on H->personnage: %s\n",SDL_GetError());
        
    }
}

void initialiser_hero(Hero *H,int i)
{
if(i==1)
{
H->posimage.x=0;
H->posimage.y=745 - (H->personnage->h);
H->posimage.w=Hero_WIDTH;
H->posimage.h=Hero_HEIGHT;
H->poshero.x=0;
H->poshero.y=0;
H->poshero.w=Hero_WIDTH;
H->poshero.h=Hero_HEIGHT;
H->vie=5;
H->direction=0;
}
else 
{
H->posimage.x=SCREEN_W/2;
H->posimage.y=745 - (H->personnage->h);
H->posimage.w=Hero_WIDTH;
H->posimage.h=Hero_HEIGHT;
H->poshero.x=0;
H->poshero.y=0;
H->poshero.w=Hero_WIDTH;
H->poshero.h=Hero_HEIGHT;
H->vie=5;
H->direction=0;
}
}
void blithero(Hero H,SDL_Surface *screen)
{

  SDL_BlitSurface(H.personnage,&H.poshero,screen,&H.posimage);

}

void animateheroR(Hero *H)
{H->poshero.x+=Hero_WIDTH;
H->poshero.x=H->poshero.x % (Hero_WIDTH *6);
H->poshero.y=0;
}
void animateheroL(Hero *H)
{H->poshero.x+=Hero_WIDTH;
H->poshero.x=H->poshero.x % (Hero_WIDTH *6);
H->poshero.y=Hero_HEIGHT;
}
void MoveheroR(Hero *H)
{H->posimage.x+=10;
H->direction=1;
}
void MoveheroL(Hero *H)
{
H->posimage.x-=10;
H->direction=-1;
}
void free_Hero(Hero *H)
{

 SDL_FreeSurface(H->personnage);

}

