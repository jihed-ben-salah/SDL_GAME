#ifndef ENIGMEAVECFICHIER_H_
#define ENIGMEAVECFICHIER_H_

//soumaya enigme avec fichier
/**  
* @struct REPONSE 
* @brief structure pour les reponses de l enigme 
*/
typedef struct {

char rep1[10];
SDL_Surface *r1; /*!< surface reponse1*/
SDL_Rect position_rep1;/*!< Rectangle pour la reponse 1*/
char rep2[10];
SDL_Surface *r2;/*!< surface reponse2*/
SDL_Rect position_rep2;/*!< Rectangle pour la reponse 2*/
char rep3[10];/*!< Rectangle pour la reponse 3*/
SDL_Surface *r3;/*!< surface reponse3*/
SDL_Rect position_rep3;
char rep_vrai[10];
}rep; 
/**  
* @struct ENIGME  
* @brief structure pour l'enigme 
*/
typedef struct { 
char question[300];
rep reponse; 
SDL_Surface *ques;/*!< surface question */
SDL_Rect position_question;/*!< Rectangle pour question */

}Enigme;

int aleatoire ();
void initialiser (char* fichier,Enigme *E);
void afficher(Enigme E, SDL_Surface * surface_enigme);
int resolution (Enigme E, SDL_Surface *surface_enigme,int a,int b);


#endif
