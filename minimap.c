#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include  "background.h"
#include  "minimap.h"
#include "hero.h"
void loadminimap(minimap *mini)
{
mini->minimap_Img= IMG_Load("mini2.png");

	if (mini->minimap_Img == NULL) {
           printf("Erreuer Chargement minimap Images\n");
	}
mini->Dot= IMG_Load("dot4.png");

	if (mini->Dot == NULL) {
           printf("Erreuer Chargement minimap Images\n");
	}


}
void free_minimap(minimap *mini)
{

 SDL_FreeSurface(mini->minimap_Img);
 SDL_FreeSurface(mini->Dot);
}

void initialiser_minimap(minimap *mini)
{
mini->minimap_Pos.x=0;
mini->minimap_Pos.y=0;
mini->Dot_Pos.x=0;
mini->Dot_Pos.y=54;
}
void afficher_minimap(minimap *mini,SDL_Surface *screen,background back,Hero h)
{

SDL_BlitSurface(mini->minimap_Img,NULL,screen,&mini->minimap_Pos);
SDL_BlitSurface(mini->Dot,NULL,screen,&mini->Dot_Pos);
if (h.posimage.x<150)
mini->Dot_Pos.x=h.posimage.x/10;
else 
mini->Dot_Pos.x=(back.camera.x+150)/10;


mini->Dot_Pos.y=(h.posimage.y*54)/489;










}
