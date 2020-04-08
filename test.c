#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "test.h"
//background
void initialiser_Background(background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
}
void afficher_background(background *Backg,SDL_Surface *screen)
{Backg->backgroundImg = SDL_LoadBMP("background.bmp");
	
SDL_BlitSurface(Backg->backgroundImg,NULL,screen,&(Backg->backgroundPos));
SDL_FreeSurface(Backg->backgroundImg);
}
//entitee secondaire
void initialiser_entite_secondaire (entite_sc *E )
{

 E->img=NULL;

 E->pos.x=700;
 E->pos.y=100;

}



void afficher_entite_secondaire (SDL_Surface * screen ,entite_sc *E)
{

 E->img=IMG_Load("img.png");

 SDL_BlitSurface(E->img,NULL,screen,&(E->pos)) ;
 SDL_Flip(screen);

}
//collision
SDL_Color getRGB(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}
int colbackgroundleft(SDL_Surface* Backgroundmasque,SDL_Rect positionhero1)
{
    int x1,y1;
    int x2,y2;
    int x3,y3;

    x1=positionhero1.x+10;
    y1=positionhero1.y;

    x2=positionhero1.x+20;
    y2=positionhero1.y+positionhero1.h/2;

    x3=positionhero1.x+10;
    y3=positionhero1.y+positionhero1.h;

    SDL_Color color1=getRGB(Backgroundmasque,x1,y1);
    SDL_Color color2=getRGB(Backgroundmasque,x2,y2);
    SDL_Color color3=getRGB(Backgroundmasque,x3,y3);

    if((color1.r==0 && color1.g==0 && color1.b==0)||(color2.r==0 && color2.g==0 && color2.b==0)||(color3.r==0 && color3.g==0 && color3.b==0))
       return(1);
   
        return(0);
}
int colbackgroundRight(SDL_Surface* Backgroundmasque,SDL_Rect positionhero1)
{
    int x1,y1;
    int x2,y2;
    int x3,y3;

    x1=positionhero1.x+positionhero1.w+20;
    y1=positionhero1.y;

    x2=positionhero1.x+positionhero1.w-20;
    y2=positionhero1.y+positionhero1.h/2;

    x3=positionhero1.x+positionhero1.w+20;
    y3=positionhero1.y+positionhero1.h;

    SDL_Color color1=getRGB(Backgroundmasque,x1,y1);
    SDL_Color color2=getRGB(Backgroundmasque,x2,y2);
    SDL_Color color3=getRGB(Backgroundmasque,x3,y3);

    if((color1.r==0 && color1.g==0 && color1.b==0)||(color2.r==0 && color2.g==0 && color2.b==0)||(color3.r==0 && color3.g==0 && color3.b==0))
        return(1);
   
        return(0);
}

int colbackgroundDown(SDL_Surface* Backgroundmasque,SDL_Rect positionhero1)
{
    int x1,y1;
    int x2,y2;
    int x3,y3;

    x1=positionhero1.x;
    y1=positionhero1.y+positionhero1.h+8;

    x2=positionhero1.x+positionhero1.w/2;
    y2=positionhero1.y+positionhero1.h+8;

    x3=positionhero1.x+positionhero1.w;
    y3=positionhero1.y+positionhero1.h+8;

     SDL_Color color1=getRGB(Backgroundmasque,x1,y1);
    SDL_Color color2=getRGB(Backgroundmasque,x2,y2);
    SDL_Color color3=getRGB(Backgroundmasque,x3,y3);

    if((color1.r==0 && color1.g==0 && color1.b==0)||(color2.r==0 && color2.g==0 && color2.b==0)||(color3.r==0 && color3.g==0 && color3.b==0))
        return(1);
   
        return(0);
}
int colbackgroundUp(SDL_Surface* Backgroundmasque,SDL_Rect positionhero1)
{
    int x1,y1;
    int x2,y2;
    int x3,y3;

    x1=positionhero1.x;
    y1=positionhero1.y+10;

    x2=positionhero1.x+positionhero1.w/2;
    y2=positionhero1.y+40;

    x3=positionhero1.x+positionhero1.w;
    y3=positionhero1.y+10;

      SDL_Color color1=getRGB(Backgroundmasque,x1,y1);
      SDL_Color color2=getRGB(Backgroundmasque,x2,y2);
      SDL_Color color3=getRGB(Backgroundmasque,x3,y3);

    if((color1.r==0 && color1.g==0 && color1.b==0)||(color2.r==0 && color2.g==0 && color2.b==0)||(color3.r==0 && color3.g==0 && color3.b==0))
        return(1);
        return(0);
}
