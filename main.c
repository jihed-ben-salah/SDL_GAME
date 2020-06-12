#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "hero.h"
#include "background.h"


int main(void)
{
int c;
int done=1;
int b[2]={0,0};
Hero H1;
Hero H2;
background Back;
background Back2;
// Declaration

SDL_Surface *screen;


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


loadHero(&H1,"Entite2.png");
loadHero(&H2,"Entite2.png");
initialiser_hero(&H1,1);
initialiser_hero(&H2,2);


loadBackground(&Back);
initialiser_Background(&Back);
loadBackground(&Back2);
initialiser_Background(&Back2);



SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

while(done)

{
blitbackground(&Back,screen);
blitbackground2(&Back2,screen);

blithero(H1,screen);
blithero(H2,screen);

SDL_Event event;

while(SDL_PollEvent(&event))
{switch(event.type)
  {


case SDL_QUIT:
  {done=0;
   break;}


case SDL_KEYDOWN:
{
  

if(event.key.keysym.sym==SDLK_ESCAPE)
{ done=0;
      break;}
else if(event.key.keysym.sym==SDLK_RIGHT)
{
b[0]=1;
if(H1.posimage.x<250)
	MoveheroR(&H1);
else
	scrolling(&Back,b,1);

}
else if(event.key.keysym.sym==SDLK_LEFT)
{
b[1]=1;
if(H1.posimage.x>0)
	MoveheroL(&H1);
else
	scrolling(&Back,b,1);
}
else if(event.key.keysym.sym==SDLK_d)
{
b[0]=1;
if(H2.posimage.x<750)
	MoveheroR(&H2);
else 
	scrolling(&Back2,b,2);
}
else if(event.key.keysym.sym==SDLK_q)
{
b[1]=1;
if(H2.posimage.x>500)
	MoveheroL(&H2);
else 
	scrolling(&Back2,b,2);
}
}
case SDL_KEYUP:
{

if(event.key.keysym.sym==SDLK_ESCAPE)
{ done=0;
      break;}
else if(event.key.keysym.sym==SDLK_RIGHT)
{
b[0]=0;
if(H1.posimage.x<250)
	MoveheroR(&H1);
else
	scrolling(&Back,b,1);
}
else if(event.key.keysym.sym==SDLK_LEFT)
{
b[1]=0;
if(H1.posimage.x>0)
	MoveheroL(&H1);
else 
	scrolling(&Back,b,1);
}
else if(event.key.keysym.sym==SDLK_d)
{
b[0]=0;
if(H2.posimage.x<750)
	MoveheroR(&H2);
else 
	scrolling(&Back2,b,2);
}
else if(event.key.keysym.sym==SDLK_q)
{
b[1]=0;
if(H2.posimage.x>500)
	MoveheroL(&H2);
else 
	scrolling(&Back2,b,2);
}
}


}


SDL_Flip(screen);

}
}


// Liberation memoire



SDL_Quit();
SDL_Delay(10);

return 0;

}
