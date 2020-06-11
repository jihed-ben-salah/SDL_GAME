
/**
* @struct entite_sc
* @brief struct for entite
*/

#pragma once

typedef struct{

SDL_Surface *img1; /*!< Surface. */
SDL_Surface *img2; /*!< Surface. */
SDL_Rect pos; /*!< Rectangle*/

int dx;
int cx;

} entite_sc;

void Entite_Init(entite_sc *e,int x, int y);
void deplacement_aleatoire (entite_sc *e, SDL_Surface **screen);
