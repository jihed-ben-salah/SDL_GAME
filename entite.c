/**
* @file entite.c
* @brief Tester programme
* @author Bechir Mennai
* @version 1.0
* @date Juin 01, 2020
*
* Development des fonctions
*
*/

#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"entite.h"


/**
* @brief initialiser entite e.
* @param e l'entite secondaire
* @param x position entite
* @param y position entite
* @return Rien
*/

void Entite_Init(entite_sc *e,int x, int y){
	
        e->img1 = IMG_Load("Img.png");
	e->img2 = IMG_Load("Img2.png");
        
        e->pos.x=x;
        e->pos.y=y;
	
        e->dx = 100;
	e->cx = 100;
}


/**
* @brief Deplacer l'entite e.
* @param e l'entite secondaire
* @param screen the screen
* @return Rien
*/

void deplacement_aleatoire (entite_sc *e, SDL_Surface **screen) {
	
       SDL_Rect r2 = {e->pos.x, e->pos.y};
	
        if(e->dx){
		e->pos.x += 8;
		SDL_BlitSurface(e->img2,NULL,*screen, &r2);
	}
        
        else{
		SDL_BlitSurface(e->img1,NULL,*screen, &r2);
		e->pos.x -= 8;

	}

	e->cx++;
	if(e->cx % 80 == 0)
		e->dx = !e->dx;
       

}


