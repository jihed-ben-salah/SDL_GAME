#ifndef FONCTION_H_
#define FONCTION_H_

typedef struct enigme_s
{
SDL_Surface *enigme;
SDL_Surface *boutton1;
SDL_Surface *boutton2;
SDL_Surface *boutton3;
SDL_Rect positionboutton1,positionboutton2,positionboutton3,positionenigme;
}enigme_s;

typedef struct hero
{SDL_Rect position_hero;
SDL_Rect *persd[4],*persg[4];//(GAUCHE,DROITE)
//SDL_surface *vie,*temps;
//score Score;
}hero;

void initialiser (enigme_s* E);
void afficher(enigme_s *E,  SDL_Surface *screen);
int resolution ( enigme_s *E, SDL_Surface *screen, SDL_Event event );
void deplacement ( SDL_Event event,hero h);
 //int col_trigo(SDL_Rect *hero, SDL_Rect *entite);

#endif
