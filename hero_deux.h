#ifndef hero_deuxH_
#define hero_deux_H_

#define hero_deux_WIDTH 128
#define hero_deux_HEIGHT 135 

typedef struct {
SDL_Surface *personnagehero_deux;
SDL_Rect poshero_deux;
SDL_Rect posimagehero_deux;

int viehero_deux;

}hero_deux; 


void loadhero_deux(hero_deux *H);
void initialiser_hero_deux(hero_deux *H);
void blithero_deux(hero_deux H,SDL_Surface *screen);
void animateheroD(hero_deux *H); 
void animateheroG(hero_deux *H); 
void MoveheroD(hero_deux *H);
void MoveheroG(hero_deux *H);
void free_hero_deux(hero_deux *H);


#endif
