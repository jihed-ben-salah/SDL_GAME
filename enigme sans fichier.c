#include<stdio.h>
#include<time.h>
#include"SDL/SDL.h"
#include"enigme.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_ttf.h>


void initialiser (  enigme_sf * E)
{
E->image[0]=IMG_Load("1a15/1.png");
E->image[1]=IMG_Load("1a15/2.png");
E->image[2]=IMG_Load("1a15/3.png");
E->image[3]=IMG_Load("1a15/4.png");
E->image[4]=IMG_Load("1a15/5.png");
E->image[5]=IMG_Load("1a15/6.png");
E->image[6]=IMG_Load("1a15/7.png");
E->image[7]=IMG_Load("1a15/8.png");
E->image[8]=IMG_Load("1a15/9.png");
E->image[9]=IMG_Load("1a15/10.png");
E->image[10]=IMG_Load("1a15/11.png");
E->image[11]=IMG_Load("1a15/12.png");
E->image[12]=IMG_Load("1a15/13.png");
E->image[13]=IMG_Load("1a15/14.png");
E->image[14]=IMG_Load("1a15/15.png");
}

void aleatoire ( enigme_sf *E)
{
time_t t;
   int a;
   srand((unsigned) time(&t));

for ( a=0;a<15;a++)
{
E->pos_x[a]=rand()%1000;
}
for ( a=0;a<15;a++)
{
E->pos_y[a]=rand()%400;
}
for(a=0;a<15;a++)
{
E->pos[a].x=E->pos_x[a];
E->pos[a].y=E->pos_y[a];

}
}

void afficher(enigme_sf *E,  SDL_Surface *screen,int i)
{
  int y;

for (y=i;y<15;y++)
{
SDL_BlitSurface(E->image[y],NULL,screen,&E->pos[y]);
}

}



int resolution ( enigme_sf E, SDL_Surface * screen, SDL_Event P,SDL_Surface *image,SDL_Rect positionbackground)
{  SDL_Surface *texte = NULL;
SDL_Rect position;
TTF_Font *police = NULL;
SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
int continuer = 1;

   int tempsActuel = 0, tempsPrecedent = 0, compteur = 16000;

   char temps[20] = "";
   TTF_Init();
int y,a,b,i=0,f=0;
police = TTF_OpenFont("Sketch.ttf", 65);
tempsActuel = SDL_GetTicks();
 sprintf(temps, "Temps : %d", compteur);
 texte = TTF_RenderText_Blended(police, temps, couleurNoire);
  // texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche);
while (f==0)
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

SDL_BlitSurface(image,NULL,screen,&positionbackground);
position.x = 0;

       position.y = 0;

       
for ( y=i;y<15;y++)
{
SDL_BlitSurface(E.image[y],NULL,screen,&E.pos[y]);
}
SDL_BlitSurface(texte, NULL, screen, &position);
SDL_Flip(screen);

 while(SDL_PollEvent(&P))
        {
            switch (P.type)
            {	
            case SDL_QUIT :
            {
                f=1 ;
                break;
            }
case SDL_MOUSEBUTTONDOWN:
            {
a=P.button.x;
b=P.button.y;
if(i!=15){
if ( a>E.pos[i].x && a<E.pos[i].x+200 && b>E.pos[i].y && b<E.pos[i].y+200)
{i++;}
else return 0;
if (i==15)
return 1;
}
break;}}}}
return 0;
}


































































































