#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main(void)
{

// initialisation de variable
    SDL_Surface *screen;
    SDL_Surface *texte;
    SDL_Surface *background;
    SDL_Rect positionecran;
    SDL_Surface *play;
    SDL_Surface *playmotion;
    SDL_Surface *playclic;
    SDL_Surface *exit;
    SDL_Surface *new;
    SDL_Surface *point;
    SDL_Surface *point2;
    SDL_Surface *exitmotion;
    SDL_Surface *exitclic;
    SDL_Surface *option;
    SDL_Surface *optionclic;
    SDL_Surface *optionmotion;
    SDL_Rect positionplay;
    SDL_Rect positionpoint;
    SDL_Rect positionpoint2;
    SDL_Rect positionon;
    SDL_Surface *fenetre;
    SDL_Surface *backoption;
    SDL_Rect positionoption;
    SDL_Rect positiontexte;
    SDL_Rect positionbackoption;
    SDL_Rect positionexit;
    Mix_Chunk *son;
    Mix_Music *music;
    SDL_Surface *on;
    SDL_Surface *off,*sprite;
    SDL_Surface *t[12];
    SDL_Rect right[5],left[5];  //tableau
    SDL_Rect positionsprite;
    int x, y;
    int position=3;
    char pause;
    int a,b;
    int resolution=0;
    int verif=0;
    int test=0,f=0;
    SDL_Event event;
    SDL_Event event2;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire= {255,255,255};

    /*le tableau des images */
    t[0]=IMG_Load("background.png");
    t[1]=IMG_Load("1a.png");
    t[2]=IMG_Load("2a.png");
    t[3]=IMG_Load("3a.png");
    t[4]=IMG_Load("4a.png");
    t[5]=IMG_Load("5a.png");
    t[6]=IMG_Load("6a.png");
    t[7]=IMG_Load("7a.png");
    t[8]=IMG_Load("8a.png");
    t[9]=IMG_Load("9a.png");
    t[10]=IMG_Load("10a.png");
    t[11]=IMG_Load("11a.png");
    int i=0,j;
//tableau sprite
    left[0].x=5;
    left[0].y=10;
    left[0].w=64;
    left[0].h=438;
    left[1].x=85;
    left[1].y=10;
    left[1].w=64;
    left[1].h=438;
    left[2].x=176;
    left[2].y=10;
    left[2].w=64;
    left[2].h=439;
    left[3].x=257;
    left[3].y=10;
    left[3].w=64;
    left[3].h=438;
    left[4].x=328;
    left[4].y=10;
    left[4].w=64;
    left[4].h=438;
    left[5].x=415;
    left[5].y=10;
    left[5].w=64;
    left[5].h=438;
    right[5].x=5;
    right[5].y=165;
    right[5].w=64;
    right[5].h=438;
    right[4].x=85;
    right[4].y=165;
    right[4].w=64;
    right[4].h=438;
    right[3].x=176;
    right[3].y=165;
    right[3].w=64;
    right[3].h=439;
    right[2].x=257;
    right[2].y=165;
    right[2].w=64;
    right[2].h=438;
    right[1].x=328;
    right[1].y=165;
    right[1].w=64;
    right[1].h=438;
    right[0].x=415;
    right[0].y=165;
    right[0].w=64;
    right[0].h=438;
//charactere
    sprite=IMG_Load("sprite.png");
    positionsprite.x=620;
    positionsprite.y=450;

    /* Chargement de la police */
    TTF_Init();
    police = TTF_OpenFont("1.ttf",55);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "THE MAGIC PILL", couleurNoire);
    positiontexte.x = 850;
    positiontexte.y = 450;
// musique
    if ( Mix_OpenAudio ( 44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) == -1 )
    {
        printf ( " %s", Mix_GetError());
    }
    Mix_AllocateChannels(1);
    music= Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(music,-1);
    //son bref
    son = Mix_LoadWAV("click.wav");


    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }

