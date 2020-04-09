#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "time.h"
#include "fonction.h"

int main(void)
{


// Declaration POUR ENIGME :

SDL_Surface *screen=NULL,*enigme=NULL,*boutton1=NULL,*boutton2=NULL,*boutton3=NULL,*faux=NULL,*vrai=NULL;
SDL_Rect positionboutton1,positionboutton2,positionboutton3,positionenigme,posfaux,posvrai,position,postext;
Mix_Music *music;
Mix_Chunk *son;
SDL_Event event;
enigme_s e;

//DECLARATION POUR DEPLACEMENT PERSONNAGE 

SDL_Surface *image,*persd[4],*persg[4],*persinit;
SDL_Rect positionpers,positionimage;
char pause;
int done=1;

if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }


// Creation screen

screen=SDL_SetVideoMode(1280,640,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }

//music

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());}


music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);



//son bref
son = Mix_LoadWAV("scream.wav");


if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
  printf("Unable to inizialize SDL: %s \n",SDL_GetError());
  return 1;
}
 screen=SDL_SetVideoMode(1084,1084,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
    
  enigme=IMG_Load("enigme.png");
    if(enigme==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }  
positionenigme.x=0;
positionenigme.y=0;

   faux= IMG_Load("faux.png");
    if(faux==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }

    posfaux.x=5;
    posfaux.y=5;

    vrai= IMG_Load("vrai.png");
    if(vrai==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }
   posvrai.x=5;
   posvrai.y=5;

    initialiser( &e );

    if(e.enigme==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
       
    }
SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

while(done)

{ int k,c;
k=resolution(&e,screen,event );
// blit
		switch(k)
		{
		case 0:
		    {
		boutton1= IMG_Load("boutoni1.png");
		SDL_BlitSurface(boutton1,NULL,screen,&positionboutton1);
		boutton2= IMG_Load("boutoni2.png");
		SDL_BlitSurface(boutton2,NULL,screen,&positionboutton2);
		boutton3= IMG_Load("boutoni3.png");
		SDL_BlitSurface(boutton3,NULL,screen,&positionboutton3);
		break;
		    }
		case 1:
		    {
		boutton1= IMG_Load("bouton1.png");
		SDL_BlitSurface(boutton1,NULL,screen,&positionboutton1);
		boutton2= IMG_Load("boutoni2.png");
		SDL_BlitSurface(boutton2,NULL,screen,&positionboutton2);
		boutton3= IMG_Load("boutoni3.png");
		SDL_BlitSurface(boutton3,NULL,screen,&positionboutton3);
		break;
		    } 			
		case 2:
		    {
		boutton1= IMG_Load("boutoni1.png");
		SDL_BlitSurface(boutton1,NULL,screen,&positionboutton1);
		boutton2= IMG_Load("bouton2.png");
		SDL_BlitSurface(boutton2,NULL,screen,&positionboutton2);
		boutton3= IMG_Load("boutoni3.png");
		SDL_BlitSurface(boutton3,NULL,screen,&positionboutton3);
		break;
		    }
		case 3:
		    { 
		boutton1= IMG_Load("boutoni1.png");
		SDL_BlitSurface(boutton1,NULL,screen,&positionboutton1);
		boutton2= IMG_Load("boutoni2.png");
		SDL_BlitSurface(boutton2,NULL,screen,&positionboutton2);
		boutton3= IMG_Load("bouton3.png");
		SDL_BlitSurface(boutton3,NULL,screen,&positionboutton3);
		break;
		     }
		}//fin switch k
		switch(c)
		{
		case 1:
		faux= IMG_Load("faux.png");
		SDL_BlitSurface(faux,NULL,screen,&posfaux);
		break;
		case 2:
		vrai= IMG_Load("vrai.png");
		SDL_BlitSurface(vrai,NULL,screen,&posvrai);
		done=0; //remplacez done=0 par l'appel au fonction jouer au niveau d'integration
		break;
		}// fin switch c

SDL_BlitSurface(enigme,NULL,screen,&positionenigme);
afficher(&e,screen);
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




SDL_Flip(screen);

}
}
}
}
//////////////DEPLACEMENT/////////////
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
// Liberation memoire


SDL_FreeSurface(enigme);
Mix_FreeMusic(music);
SDL_Quit();
SDL_Delay(10);
pause=getchar();

return 0;

}
