#include <SDL/SDL.h>
#include "othello.h"

#define klCase 64
#define khCase 64


int main() {

	

	int fin=0, n;
	int table[8][8];
       othello O;
	SDL_Surface* sfenetre;
	
	SDL_Event evenement;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_WM_SetCaption("othello", NULL);
	sfenetre=SDL_SetVideoMode(8*klCase, 8*khCase, 32, SDL_HWSURFACE);

	initi(&O);

	initialisation(table);

	dessin(table, sfenetre,O);
	SDL_Flip(sfenetre);

	while ( !fin ) {

		SDL_WaitEvent(&evenement);

		switch ( evenement.type ) {

			case SDL_QUIT:
				fin=1;
			break;
			case SDL_KEYDOWN:
				if ( evenement.key.keysym.sym==SDLK_ESCAPE )
					fin=1;
			break;
			case SDL_MOUSEBUTTONDOWN:
				if ( !passerTour(table, kblanche) ) {

					if ( positionnement(table, kblanche, evenement.button.y/khCase, 
					       evenement.button.x/klCase)==kcorrect ) {

						dessin(table, sfenetre,O);
						SDL_Flip(sfenetre);

						SDL_Delay(1000);

						if ( !passerTour(table, knoire) )
							ordinateur(table);
					}
				}
				else if ( !passerTour(table, knoire) )
					ordinateur(table);

				dessin(table, sfenetre,O);
				SDL_Flip(sfenetre);
			break;
		}
	}

	for ( n=0; n<3; n++ )
		SDL_FreeSurface(O.spiece[n]);

	SDL_Quit();

	return 0;
}






