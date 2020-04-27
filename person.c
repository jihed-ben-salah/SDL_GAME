#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
int main(void)
{

// initialisation de variable
    int j;
    char pause ;
    SDL_Surface *screen;
    SDL_Surface *background;
    SDL_Surface *sprite;
    SDL_Rect positionecran;
    SDL_Rect right[7],left[7];  //tableau
    SDL_Rect positionsprite;
    SDL_Event event;
    int x,y;
    int w,h;

// background
    background=IMG_Load("background.png");
    if(background==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
        return 1;
    }
    positionecran.x=0;
    positionecran.y=0;
    positionecran.w=background->w;

//tableau sprite
left[0].x=0;left[0].y=220;left[0].w=56;left[0].h=110;  
left[1].x=56;left[1].y=220;left[1].w=56;left[1].h=110;  
left[2].x=112;left[2].y=220;left[2].w=56;left[2].h=110;
left[3].x=168;left[3].y=220;left[3].w=56;left[3].h=110;  
 left[4].x=224;left[4].y=165;left[4].w=56;left[4].h=165; 
 left[5].x=280;left[5].y=55;left[5].w=56;left[5].h=275; 
left[6].x=336;left[6].y=110;left[6].w=56;left[6].h=220;
left[7].x=392;left[7].y=220;left[7].w=56;left[7].h=110;
left[8].x=448;left[8].y=220;left[8].w=56;left[8].h=110;
left[9].x=504;left[9].y=220;left[9].w=56;left[9].h=110;
right[9].x=392;right[9].y=220;right[9].w=56;right[9].h=110;
right[8].x=448;right[8].y=220;right[8].w=56;right[8].h=110;
right[7].x=392;right[7].y=220;right[7].w=56;right[7].h=110;
right[6].x=336;right[6].y=110;right[6].w=56;right[6].h=220;
right[5].x=280;right[5].y=55;right[5].w=56;right[5].h=275;  
right[4].x=224;right[4].y=165;right[4].w=56;right[4].h=165;  
right[3].x=168;right[3].y=220;right[3].w=56;right[3].h=110;
right[2].x=112;right[2].y=220;right[2].w=56;right[2].h=110;  
 right[1].x=56;right[1].y=220;right[1].w=56;right[1].h=110; 
 right[0].x=0;right[0].y=220;right[0].w=56;right[0].h=110;

//charactere
sprite=IMG_Load("sprite.png");
positionsprite.x=0;
positionsprite.y=400;

// ouverture fenetre
    screen=SDL_SetVideoMode(800,750,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }



//Blit


   int done=1;//SDL_EnableKeyRepeat(30,0);
   
    while (done)

    { 
  SDL_BlitSurface(background,NULL,screen,&positionecran);
  SDL_BlitSurface(sprite, &right[0],screen,&positionsprite);   



  while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT :
            {
                done=0 ;
                break;
            }
   case SDL_KEYUP:
            {                        //deplacement du clavier down  
             if(event.key.keysym.sym==SDLK_UP)
             for (j=0;j<10;j++)
             {
                positionsprite.y=positionsprite.y-5;
                SDL_BlitSurface(background,NULL,screen,&positionecran);
                SDL_BlitSurface(sprite,&right[j] ,screen,&positionsprite);
                positionsprite.y=positionsprite.y+5;
                
    SDL_Flip(screen); 
    SDL_Delay(50);

                
             }
                  break;}
 case SDL_KEYDOWN:
{ 
if(event.key.keysym.sym==SDLK_RIGHT)
for (j=0;j<8;j++)
{
    positionsprite.x=positionsprite.x+5;
    SDL_BlitSurface(background,NULL,screen,&positionecran);
    SDL_BlitSurface(sprite,&right[j] ,screen,&positionsprite); 
    
    
   
    SDL_Flip(screen); 
    SDL_Delay(50);
}
else  if(event.key.keysym.sym==SDLK_LEFT)
for (j=0;j<8;j++)
{
  
  positionsprite.x=positionsprite.x-5;
  SDL_BlitSurface(background,NULL,screen,&positionecran);
  SDL_BlitSurface(sprite,&left[j] ,screen,&positionsprite); 
  
   
   SDL_Flip(screen); 
   SDL_Delay(50);
}
j=0; SDL_Flip(screen); break;} }

 SDL_Flip(screen);
}  SDL_Flip(screen); }

//liberer les surfaces

SDL_FreeSurface(background);
SDL_FreeSurface(sprite);
SDL_Delay(10);
SDL_Quit();
pause=getchar();


return 0;

}


