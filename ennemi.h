/**
* @struct Ennemi
* @brief struct for Ennemi
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define Ennemi_WIDTH 100
#define Ennemi_HEIGHT 100 


typedef struct
{

SDL_Surface* image; /*!< Surface. */

SDL_Rect pos_ennemi;  // Sprite  /*!< Rectangle*/
SDL_Rect positionAbsolue; // Depl  /*!< Rectangle*/

int direction;

int pos_max;
int pos_min;

}Ennemi;

void Load_ennemi(Ennemi* E);
void initialiserennemi(Ennemi* E,int max,int min);
void Dep_Alea_Ennemi(Ennemi* E);
void animateEnnemi(Ennemi* E);
void blit_Ennemi(Ennemi E,SDL_Surface *screen);
void free_Ennemi(Ennemi* E);
void moveEnnemi(Ennemi* E);
