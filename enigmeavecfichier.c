/**  
* @file [<enigmeavecfichier.c>] 
*/ 
#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "fonction.h"

/**  
* @brief generer un entier aléatoirement   .  
* @param rien  
* @return un entier  
*/
int aleatoire()
{int i;
do {
    srand(time(NULL));
   i=rand()%20;

  } while(i==0 || i>10);

return i;
}
/**  
* @brief  initialiser l' enigme E .  
* @param E enigme  pointeur   
* @param fichier :c'est le nom du ficher dont lequel on va lire les les enigmes 
* @return Nothing  
*/
void initialiser (char* fichier,Enigme *E)
{
FILE *f=NULL;
int numero,i,j=0;
TTF_Font *police = NULL;
TTF_Font *police1 = NULL;
SDL_Color couleurNoire = {31,11,11};
TTF_Init();
 police = TTF_OpenFont("aaaa.ttf",45);
 police1 = TTF_OpenFont("1.ttf",45);

char caractereActuel;
char chaine[256]="";
numero=aleatoire();
f=fopen(fichier,"r");
if(f!=NULL)
{while(fgets(chaine,256,f)!=NULL)
{j++;

if(j==numero)
{
i=0;
                do
               {
                caractereActuel = fgetc(f); // On lit le caractère
                E->question[i]=caractereActuel;
                  i++;
                }while(caractereActuel!='.');

i=0;
                do
               {
                caractereActuel = fgetc(f); // On lit le caractère
                E->reponse.rep1[i]=caractereActuel;
                i++;
               }while(caractereActuel!='.');


i=0;
               do
               {
               caractereActuel = fgetc(f); // On lit le caractère
               E->reponse.rep2[i]=caractereActuel;
               i++;
               }while(caractereActuel!='.');
i=0;

               do
               {
               caractereActuel = fgetc(f);
               E->reponse.rep3[i]=caractereActuel;
               i++;

               }while(caractereActuel!='.');
i=0;

               do
               {caractereActuel=fgetc(f); // On lit le caractère
                E->reponse.rep_vrai[i]=caractereActuel;
                i++;
               }while(caractereActuel!='.');

}

}
fclose(f);


}

// Écriture du texte dans la SDL_Surface question
     E->ques =TTF_RenderText_Blended(police,E->question,couleurNoire);
     E->position_question.x = 185;
     E->position_question.y =350;

// Écriture du texte dans la SDL_Surface reponse1

    E->reponse.r1=TTF_RenderText_Blended(police1,E->reponse.rep1,couleurNoire);
    E->reponse.position_rep1.x = 400;
    E->reponse.position_rep1.y =450 ;
 E->reponse.position_rep1.w=E->reponse.r1->w;
// Écriture du texte dans la SDL_Surface reponse2
    E->reponse.r2=TTF_RenderText_Blended(police1,E->reponse.rep2,couleurNoire);
    E->reponse.position_rep2.x = 400;
    E->reponse.position_rep2.y =550 ;
E->reponse.position_rep2.w=E->reponse.r2->w;
// Écriture du texte dans la SDL_Surface reponse3
    E->reponse.r3=TTF_RenderText_Blended(police1,E->reponse.rep3,couleurNoire);
    E->reponse.position_rep3.x = 400;
    E->reponse.position_rep3.y =650 ;
E->reponse.position_rep3.w=E->reponse.r3->w;
TTF_CloseFont(police);
TTF_CloseFont(police1);
TTF_Quit();
}
/**  
* @brief  afficher les reponses et la question  .  
* @param surface de l'enigme 
* @param E enigme  
* @return Nothing  
*/
void afficher(Enigme E, SDL_Surface * surface_enigme)
{
SDL_Surface *fonds=NULL;
SDL_Rect positionfonds;
//fonds de l'enigme
     fonds=IMG_Load("fonds.png");
     positionfonds.x=0;
     positionfonds.y=0;
SDL_BlitSurface(fonds, NULL,surface_enigme,&positionfonds); 

SDL_BlitSurface(E.ques,&positionfonds,surface_enigme,&E.position_question);


SDL_BlitSurface(E.reponse.r1,&positionfonds,surface_enigme,&E.reponse.position_rep1);


SDL_BlitSurface(E.reponse.r2,&positionfonds,surface_enigme,&E.reponse.position_rep2);


SDL_BlitSurface(E.reponse.r3,&positionfonds,surface_enigme,&E.reponse.position_rep3);
    SDL_Flip(surface_enigme);
}
/**  
* @brief  resolution de l'enigme E.  
* @param surface de l'enigme 
* @param E enigme  
* @return 0 si vrai ou 1 si faux 
*/

int resolution (Enigme E, SDL_Surface *surface_enigme,int a,int b)
{int Reso=-1;

char w,v;



v=E.reponse.rep_vrai[0];



if (a > E.reponse.position_rep1.x && a< E.reponse.position_rep1.x + E.reponse.position_rep1.w && b >E.reponse.position_rep1.y && b < E.reponse.position_rep1.y+45)
    {w=E.reponse.rep1[0];

    if(w==v)
     {
      Reso=1;
      }
    else
     {Reso=0;
     
    }


     }
else if (a > E.reponse.position_rep2.x && a< E.reponse.position_rep2.x+E.reponse.position_rep2.w && b >E.reponse.position_rep2.y && b < E.reponse.position_rep2.y+45)
    {
w=E.reponse.rep2[0];

if(w==v)
      {Reso=1;

}
    else
     {Reso=0;
     }


     }
else if (a > E.reponse.position_rep3.x && a< E.reponse.position_rep3.x+E.reponse.position_rep3.w && b >E.reponse.position_rep3.y && b < E.reponse.position_rep3.y+45)
    {w=E.reponse.rep3[0];

if(w==v)
     { Reso=1;

}
    else
     {Reso=0;

}

     }



return Reso;

}
