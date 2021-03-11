#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



void read_volume (int *music, int *sfx);
void save_volume (int *music, int *sfx);
int windo(SDL_Surface *ecran);
int fullscreen(SDL_Surface *ecran);
void options(SDL_Surface *screen,int *action);



#endif // OPTION_H_INCLUDED