// image point
    point=IMG_Load("point1.png");
    if(point==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    positionpoint.x=645;  // 550 pos 1
    positionpoint.y=260;


// image point 2
    point2=IMG_Load("point2.png");

    positionpoint2.x=645;
    positionpoint2.y=380;
// ouverture fenetre option
    fenetre=SDL_SetVideoMode(400,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(fenetre==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
// background
    backoption=IMG_Load("fenetreva.png");
    if(backoption==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
        return 1;
    }
    positionbackoption.x=450;
    positionbackoption.y=10;
    positionbackoption.w=backoption->w;
// ouverture fenetre
    screen=SDL_SetVideoMode(1280,604,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
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
// image play
    play=IMG_Load("play1.png");
    if(play==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    positionplay.x=525;
    positionplay.y=200;
// image exit
    exit=IMG_Load("exit1.png");
    if(exit==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    positionexit.x=525;
    positionexit.y=350;
// image exitmotion
    exitmotion=IMG_Load("exitmotion1.png");
    if(exitmotion==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    // image exitclic
    exitclic=IMG_Load("exitclic1.png");
    if(exitclic==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }

// image option
    option=IMG_Load("option1.png");
    if(option==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    positionoption.x=525;
    positionoption.y=275;
// image optionmotion1
    optionmotion=IMG_Load("optionmotion1.png");
    if(optionmotion==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
// image optionclic1
    optionclic=IMG_Load("optionclic1.png");
    if(optionclic==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }


// image play2
    playmotion=IMG_Load("playmotion1.png");
    if(playmotion==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }

// image play clic
    playclic=IMG_Load("playclic1.png");
    if(playclic==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    // new background
    new=IMG_Load("new2.png");
    if(new==NULL)
    {
        printf("Unable to load new: %s\n",SDL_GetError());
        return 1;
    }
//bonton on pour la resolution
    on=IMG_Load("on.png");
    if(on==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }
    positionon.x=535;
    positionon.y=470;
//bonton off pour la resolution
    off=IMG_Load("off.png");
    if(off==NULL)
    {
        printf("Unable to load offf: %s\n",SDL_GetError());
        return 1;
    }
























    int done=1;
    SDL_EnableKeyRepeat(30,0);
    while (done)

    {



// blit
        SDL_BlitSurface(t[i],NULL,screen,&positionecran);
        i++;
        SDL_Delay(20);
        if (i==12)
            i=0;

        SDL_BlitSurface(play,&positionecran,screen,&positionplay);

        SDL_BlitSurface(option,&positionecran,screen,&positionoption);
        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
        SDL_BlitSurface(sprite, &right[0],screen,&positionsprite);

        f=0;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT :
            {
                done=0 ;
                break;
            }
            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym==SDLK_RIGHT)
                    for (j=0; j<6; j++)
                    {
                        SDL_BlitSurface(t[0],NULL,screen,&positionecran);
                        SDL_BlitSurface(play,&positionecran,screen,&positionplay);

                        SDL_BlitSurface(option,&positionecran,screen,&positionoption);
                        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
                        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
                        positionsprite.x=positionsprite.x+5;

                        SDL_BlitSurface(sprite,&right[j],screen,&positionsprite);

                        SDL_Flip(screen);


                        SDL_Delay(50);
                    }
                else  if(event.key.keysym.sym==SDLK_LEFT)
                    for (j=0; j<6; j++)
                    {
                        SDL_BlitSurface(t[0],NULL,screen,&positionecran);
                        SDL_BlitSurface(play,&positionecran,screen,&positionplay);

                        SDL_BlitSurface(option,&positionecran,screen,&positionoption);
                        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
                        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
                        positionsprite.x=positionsprite.x-5;

                        SDL_BlitSurface(sprite,&left[j],screen,&positionsprite);

                        SDL_Flip(screen);


                        SDL_Delay(50);
                    }
                j=0;
                SDL_Flip(screen);
                break;
            }
            case SDL_KEYUP:
            {
                //deplacement du clavier down
                if(event.key.keysym.sym==SDLK_DOWN)
                {
                    switch (position)
                    {
                    case 2 :
                    {
                        SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                        Mix_PlayChannel(-1, son, 0);
                        position =0;
                        break;
                    }
                    case 0 :
                    {
                        SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                        Mix_PlayChannel(-1, son, 0);
                        position =1;
                        break;
                    }
                    case 1 :
                    {
                        SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                        Mix_PlayChannel(-1, son, 0);
                        position=2;
                        break;
                    }
                    case 3:
                    {
                        SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                        Mix_PlayChannel(-1, son, 0);
                        position =0;
                        break;
                    }
                    }
                }
                //deplacement du clavier up

                else if ( event.key.keysym.sym == SDLK_UP )
                {
                    switch (position)
                    {
                    case 1 :
                    {
                        SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                        Mix_PlayChannel(-1, son, 0);
                        position=0;
                        break;

                    }
                    case 2 :
                    {
                        SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                        Mix_PlayChannel(-1, son, 0);

                        position =1;
                        break;
                    }
                    case 0 :
                    {
                        SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                        Mix_PlayChannel(-1, son, 0);

                        position=2;
                        break;
                    }
                    case 3:
                    {
                        SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                        Mix_PlayChannel(-1, son, 0);
                        position =0;
                        break;
                    }
                    }


                }
                else if(event.key.keysym.sym==SDLK_RIGHT)
                    for (j=0; j<6; j++)
                    {
                        SDL_BlitSurface(t[0],NULL,screen,&positionecran);
                        SDL_BlitSurface(play,&positionecran,screen,&positionplay);

                        SDL_BlitSurface(option,&positionecran,screen,&positionoption);
                        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
                        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
                        positionsprite.x=positionsprite.x+5;

                        SDL_BlitSurface(sprite,&right[j],screen,&positionsprite);

                        SDL_Flip(screen);


                        SDL_Delay(50);
                    }
                else  if(event.key.keysym.sym==SDLK_LEFT)
                    for (j=0; j<6; j++)
                    {
                        SDL_BlitSurface(t[0],NULL,screen,&positionecran);
                        SDL_BlitSurface(play,&positionecran,screen,&positionplay);

                        SDL_BlitSurface(option,&positionecran,screen,&positionoption);
                        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
                        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
                        positionsprite.x=positionsprite.x-5;

                        SDL_BlitSurface(sprite,&left[j],screen,&positionsprite);

                        SDL_Flip(screen);


                        SDL_Delay(50);
                    }
                j=0;
                SDL_Flip(screen);
                break;
            }
            case SDL_MOUSEMOTION :
            {
                x=event.motion.x;
                y=event.motion.y;
                if ( x >positionplay.x && x< positionplay.x+positionplay.w && y >positionplay.y && y < positionplay.y+positionplay.h )
                {
                    SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                    Mix_PlayChannel(-1, son, 0);




                }
                else if ( x >positionoption.x && x<positionoption.x+positionoption.w && y >positionoption.y && y < positionoption.y+positionoption.h )
                {
                    SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                    Mix_PlayChannel(-1, son, 0);
                }
                else if ( x >positionexit.x && x<positionexit.x+positionexit.w && y >positionexit.y && y < positionexit.y+positionexit.h )
                {
                    SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                    Mix_PlayChannel(-1, son, 0);
                }

                break;

            }
            case SDL_MOUSEBUTTONDOWN:
            {
                a=event.button.x;
                b=event.button.y ;
                if ( a >positionplay.x && a< positionplay.x+positionplay.w && b >positionplay.y && b < positionplay.y+positionplay.h )
                {
                    SDL_BlitSurface(playclic,&positionecran,screen,&positionplay);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                    test=1;
                    done=0;

                }
                else if( a >positionoption.x && a<positionoption.x+positionoption.w && b >positionoption.y && b < positionoption.y+positionoption.h )
                {
                    SDL_BlitSurface(optionclic,&positionecran,screen,&positionoption);
                    SDL_Flip(screen);
                    SDL_Delay(50);
                    while (f==0)
                    {
                        SDL_BlitSurface(backoption,NULL,fenetre,&positionbackoption);
                        SDL_BlitSurface(point,&positionecran,fenetre,&positionpoint);
                        SDL_BlitSurface(point2,&positionecran,fenetre,&positionpoint2);
                        if(resolution==1)
                            SDL_BlitSurface(on,&positionecran,fenetre,&positionon);
                        else
                            SDL_BlitSurface(off,&positionecran,fenetre,&positionon);
                        SDL_Flip(fenetre);
                        while(SDL_PollEvent(&event2))
                        {


                            switch (event2.type)
                            {
                            case SDL_QUIT :
                            {
                                done=0 ;
                                break;
                            }
                            case SDL_MOUSEBUTTONUP :
                            {
                                x=event2.button.x;
                                y=event2.button.y;
                                if (x>520 && x<575 && y>230 && y <300)
                                    // change music
                                {
                                    positionpoint.x=550;////////////////////5
                                    Mix_VolumeMusic(MIX_MAX_VOLUME*0);
                                }
                                else if (x>580 && x<620 && y>230 && y <300)
                                {
                                    positionpoint.x=600;////////////////1
                                    Mix_VolumeMusic(MIX_MAX_VOLUME/4);
                                }
                                else if (x>620 && x<670 && y>230 && y <300)
                                {
                                    positionpoint.x=645;/////////////////4
                                    Mix_VolumeMusic(MIX_MAX_VOLUME/2);
                                }
                                else if (x>680 && x<720 && y>230 && y <300)
                                {
                                    positionpoint.x=695;///////////////////3
                                    Mix_VolumeMusic(3*MIX_MAX_VOLUME/4);
                                }
                                else if (x>720 && x<760 && y>230 && y <300)
                                {
                                    positionpoint.x=750;///////////////////2
                                    Mix_VolumeMusic(MIX_MAX_VOLUME*2);
                                } //change sound
                                else if (x>520 && x<575 && y>350 && y <420)

                                {
                                    positionpoint2.x=550;
                                    Mix_VolumeChunk(son,MIX_MAX_VOLUME*0);
                                }
                                else if (x>580 && x<620 && y>350 && y <420)
                                {
                                    positionpoint2.x=600;
                                    Mix_VolumeChunk(son,MIX_MAX_VOLUME/4);

                                }
                                else if (x>620 && x<670 && y>350 && y <420)
                                {
                                    positionpoint2.x=645;
                                    Mix_VolumeChunk(son,MIX_MAX_VOLUME/2);

                                }
                                else if (x>680 && x<720 && y>350 && y <420)
                                {
                                    positionpoint2.x=695;
                                    Mix_VolumeChunk(son,3*MIX_MAX_VOLUME/4);
                                }
                                else if (x>720 && x<760 && y>350 && y <420)
                                {
                                    positionpoint2.x=750;
                                    Mix_VolumeChunk(son,MIX_MAX_VOLUME*2);

                                }
                                /*  else if ( x>250 && x<530 && y > 500 && y<565)
                                  // appuye sur back
                                      f=1;*/
                                else if ( x<positionbackoption.x || x>positionbackoption.x+positionbackoption.w || y < positionbackoption.y || y>positionbackoption.y+positionbackoption.h)
                                    //appuye hors de la fenetre
                                    f=1;
                                //resolution full screen
                                else if(x>positionon.x && x<positionon.x+positionon.w && y>positionon.y && y<positionon.y+positionon.h )
                                {
                                    if (resolution==0)
                                    {
                                        SDL_BlitSurface(on,&positionecran,fenetre,&positionon);
                                        SDL_WM_ToggleFullScreen(fenetre);
                                       
                                        resolution=1;
                                    }
                                    else if (resolution==1)
                                    {
                                        SDL_BlitSurface(off,&positionecran,fenetre,&positionon);
                                        resolution=0;
                                        SDL_WM_IconifyWindow();
                                       
                                    }
                                }

                                break;

                            }
                            }
                            SDL_Flip(fenetre);

                        }
                    }
                }
                else if ( a >positionexit.x && a<positionexit.x+positionexit.w && b >positionexit.y && b < positionexit.y+positionexit.h )
                {
                    SDL_BlitSurface(exitclic,&positionecran,screen,&positionexit);
                    done =0;
                }
                break;
            }




            }


            SDL_Flip(screen);


        }
        if (positionsprite.x>1250)
        {
            test=2;
            done=0;
        }
        else if (positionsprite.x<50)
            done=0;

    }

    // boucle du background clic play
    if(test==1)
        while(done==0)
        {
            SDL_BlitSurface(new,NULL,screen,&positionecran);
            SDL_Flip(screen);

            while(SDL_PollEvent(&event2))
            {
                switch (event2.type)
                {
                case SDL_QUIT :
                {
                    done=1 ;
                    break;
                }
                }
            }
        }


//liberer les surfaces

    SDL_FreeSurface(background);
    SDL_FreeSurface(play);
    SDL_FreeSurface(new);
    SDL_FreeSurface(option);
    SDL_FreeSurface(exit);
    SDL_Delay(10);
    SDL_Quit();
    pause=getchar();
    Mix_FreeChunk(son);
    TTF_CloseFont(police);
    TTF_Quit();
    Mix_FreeMusic(music);
    return 0;
}

