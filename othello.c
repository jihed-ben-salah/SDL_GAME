#include <SDL/SDL.h>
#include "othello.h"
void initi(othello *O)
{       O->spiece[kblanche]=SDL_LoadBMP("blanche.bmp");
	O->spiece[knoire]=SDL_LoadBMP("noire.bmp");
	O->spiece[kneutre]=SDL_LoadBMP("neutre.bmp");
}
void initialisation(int table[8][8]) {

	int i, j;

	for ( i=0; i<8; i++ )
		for ( j=0; j<8; j++ )
			table[i][j]=kneutre;

	table[3][3]=kblanche, table[3][4]=knoire, 
	table[4][3]=knoire, table[4][4]=kblanche;

	
}
void dessin(int table[8][8],SDL_Surface* sfenetre,othello O) {

	int i, j;
	SDL_Rect position;

	for ( i=0; i<8; i++ ) {

		position.y=i*khCase;

		for ( j=0; j<8; j++ ) {

			position.x=j*klCase;

			SDL_BlitSurface(O.spiece[table[i][j]], NULL, sfenetre, &position);
		}
	}

	
}

void copie(int table[8][8], int copieTable[8][8]) {

	int i, j;

	for ( i=0; i<8; i++ )
		for ( j=0; j<8; j++ )
			copieTable[i][j]=table[i][j];

	return;
}

int passerTour(int table[8][8], int couleur) {

	int i, j;
	int copieTable[8][8];

	for ( i=0; i<8; i++ ) {

		for ( j=0; j<8; j++ ) {

			copie(table, copieTable);

			if ( positionnement(copieTable, couleur, i, j)==kcorrect )
				return 0;
		}
	}

	return 1;		
}
int total(int table[8][8]) {

	int i, j, n=0;

	for ( i=0; i<8; i++ )
		for ( j=0; j<8; j++ )
			if ( table[i][j]==knoire )
				n++;
			else if ( table[i][j]==kblanche )
				n--;

	return n;
}
int arbre(int table[8][8], int couleur, int x) {

	int total(int table[8][8]);

	int i, j, n=0;
	int copieTable[8][8];

	if ( x<4 ) {

		x++;

		for ( i=0; i<8; i++ ) {

			for ( j=0; j<8; j++ ) {

				copie(table, copieTable);

				if ( positionnement(copieTable, couleur, i, j)==kcorrect )
					n+=arbre(copieTable, !couleur, x);
			}
		}
	}
	else
		return total(table);

	return n/4;
}
void ordinateur(int table[8][8]) {

	int arbre(int table[8][8], int couleur, int x);

	int i, j, n, m, x=0;
	int copieTable[8][8], tableDefinitive[8][8];

	for ( i=0; i<8; i++ ) {

		for ( j=0; j<8; j++ ) {

			copie(table, copieTable);

			if ( positionnement(copieTable, knoire, i, j)==kcorrect ) {

				x++;
				n=arbre(copieTable, knoire, 0);

				if ( x==1 || n>m ) {

					m=n;
					copie(copieTable, tableDefinitive);
				}
			}
		}
	}

	copie(tableDefinitive, table);

	return;
}






int encadrement(int table[8][8], int couleur, int i, int j, int dir[2]) {

	while ( 0<=i && i<=7 && 0<=j && j<=7 && table[i][j]==!couleur )
		i+=dir[0], j+=dir[1];

	if ( 0<=i && i<=7 && 0<=j && j<=7 && 
	       table[i][j]==couleur && table[i-dir[0]][j-dir[1]]==!couleur )
		return kcorrect;

	return !kcorrect;
}

int inversionPions(int table[8][8], int couleur, int i, int j) {

	int encadrement(int table[8][8], int couleur, int i, int j, int dir[2]) ;

	int n, ci, cj, x=0;
	int dir[8][2]={{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

	for ( n=0; n<8; n++ ) {

		ci=i, cj=j;

		if ( encadrement(table, couleur, ci+dir[n][0], cj+dir[n][1], dir[n])==kcorrect ) {

			while ( table[ci+dir[n][0]][cj+dir[n][1]]==!couleur ) {

				table[ci+dir[n][0]][cj+dir[n][1]]=couleur;
				ci+=dir[n][0], cj+=dir[n][1];
				x++;
			}
		}
	}

	return x;
}

int positionnement(int table[8][8], int couleur, int i, int j) {

	int inversionPions(int table[8][8], int couleur, int i, int j);

	if ( table[i][j]==kneutre ) {

		if ( inversionPions(table, couleur, i, j)!=0 ) {

			table[i][j]=couleur;

			return kcorrect;
		}
	}

	return !kcorrect;
}
