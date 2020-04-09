#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include<SDL/SDL_mixer.h>
int main(void)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());}
SDL_Surface *screen;
SDL_Surface *image,*persd[4],*persg[4],*persinit;
SDL_Rect positionpers,positionimage;
//initialise sdl
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable to inizialize SDL: %s \n",SDL_GetError());
return 1;
}//creation de la fenetre
screen=SDL_SetVideoMode(1433,667,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("Unable to set video mode : %s" ,SDL_GetError());
return 1;
}
//ajout de l'image
image=IMG_Load("background.png");
if(image==NULL)
{printf("Unable to load image: %s\n",SDL_GetError());
return 1;
}
persinit = IMG_Load("position_choix.png");// position initiale du personnage
    // animation deplacement personnage a droite
    persd[0] = IMG_Load("position_droit1.png");
    persd[1] = IMG_Load("position_droit2.png");
    persd[2] = IMG_Load("position_droit3.png");
    persd[3] = IMG_Load("position_droit5.png");



    // animation deplacement personnage a gauche    
    persg[0] = IMG_Load("position_gauche1.png");
    persg[1] = IMG_Load("position_gauche2.png");
    persg[2] = IMG_Load("position_gauche3.png");
    persg[3] = IMG_Load("position_gauche4.png");

//position fond
positionimage.x=0;
positionimage.y=0;
positionpers.x=300;
positionpers.y=500;
//SDL_BlitSurface(image,NULL,screen,&positionimage);
//SDL_BlitSurface(persinit,NULL,screen,&positionpers);


int done=1;
int x=0,p=0,i=0,j=0,a, q, r;
while(done)
{SDL_Event event;
switch(x)
{
case 0:
SDL_BlitSurface(image,NULL,screen,&positionimage);
SDL_BlitSurface(persinit,NULL,screen,&positionpers);
break;
case 1:
SDL_BlitSurface(image,NULL,screen,&positionimage);
SDL_BlitSurface(persd[i],NULL,screen,&positionpers);

q = a-positionpers.x;
r = (a-positionpers.x)%10;


if (q>=10)
    positionpers.x+=10;
else
    positionpers.x+=r;

SDL_Delay(30);
i++;
if(i==3)
i=0;
break;
case 2:
SDL_BlitSurface(image,NULL,screen,&positionimage);
SDL_BlitSurface(persg[j],NULL,screen,&positionpers);
q = a-positionpers.x;
r = (a-positionpers.x)%10;


if (q>=10)
    positionpers.x+=10;
else
    positionpers.x+=r;
positionpers.x--;


SDL_Delay(30);
j++;
if(j==3)
j=0;
break;
}//switch x
if(p==1)
{
      if(a>positionpers.x)

          x=1;

      else
           if(a<positionpers.x)
                x=2;
             
             if(a==positionpers.x)
             {
                p=0;
                x=0;
             }
}

                     while(SDL_PollEvent(&event))
                      {switch(event.type)
                            {
                            case SDL_QUIT:
                            {
                               done=0;
                               break;
                            }
                            case SDL_MOUSEBUTTONUP:
                            {
                                if((event.button.button==SDL_BUTTON_LEFT))    
                            {  
                                      a=event.button.x;
     p=1;
                                }                                    
                                break;
                             }

   }//fin switch event
     }//fin while poll


SDL_Flip(screen);
}//fin done
SDL_FreeSurface(screen);
SDL_FreeSurface(image);
SDL_FreeSurface(persg[3]);
SDL_FreeSurface(persd[3]);
SDL_FreeSurface(persinit);
SDL_Quit();
return 0;
}

