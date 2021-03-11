
#include"animation.h"
void animation1(SDL_Surface *screen)
{
SDL_Surface *logo=NULL;
logo= IMG_Load("graphic/logo/logo.png"); 
SDL_Rect logo_pos;
logo_pos.x=0;
logo_pos.y=0;


SDL_Surface *transition;
transition=IMG_Load("graphic/transition.png");
SDL_Rect transition_pos;
transition_pos.x=0;
transition_pos.y=0;


Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);
Mix_Chunk *music;
music= Mix_LoadWAV("graphic/menu/transition.wav");
Mix_VolumeChunk(music, MIX_MAX_VOLUME/2);


Mix_PlayChannel(1,music, 0);SDL_Delay(100);
SDL_Surface *frame;
	SDL_Event event;
	char chaine2[50];
	char chaine[8];
	int i=0,j=10;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;

transition=IMG_Load("graphic/transition.png");
SDL_BlitSurface(transition,NULL,screen,&posframe);
	for(i=1;i<11;i++){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"graphic/logo/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,screen,&posframe);
		SDL_Flip(screen);
		SDL_Delay(100);
		SDL_FreeSurface(frame);

	                 }
SDL_Delay(2500);

	for(i=10;i>0;i--){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"graphic/logo/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,screen,&posframe);
		SDL_Flip(screen);
		SDL_Delay(50);
		SDL_BlitSurface(transition,NULL,screen,&transition_pos);
		SDL_FreeSurface(frame);
	}
SDL_BlitSurface(transition,NULL,screen,&transition_pos);
SDL_Flip(screen);
SDL_Delay(500);


SDL_FreeSurface(transition);
}
