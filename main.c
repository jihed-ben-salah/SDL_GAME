#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "fonction.h"

int main(void)
{   enigme_s E;
    SDL_Surface *screen,boutton1,boutton2,boutton3;
    SDL_Surface  *background;
    SDL_Surface  *faux,*vrai;
    SDL_Surface  *enigme;
    SDL_Surface *texte;
    SDL_Rect positionboutton1,positionboutton2,positionboutton3,positionenigme,posfaux,posvrai,position,postext;
 //pour texte:
  position.x=0;
  position.y=237; 
    SDL_Color couleurNoire= {0,0,0};
    SDL_Event event;
    TTF_Font *police = NULL;
 

    int  done=1,k=0,c=0;
  initialiser (&E);

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
    
      while (done==1)
    {

SDL_BlitSurface(texte, NULL, screen, &position);
SDL_Flip(screen);


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
		SDL_SetColorKey(faux,SDL_SRCCOLORKEY,SDL_MapRGB(faux->format,0,0,255));
		SDL_BlitSurface(faux,NULL,screen,&posfaux);
		break;
		case 2:
		vrai= IMG_Load("vrai.png");
		SDL_SetColorKey(vrai,SDL_SRCCOLORKEY,SDL_MapRGB(vrai->format,0,0,255));
		SDL_BlitSurface(vrai,NULL,screen,&posvrai);
		done=0; //remplacez done=0 par l'appel au fonction jouer au niveau d'integration
		break;
		}// fin switch c



 while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT :
            {
                done=0 ;
                break;
            }
            
            }
        }
    }
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    SDL_Quit();
    TTF_CloseFont(police);
    TTF_Quit();
    return 0;
}
