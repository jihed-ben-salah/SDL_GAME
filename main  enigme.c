
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "enigme.h"
#include "SDL/SDL_ttf.h"
int main(void)
{
    int enigme=0,valeur;
    enigme_sf E;
    E.pos[16].x=200;
    E.pos[16].y=200;
    int y;
    int i=0;
 int tempsActuel = 0, tempsPrecedent = 0, compteur = 6000;
int verif=0;
   char temps[20] = "";

SDL_Surface *textetemps = NULL;
SDL_Rect positiontemps;
tempsActuel = SDL_GetTicks();
 sprintf(temps, "Temps : %d", compteur);

    SDL_Surface *screen,*background,*photo, *defeat, *victory;
    SDL_Surface *screenenigme;
    SDL_Surface *texte;

    int done=1,a,b,f=0;
    SDL_Rect positionbackground,positionphoto,positiondefeat,positionvictory;
    aleatoire (&E);
    SDL_Rect positiontexte;
SDL_Color  couleurBlanche = {255, 255, 255};
    SDL_Color couleurNoire= {0,0,0};
    SDL_Event event,event2;
    TTF_Font *police ,*policetemps= NULL;
    char pause;
positiontemps.x=300;
positiontemps.y=300;




    TTF_Init();
    police = TTF_OpenFont("Sketch.ttf",30);
 policetemps = TTF_OpenFont("Sketch.ttf",100);
    texte = TTF_RenderText_Blended(police, "Cliquez de 1 à 15 en ordre le plus rapidement possible!!", 	couleurNoire);
textetemps = TTF_RenderText_Blended(policetemps, temps, couleurNoire);
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }


    positiontexte.x = 100;
    positiontexte.y = 450;

    initialiser(&E);
    screen=SDL_SetVideoMode(1280,500,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
    photo=IMG_Load("enigme.jpg");
    if(photo==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }
    victory=IMG_Load("victory.png");
    if(victory==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }
    defeat=IMG_Load("defeat.png");
    if(defeat==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }
    positionvictory.x=200;
    positionvictory.y=0;
    positiondefeat.x=300;
    positiondefeat.y=0;
    positionphoto.x=0;
    positionphoto.y=0;
    positionphoto.w=photo->w;
    background=IMG_Load("background.jpg");
    if(background==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }


    positionbackground.x=0;
    positionbackground.y=0;
    positionbackground.w=background->w;













    while (done==1)
    {
// TEMPS
tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >= 100) /* Si 100 ms au moins se sont écoulées */

       {

           compteur -= 100; /* On rajoute 100 ms au compteur */

           sprintf(temps, " %d", compteur/1000); /* On écrit dans la chaîne "temps" le nouveau temps */

           SDL_FreeSurface(textetemps); /* On supprime la surface précédente */

           textetemps = TTF_RenderText_Shaded(policetemps, temps, couleurNoire, couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */

           tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
if (compteur==0)
verif=1;

       }




        aleatoire (&E);
        SDL_BlitSurface(background, NULL,screen,&positionbackground);
        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
SDL_BlitSurface(textetemps, NULL, screen, &positiontemps);
        SDL_Flip(screen);
     
 if (verif==1)
                {
                    screenenigme=SDL_SetVideoMode(1280,500,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
                    if(screenenigme==NULL)
                    {
                        printf("Unable to set video mode : %s",SDL_GetError());
                        return 1;
                    }
                    valeur=resolution(E,screenenigme,event2,photo,positionphoto);
                    if (valeur==1)
                    {
                        SDL_BlitSurface(victory, NULL,screen,&positionvictory);
                        SDL_Flip(screenenigme);
                        SDL_Delay(3000);
                    }
                    else if (valeur==0)
                    {
                        SDL_BlitSurface(defeat, NULL,screen,&positiondefeat);
                        SDL_Flip(screenenigme);
                        SDL_Delay(3000);
                    }
               compteur=6000; 
               verif=0;
//Enlever ici pour limplementation
//done =0;

}
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
    pause=getchar();
    TTF_CloseFont(police);
    TTF_Quit();
    return 0;
}

