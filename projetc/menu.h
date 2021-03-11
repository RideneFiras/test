#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "quit.h"
#include "option.h"



void menu (SDL_Surface *screen, int *continuer);

#endif // MENU_H_INCLUDED
