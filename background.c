#include  "background.h"
#include "SDL/SDL_image.h"
#define SCREEN_W 1000
#define SCREEN_H 736

void loadBackground(background *Back)
{
	
        // load background
	
        Back->background_Img = IMG_Load("background.png");

	if (Back->background_Img == NULL) {
           printf("Erreuer Chargement Background Images\n");
	}

}

void initialiser_Background(background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0; 
        Backg->backgroundPos.w=SCREEN_W/2;
	Backg->backgroundPos.h=SCREEN_H;   
       Backg->backgroundPos2.x=SCREEN_W/2;
	Backg->backgroundPos2.y=0; 
          Backg->backgroundPos2.w=SCREEN_W/2;
	Backg->backgroundPos2.h=SCREEN_H;
        Backg->camera.x=0;
         Backg->camera.y=0;
         Backg->camera.w=SCREEN_W/2;
         Backg->camera.h=SCREEN_H;
         Backg->camera2.x=0;
         Backg->camera2.y=0;
         Backg->camera2.w=SCREEN_W/2;
         Backg->camera2.h=SCREEN_H;

}
void blitbackground(background *Backg,SDL_Surface *screen)
{
SDL_BlitSurface(Backg->background_Img,&Backg->camera,screen,NULL);
}
void blitbackground2(background *Backg,SDL_Surface *screen)
{
SDL_BlitSurface(Backg->background_Img,&Backg->camera2,screen,&Backg->backgroundPos2);
}
/*void scrolling(background *backg,int *b)
{
const int speed=20;
int x,y;
x=0;
y=0;
if(b[0]==1)
{x+=speed;
backg->camera.x+=speed;
if(backg->camera.x>=10000-1000)
backg->camera.x=10000-1000;}
else if(b[1]==1)
{x-=speed;
backg->camera.x-=speed;
if(backg->camera.x<=0)
backg->camera.x=0;
}
}*/
void scrolling(background *backg,int *b,int c)
{
const int speed=20;
int x,y;
x=0;
y=0;
if(c==1)
{
if(b[0]==1)
{x+=speed;
backg->camera.x+=speed;
if(backg->camera.x>=10000-500)
	backg->camera.x=10000-500;}
else if(b[1]==1)
{x-=speed;
backg->camera.x-=speed;
if(backg->camera.x<=0)
backg->camera.x=0;
}
}
else 
{
if(b[0]==1)
{x+=speed;
backg->camera2.x+=speed;
if(backg->camera2.x>=10000-500)
backg->camera2.x=10000-500;}
else if(b[1]==1)
{x-=speed;
backg->camera2.x-=speed;
if(backg->camera2.x<=0)
backg->camera2.x=0;
}
}
}


void freeBackground(background *Back)
{

 SDL_FreeSurface(Back->background_Img);

}



