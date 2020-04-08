
#ifndef ENIGME_H_
#define ENIGME_H_

typedef struct enigme_sf 
{  
SDL_Surface *image[15];
int pos_x[15];
int pos_y[15];
SDL_Rect pos[16];
}enigme_sf;

void initialiser (  enigme_sf * E);
void aleatoire ( enigme_sf *E);
void afficher(enigme_sf *E,  SDL_Surface *screen,int i);
int resolution ( enigme_sf E, SDL_Surface * screen, SDL_Event P,SDL_Surface *image,SDL_Rect positionbackground);
#endif

