

#ifndef OTHELLO_H_
#define OTHELLO_H_



#define kblanche 0
#define knoire 1
#define kneutre 2
#define klCase 64
#define khCase 64
#define kcorrect 1

typedef struct
{SDL_Surface* spiece[3];
}othello;
void initi(othello *O);
void initialisation(int table[8][8]);
void dessin(int table[8][8], SDL_Surface* sfenetre,othello O);
void copie(int table[8][8], int copieTable[8][8]);
int passerTour(int table[8][8], int couleur) ;
int total(int table[8][8]);
int arbre(int table[8][8], int couleur, int x);
void ordinateur(int table[8][8]);
int encadrement(int table[8][8], int couleur, int i, int j, int dir[2]);
int inversionPions(int table[8][8], int couleur, int i, int j);
int positionnement(int table[8][8], int couleur, int i, int j);
#endif

