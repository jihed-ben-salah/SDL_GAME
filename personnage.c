#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "personnage.h"
#include "collision.h"
void initialiser_hero(hero *h)
{
//charactere
    h->sprite_right=IMG_Load("sprite.png");
    h->positionsprite.x=400;
    h->positionsprite.y=520;
    h->sprite_left=IMG_Load("Lsprite.png");

    h->left[7].x=0;
    h->left[7].y=0;
    h->left[7].w=56;
    h->left[7].h=110;
    h->left[6].x=56;
    h->left[6].y=0;
    h->left[6].w=56;
    h->left[6].h=110;
    h->left[5].x=112;
    h->left[5].y=0;
    h->left[5].w=56;
    h->left[5].h=110;
    h->left[4].x=168;
    h->left[4].y=0;
    h->left[4].w=56;
    h->left[4].h=110;
    h->left[3].x=224;
    h->left[3].y=0;
    h->left[3].w=56;
    h->left[3].h=110;
    h->left[2].x=280;
    h->left[2].y=0;
    h->left[2].w=56;
    h->left[2].h=110;
    h->left[1].x=336;
    h->left[1].y=0;
    h->left[1].w=56;
    h->left[1].h=110;
    h->left[0].x=392;
    h->left[0].y=0;
    h->left[0].w=56;
    h->left[0].h=110;
    h->right[7].x=392;
    h->right[7].y=0;
    h->right[7].w=56;
    h->right[7].h=110;
    h->right[6].x=336;
    h->right[6].y=0;
    h->right[6].w=56;
    h->right[6].h=110;
    h->right[5].x=280;
    h->right[5].y=0;
    h->right[5].w=56;
    h->right[5].h=110;
    h->right[4].x=224;
    h->right[4].y=0;
    h->right[4].w=56;
    h->right[4].h=110;
    h->right[3].x=168;
    h->right[3].y=0;
    h->right[3].w=56;
    h->right[3].h=110;
    h->right[2].x=112;
    h->right[2].y=0;
    h->right[2].w=56;
    h->right[2].h=110;
    h->right[1].x=56;
    h->right[1].y=0;
    h->right[1].w=56;
    h->right[1].h=110;
    h->right[0].x=0;
    h->right[0].y=0;
    h->right[0].w=56;
    h->right[0].h=110;


}
void Afficher(hero h,SDL_Surface *screen)
{


    if(h.verif!=3)
        SDL_BlitSurface(h.sprite_right,&h.right[0],screen,&h.positionsprite);
    else
        SDL_BlitSurface(h.sprite_left,&h.left[0],screen,&h.positionsprite);

}

int Animation_hero(hero *h,SDL_Surface *screen,background *Back, SDL_Surface *BackMasque)

