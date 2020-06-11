/**
* @file ennemi.c
* @brief Tester programme
* @author Bechir Mennai
* @version 1.0
* @date Juin 01, 2020
*
* Development des fonctions
*
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"


/**
* @brief Load Ennemi E
* @param E l'ennemi
* @return Rien
*/


void Load_ennemi(Ennemi* E)
{

E->image=IMG_Load("ennemi.png");

if(E->image==NULL)
{
printf("Unable to load on E->image: %s\n",SDL_GetError());        
}


}

/**
* @brief initialiser Ennemi E.
* @param E l'ennemi
* @param min position minimal
* @param max position maximal
* @return Rien
*/


void initialiserennemi(Ennemi* E,int max,int min)
{

// Deplacement
E->positionAbsolue.x=max;
E->positionAbsolue.y=385;

// Sprite
E->pos_ennemi.x=0;
E->pos_ennemi.y=Ennemi_HEIGHT;

E->pos_ennemi.w=Ennemi_WIDTH;
E->pos_ennemi.h=Ennemi_HEIGHT;

E->direction=1; //A gauche

E->pos_max=max;
E->pos_min=min;

}


/**
* @brief Deplacer l'ennemi E
* @param E l'ennemi
* @return Rien
*/

void Dep_Alea_Ennemi(Ennemi* E) 
{

animateEnnemi(E); 

moveEnnemi(E);

}

/**
* @brief Animation de l'ennemi E
* @param E l'ennemi
* @return Rien
*/


void animateEnnemi(Ennemi* E)
{ 

    if (E->direction==1)
    {
    // Animation ennemi a gauche
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=300;}
  
    else if (E->direction==2)
    {
    // Animation ennemi a droite
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=200;}   

}


/**
* @brief Mouvement de l'ennemi E
* @param E l'ennemi
* @return Rien
*/


void moveEnnemi(Ennemi* E)
{


  if ((E->pos_min <= E->positionAbsolue.x)&&(E->positionAbsolue.x<E->pos_max)&&(E->direction==2))
     {E->positionAbsolue.x+=2;}

  if (E->positionAbsolue.x==E->pos_max) {E->direction=1;}
 
  if ((E->pos_min < E->positionAbsolue.x)&&(E->positionAbsolue.x <= E->pos_max)&&(E->direction==1))
     {E->positionAbsolue.x-=2;}
 
  if (E->positionAbsolue.x==E->pos_min) {E->direction=2;} 
 

}


/**
* @brief Afficher l'ennemi E
* @param screen the screen
* @param E l'ennemi
* @return rien
*/

void blit_Ennemi(Ennemi E,SDL_Surface *screen)
{

  SDL_BlitSurface(E.image,&E.pos_ennemi,screen,&E.positionAbsolue);

}

/**
* @brief Liberer la surface 
* @param E l'ennemi
* @return rien
*/

void free_Ennemi(Ennemi *E)
{

 SDL_FreeSurface(E->image);

}



