/**
* @file test.c
* @brief Tester programme
* @author Bechir Mennai
* @version 1.0
* @date Juin 01, 2020
*
* Development des fonctions
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "time.h"
#include "test.h"


/**
* @brief initialiser entite E.
* @param E l'entite secondaire
* @return Rien
*/

void initialiser_entite_secondaire ( entite_sc *E )
{

 E->img=NULL;

 E->pos.x=100;
 E->pos.y=100;

}


/**
* @brief Afficher entite E
* @param screen the screen
* @param E entite
* @return Rien
*/

void afficher_entite_secondaire ( SDL_Surface * screen , entite_sc *e )
{

 e->img=IMG_Load("img.png");

 SDL_BlitSurface(e->img,NULL,screen,&(e->pos)) ;
 SDL_Flip(screen);

}


/**
* @brief Deplacer l'entite e.
* @param E l'entite secondaire
* @param b position
* @return Rien
*/

int collision( entite_sc E, SDL_Rect b)

{
	if(!(E.pos.x > b.x+b.w || E.pos.y > b.y+b.h || E.pos.x+E.pos.w < b.x || E.pos.y+E.pos.h < b.y)){
	return 1;
}

	return 0;
}