{

    int done=0;
    SDL_Event event,event2;
    int j=1;
    int speed=8;
    SDL_Rect coll;
    coll.w=2;
    coll.h=45;
   coll.y=h->positionsprite.y;
    while(SDL_PollEvent(&event))
    {

        switch (event.type)
        {
        case SDL_QUIT :
        {
            return 1;
            break;
        }
        case SDL_KEYDOWN:
        {
            if(event.key.keysym.sym==SDLK_RIGHT)
            {

                while (j<8 )
                {

            
                    SDL_BlitSurface(Back->backgroundImg,&Back->camera,screen,NULL);


                    SDL_BlitSurface(h->sprite_right,&h->right[j],screen,&h->positionsprite);
// partie collision de jihad
                    Back->b[0]=1;
                    if(Back->b[0])
                    {
                        Back->x+=speed;
                        Back->camera.x+=speed;
                        if(Back->camera.x>=10000-800)
                            Back->camera.x=10000-800;
                    }
                    else if(Back->b[1])
                    {
                        Back->x-=speed;
                        Back->camera.x-=speed;
                        if(Back->camera.x<=0)
                            Back->camera.x=0;
                    }
                    coll.x=Back->camera.x+400;
                    if(colbackgroundleft(BackMasque,coll))
                    {
                        Back->camera.x-=(speed+5);
                    }
                    else if(colbackgroundRight(BackMasque,coll))
                    {
                        Back->camera.x+=(speed+5);
                    }
else if(colbackgroundDown(BackMasque,coll))
{h->positionsprite.y-=1;}
else if(colbackgroundUp(BackMasque,coll))
{Back->camera.y+=1;}


      

                    SDL_Flip(screen);
                    SDL_Delay(10);
//                 Marquer la position du personnage a droite/gauche
                    h->verif=2;
j++;

                }
j=1;
            }

            else  if(event.key.keysym.sym==SDLK_LEFT)
            {
                while (j<8  )
                {

               

                    SDL_BlitSurface(Back->backgroundImg,&Back->camera,screen,NULL);

                    SDL_BlitSurface(h->sprite_left,&h->left[j],screen,&h->positionsprite);
// partie collision de jihad
                    Back->b[1]=1;
                    if(Back->b[0])
                    {
                        Back->x+=speed;
                        Back->camera.x+=speed;
                        if(Back->camera.x>=10000-800)
                            Back->camera.x=10000-800;
                    }
                    else if(Back->b[1])
                    {
                        Back->x-=speed;
                        Back->camera.x-=speed;
                        if(Back->camera.x<=0)
                             Back->camera.x=0;
                    }
                    coll.x=Back->camera.x+400;

 if(colbackgroundleft(BackMasque,coll))
                    {
                        Back->camera.x-=(speed+5);
                    }
                    else if(colbackgroundRight(BackMasque,coll))
                    {
                        Back->camera.x+=(speed+5);
                    }
else if(colbackgroundDown(BackMasque,coll))
{h->positionsprite.y-=1;}
else if(colbackgroundUp(BackMasque,coll))
{Back->camera.y+=1;}

                    SDL_Flip(screen);
                    SDL_Delay(10);
//                 Marquer la position du personnage a droite/gauche
                    h->verif=3;
j++;

                }
            }
 else  if(event.key.keysym.sym==SDLK_UP)
            {
 SDL_BlitSurface(Back->backgroundImg,&Back->camera,screen,NULL);
h->positionsprite.y-=1;

                    SDL_BlitSurface(h->sprite_left,&h->left[j],screen,&h->positionsprite);
if(colbackgroundleft(BackMasque,coll))
                    {
                        Back->camera.x-=(speed+5);
                    }
                    else if(colbackgroundRight(BackMasque,coll))
                    {
                        Back->camera.x-=(speed+5);
                    }
else if(colbackgroundDown(BackMasque,coll))
{h->positionsprite.y-=1;}
else if(colbackgroundUp(BackMasque,coll))
{Back->camera.y+=1;}
SDL_Flip(screen);
}else  if(event.key.keysym.sym==SDLK_DOWN)
            {
 SDL_BlitSurface(Back->backgroundImg,&Back->camera,screen,NULL);
if(h->positionsprite.y<650){
h->positionsprite.y+=1;}
                    SDL_BlitSurface(h->sprite_left,&h->left[j],screen,&h->positionsprite);
if(colbackgroundleft(BackMasque,coll))
                    {
                        Back->camera.x-=(speed+5);
                    }
                    else if(colbackgroundRight(BackMasque,coll))
                    {
                        Back->camera.x-=(speed+5);
                    }
else if(colbackgroundDown(BackMasque,coll))
{h->positionsprite.y-=1;}
else if(colbackgroundUp(BackMasque,coll))
{Back->camera.y+=1;}
SDL_Flip(screen);
}
            j=1;
            break;
        }
// partie scrolling de jihad
        case SDL_KEYUP:
            if(event.key.keysym.sym==SDLK_RIGHT)
            {
                Back->b[0]=0;

                break;
            }


            else if(event.key.keysym.sym==SDLK_LEFT)
            {
                Back->b[1]=0;

                break;
            }
        }
    }
    if(Back->b[0])
    {
        Back->x+=speed;
        Back->camera.x+=speed;
        if(Back->camera.x>=10000-800)
            Back->camera.x=10000-800;
    }
    else if(Back->b[1])
    {
        Back->x-=speed;
        Back->camera.x-=speed;
        if(Back->camera.x<=0)
            Back->camera.x=0;
    }





    SDL_Flip(screen);
//SDL_FreeSurface(h->sprite_left);
//SDL_FreeSurface(h->sprite_right);
SDL_FreeSurface(Back->backgroundImg);
}




