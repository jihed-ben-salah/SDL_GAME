#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "test.h"
int main(void)
{
SDL_Surface *screen;
SDL_Surface *BackMasque;
  
SDL_Rect backgroundPosM;
SDL_Rect positionecran;

entite_sc E;
background Backg;

int done=1;
char pause;
int col1,col2,col3,col4;
SDL_Event event;
if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }


// Creation screen

screen=SDL_SetVideoMode(1100,619,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
//background
initialiser_Background(&Backg);
if(Backg.backgroundImg==NULL)
{
        printf("Unable to load bitmap: %s\n",SDL_GetError());
       
}
//masque
BackMasque=SDL_LoadBMP("backMasque.bmp");
	if (BackMasque == NULL)
        {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}
backgroundPosM.x=0;
backgroundPosM.y=0;
//entite secondaire
initialiser_entite_secondaire(&E);
if(E.img==NULL)
{
        printf("Unable to load bitmap: %s\n",SDL_GetError());
       
}

while(done)
{
afficher_background(&Backg,screen);
//SDL_BlitSurface(BackMasque,NULL,screen,&(backgroundPosM));
afficher_entite_secondaire (screen,&E);
/*col1=colbachgroundleft(BackMasque,E.pos);
col2=colbachgroundRight(BackMasque,E.pos);
col3=colbachgroundDown(BackMasque,E.pos);
col4=colbachgroundUp(BackMasque,E.pos);*/
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
 {   E.pos.x+=20;  }


else if(event.key.keysym.sym==SDLK_LEFT)
 {   E.pos.x-=20; }

else if(event.key.keysym.sym==SDLK_DOWN)
 {   E.pos.y+=20; }


else if(event.key.keysym.sym==SDLK_UP)
 {  E.pos.y-=20; }

}
if(colbackgroundleft(BackMasque,E.pos))
{E.pos.x+=100;}
else if(colbackgroundRight(BackMasque,E.pos))
{E.pos.x-=100;}
else if(colbackgroundDown(BackMasque,E.pos))
{E.pos.y-=100;}
else if(colbackgroundUp(BackMasque,E.pos))
{E.pos.y+=100;}
}

}
}
SDL_FreeSurface(BackMasque);
SDL_Quit();
pause=getchar();

return 0;
}

