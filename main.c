#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "personnage.h"
#include "collision.h"
int main(void)
{

    hero fadhel;
    background Back;

    int j;
    char pause ;
    SDL_Surface *screen;

    SDL_Surface *sprite;

    int verif=0;
    SDL_Event event;
    int x,y;
    int w,h;
    SDL_Surface *BackMasque;
    SDL_Rect backgroundPosM;


//masque
    BackMasque=IMG_Load("backgroundf.png");
    if (BackMasque == NULL)
    {
        printf("Unable to load this bitmap: %s\n", SDL_GetError());

    }
    backgroundPosM.x=0;
    backgroundPosM.y=0;
    
    // background
    Back.b[0]=0;
    Back.b[1]=0;
       Back.x=0;
    Back.y=0;
    Back.camera.x=0;
    Back.camera.y=0;
    Back.camera.w=800;
    Back.camera.h=736;
       
 
    initialiser_Background(&Back);
    initialiser_hero(&fadhel);
 
    if(Back.backgroundImg==NULL)
    {
        printf("Unable to load that bitmap: %s\n",SDL_GetError());

    }
// ouverture fenetre
    
    screen=SDL_SetVideoMode(800,736,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }



//Blit


    int done=1;
    SDL_EnableKeyRepeat(30,0);

    while (done)

    {

        afficher_background(&Back,screen);
        Afficher (fadhel,screen);

        verif=Animation_hero(&fadhel,screen,&Back,BackMasque);
        if (verif == 1)
            done=0;



        SDL_Flip(screen);
/*
SDL_FreeSurface(h->sprite_left);
SDL_FreeSurface(sprite);
SDL_FreeSurface(Back.backgroundImg);
*/

    }

//liberer les surfaces
    SDL_FreeSurface(BackMasque);
    SDL_FreeSurface(Back.backgroundImg);
    SDL_FreeSurface(sprite);
    SDL_Delay(10);
    SDL_Quit();
    pause=getchar();


    return 0;

}


