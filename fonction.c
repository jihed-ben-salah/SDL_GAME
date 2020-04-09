#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "fonction.h"


void initialiser (  enigme_s* E)
{
E->enigme=IMG_Load("enigme=IMG_Load");
E->boutton1=IMG_Load("bouton1.png");
E->boutton2= IMG_Load("bouton2.png");
E->boutton3= IMG_Load("bouton3.png");
}
void afficher(enigme_s *E,  SDL_Surface *screen)
{
E->positionenigme.x=0;
E->positionenigme.y=0;
E->positionboutton1.x=390;
E->positionboutton1.y=100;
E->positionboutton2.x=390;
E->positionboutton2.y=140;
E->positionboutton3.x=390;
E->positionboutton3.y=180;
SDL_BlitSurface(E->enigme,NULL,screen,&E->positionenigme);
SDL_BlitSurface(E->boutton1,NULL,screen,&E->positionboutton1);
SDL_BlitSurface(E->boutton2,NULL,screen,&E->positionboutton2);
SDL_BlitSurface(E->boutton3,NULL,screen,&E->positionboutton3);
SDL_Flip(screen);
}


int resolution ( enigme_s *e, SDL_Surface *screen, SDL_Event event )
{ SDL_Surface *texte = NULL,boutton1,boutton2,boutton3,vrai,faux;
 enigme_s *E;
    SDL_Rect position,posfaux,posvrai;
     Mix_Chunk *son;
     int   k=0,c=0,done=1;
TTF_Font *police = NULL;
SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
// temps d'enigme
int tempsActuel = 0, tempsPrecedent = 0, compteur=12000;
char temps[20] = "";
TTF_Init();
police = TTF_OpenFont("Sketch.ttf", 38);
tempsActuel = SDL_GetTicks();
sprintf(temps, "Temps : %d", compteur);
texte = TTF_RenderText_Blended(police, temps, couleurNoire);
while(done)
//debut done
{ tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >= 100) /* Si 100 ms au moins se sont écoulées */

       {

           compteur -= 100; /* On rajoute 100 ms au compteur */

           sprintf(temps, "Temps : %d", compteur/1000); /* On écrit dans la chaîne "temps" le nouveau temps */

           SDL_FreeSurface(texte); /* On supprime la surface précédente */

           texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */

           tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
if (compteur==0)
return 0;
       }

SDL_BlitSurface(texte, NULL, screen, &position);
SDL_Flip(screen);


         SDL_Event event; 
         while(SDL_PollEvent(&event))
         {
          switch(event.type)
          {
	   case SDL_QUIT:
      		done=0;
           break;


	   case SDL_MOUSEMOTION:
		if(event.motion.x>=390 && event.motion.x<=400+68 && event.motion.y>=100 && event.motion.y<=110+31)
		k=1;
		else
		if(event.motion.x>=390 && event.motion.x<=400+68 && event.motion.y>=140 && event.motion.y<=150+31)
		k=2;
		else
		if(event.motion.x>=390 && event.motion.x<=400+68 && event.motion.y>=180 && event.motion.y<=190+31)
		k=3;
	   break;
	   case SDL_MOUSEBUTTONUP:
		if((event.button.button==SDL_BUTTON_LEFT) && (event.motion.x>=390 && event.motion.x<=400+68 && event.motion.y>=100 && event.motion.y<=110+31))
		{c=1;
		Mix_PlayChannel(-1, son, 0);
		}
		else
		if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=390 && event.motion.x<=400+68 && event.motion.y>=140 && event.motion.y<=150+31))
		{c=2;
		Mix_PlayChannel(-1, son, 0);}
		else
		if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=390 && event.motion.x<=400+68 && event.motion.y>=180 && event.motion.y<=190+31))
		{c=1;
		Mix_PlayChannel(-1, son, 0);}
	   break;
	  }//fin switch event
	}//fin while poll event
}//fin done
return k;
}
//////////////////deplacement///////////////////
void deplacement ( SDL_Event event ,hero h)
{

int done=1;
SDL_Surface *image,*persd[4],*persg[4],*persinit,*screen;
SDL_Rect positionpers,positionimage;
int x=0,p=0,i=0,j=0,a, q, r;
while(done)
{
SDL_Event event;
switch(x)
{
case 0:
SDL_BlitSurface(image,NULL,screen,&positionimage);
SDL_BlitSurface(persinit,NULL,screen,&positionpers);
break;
case 1:
SDL_BlitSurface(image,NULL,screen,&positionimage);
SDL_BlitSurface(persd[i],NULL,screen,&positionpers);

q = (a-positionpers.x);
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

/* int col_trigo(SDL_Rect *hero, SDL_Rect *entite)
{
	int rh,re,xh,xe,yh,ye,distance;

	rh = (heros->w)/2;
	xh = (heros->x + (heros->w/2));
	yh = (heros->y + (heros->h/2));

	re = (entite->w)/2;
	xe = (entite->x + (entite->w/2));
	ye = (entite->y + (entite->h/2));

	distance = sqrt(pow(xe - xh, 2) + pow(ye - yh, 2));

	return (distance <= (ra + rb));
}*/

}

