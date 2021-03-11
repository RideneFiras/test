#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include"animation.h"
#include "option.h"
int main()
{int continuer=-1,a=-1;
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen=NULL;
screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("BRAINSTORM\t!",NULL);
animation1(screen);
do{menu(screen,&continuer);
switch(continuer)
{case 1 ://new game 
case 2 :options(screen,&a);
break;}
}while (continuer != 0);
SDL_Quit();
return 0 ;}
