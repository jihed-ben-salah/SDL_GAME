#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "test.h"
int main(void)
{
SDL_Surface *screen; 
SDL_Rect positionecran;
SDL_Rect camera;
background Backg;
int done=1;
char pause;
int x,y;
x=0;
y=0;
camera.x=0;
camera.y=0;
camera.w=640;
camera.h=480;
int b[2]={0,0};
const int speed=1;
SDL_Event event;
if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }


//Creation screen

screen=SDL_SetVideoMode(640,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }

//background
initialiser_Background(&Backg);
Backg.backgroundImg = SDL_LoadBMP("background.bmp");
if(Backg.backgroundImg==NULL)
{
        printf("Unable to load bitmap: %s\n",SDL_GetError());
       
}
while(done)
{
SDL_BlitSurface(Backg.backgroundImg,&camera,screen,NULL);
SDL_Flip(screen);
  while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT :
            {
                done=0 ;
                break;
            }
case SDL_KEYDOWN:
{
  

if(event.key.keysym.sym==SDLK_ESCAPE)
{ done=0;
break;}
else if(event.key.keysym.sym==SDLK_RIGHT)
 {   b[0]=1;
  
break;  }


else if(event.key.keysym.sym==SDLK_LEFT)
 {   b[1]=1;

break; }

}
case SDL_KEYUP:
if(event.key.keysym.sym==SDLK_RIGHT)
 {   b[0]=0;

break;  }


else if(event.key.keysym.sym==SDLK_LEFT)
 {   b[1]=0;

break; }
}
}
if(b[0])
{x+=speed;
camera.x+=speed;
if(camera.x>=3000-640)
camera.x=0;}
else if(b[1])
{x-=speed;
camera.x-=speed;
if(camera.x<=0)
camera.x=3000-640;
}
}
SDL_Quit();
pause=getchar();

return 0;
}

