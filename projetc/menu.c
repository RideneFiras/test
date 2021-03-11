#include "menu.h"
void menu (SDL_Surface *screen, int *continuer)
{
FILE *f=NULL;
    f=fopen("logs.txt","w");
int vm, vsfx;
read_volume (&vm,&vsfx);
//creation background
SDL_Surface *background=NULL,*TextMainMenu=NULL;
background =IMG_Load("graphic/menu/background-menu.jpg");
SDL_Rect background_pos,position;
background_pos.x=0;
background_pos.y=0;
//SDL_BlitSurface(background,NULL,screen,&background_pos);
int c=-1;
//introduction musique
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
Mix_Music *music;
music= Mix_LoadMUS("graphic/menu/background.mp3");
Mix_VolumeMusic(vm);
Mix_PlayMusic(music,-1);
Mix_Chunk *sound;
sound= Mix_LoadWAV("graphic/option/gh.wav");
if (sound==NULL)
{ 
  fprintf(f,"xxxxxx:%s",Mix_GetError());
}
Mix_VolumeChunk(sound,vsfx);
//MIX_PlayChannel(1,sound,0);

if(TTF_Init() == -1)
    {
        fprintf(f, "Erreur : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);

    }
    fprintf(f,"SDL_TTF Charger avec sucess \n");
    TTF_Font *policeTitre = NULL;
    policeTitre = TTF_OpenFont("graphic/menu/Valentime.ttf", 30);
    SDL_Color couleurBlanc = {255, 255, 255};
    SDL_Color couleurBlack = {0, 0, 0};
    SDL_Color couleurRed = {255, 0, 0};
    TextMainMenu = TTF_RenderText_Blended(policeTitre, "Menu", couleurBlanc);
    SDL_FillRect(background,NULL, SDL_MapRGB(screen->format,255,255,255 ));
    position.x=140;
    position.y=250;
    





SDL_Surface *newgame[3],*loadgame[3],*option[3],*exit[3];

	SDL_Rect pos;
	pos.x=0;
	pos.y=0;

	SDL_Event event;
	int ng=0,op=0,ex=0,lg=0,t,save;
	//chargement d'image
    newgame[0]=IMG_Load("graphic/menu/new-game-normal.png");
    loadgame[0]=IMG_Load("graphic/menu/score-normal.png");
    loadgame[2]=IMG_Load("graphic/menu/score-clicked.png");
    loadgame[1]=IMG_Load("graphic/menu/score-selected.png");
    option[0]=IMG_Load("graphic/menu/options-normal.png");
    exit[0]=IMG_Load("graphic/menu/exit-normal.png");
    newgame[1]=IMG_Load("graphic/menu/new-game-selected.png");
    newgame[2]=IMG_Load("graphic/menu/new-game-clicked.png");
    option[1]=IMG_Load("graphic/menu/options-selected.png");
    option[2]=IMG_Load("graphic/menu/options-clicked.png");
    exit[1]=IMG_Load("graphic/menu/exit-selected.png");
    exit[2]=IMG_Load("graphic/menu/exit-clicked.png");

SDL_EnableKeyRepeat(0,0);
    int i=1;
	char filename[64];
    int done=1;
	

    while (done)
    {
    //affichage des images
	    //SDL_BlitSurface(background,NULL,screen,&background_pos);
	    //SDL_BlitSurface(background,NULL,screen,&pos);
        //SDL_BlitSurface(loadgame[lg],NULL,screen,&pos);
        //SDL_BlitSurface(option[op],NULL,screen,&pos);
       // SDL_BlitSurface(newgame[ng],NULL,screen,&pos);
       // SDL_BlitSurface(exit[ex],NULL,screen,&pos);
		//animate the background
       if (i != 0)
        //SDL_FreeSurface(background);
        sprintf(filename,"background/%d.png",i);
        //screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
        SDL_BlitSurface(background,NULL,screen,&pos); 
        background = IMG_Load(filename);
        
	SDL_BlitSurface(loadgame[lg],NULL,screen,&pos);
        SDL_BlitSurface(option[op],NULL,screen,&pos);
        SDL_BlitSurface(newgame[ng],NULL,screen,&pos);
        SDL_BlitSurface(exit[ex],NULL,screen,&pos);
		SDL_BlitSurface(TextMainMenu,NULL,screen,&position);
        i++;
        if (i > 20)
        {
            i = 0;
        }
        SDL_Flip(screen);
    	t=0;
    	if (SDL_WaitEvent(&event)){
    	switch(event.type)
{
case SDL_QUIT :
(*continuer)=0;
c=0;
break;

    		//avec clavier
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym){

    				case SDLK_UP:
    				if (ng==0 && op==0 && ex==0 && lg==0)
    				{lg=1;
					Mix_PlayChannel(1,sound,0);
					SDL_Delay(500);
					}
    					if (ng==1 && t==0){
    						ex=1;
    						ng=0;
    						op=0;
    						//t=1;
                        Mix_PlayChannel(1,sound,0);
    					}
    					else if(op==1 && t==0){
    						if (lg==0)
                            {
                                ng=0;
                                lg=1;
                                op=0;
                                ex=0;
                               // t=1;
                                Mix_PlayChannel(1,sound,0);
                            }
                            else{
                                ng=1;
                                op=0; Mix_PlayChannel(1,sound,0);
                                ex=0;
                               // t=1;
                            }
    					}
    					else if (ex==1 && t==0){
    						op=1;
    						ex=0;Mix_PlayChannel(1,sound,0);
    						ng=0;
    						//t=1;
    					}
                        else if (lg==1 && t==0)
                        {
                            ng=1;
                            lg=0;
                            op=0; Mix_PlayChannel(1,sound,0);
                            ex=0;
                           // t=1;
                        }
    				break;

    				case SDLK_DOWN:
    				if (ng==0 && op==0 && ex==0 && lg==0)
    				{ex=1;}
    					if (ng==1 && t==0){
    						if (lg==0)
                            {
                                ng=0;
                                lg=1;
                                op=0;Mix_PlayChannel(1,sound,0);
                                ex=0;
                               // t=1;
                            }
                            else{
                                ng=0;
                                op=1;
                                ex=0;Mix_PlayChannel(1,sound,0);
                              //  t=1;
                            }
    					}
    					else if(op==1 && t==0){
    						ng=0;
    						op=0;Mix_PlayChannel(1,sound,0);
    						ex=1;
    						//t=1;
    					}
    					else if (ex==1 && t==0){
    						op=0;
    						ex=0;
    						ng=1;Mix_PlayChannel(1,sound,0);
    						//t=1;
    					}
                        else if (lg==1 && t==0)
                        {
                            ng=0;
                            lg=0;
                            op=1; Mix_PlayChannel(1,sound,0);
                            ex=0;
                           // t=1;
                        }
    				break;

    				case SDLK_RETURN:
    					if (ng==1)
    					{
    						SDL_BlitSurface(newgame[2],NULL,screen,&pos);
    						SDL_Flip(screen);
    						SDL_Delay(100);
(*continuer)=1;
                   c=1;
    					}
    					else if (op==1)
    					{
    						SDL_BlitSurface(option[2],NULL,screen,&pos);
    						SDL_Flip(screen);
    						SDL_Delay(100);

    					(*continuer)=2;
							c=0;
    					}
							else if (ex==1)
	    				{
	    			SDL_BlitSurface(exit[2],NULL,screen,&pos);
	    						SDL_Flip(screen);
	    				SDL_Delay (200);
						if (quit(screen)==1){
								(*continuer)=0;
						c= 0;}
	    				}
                        else if (lg==2)
                        { 
                          SDL_BlitSurface(loadgame[2],NULL,screen,&pos);
    						SDL_Flip(screen);
    						SDL_Delay(100);
                      (*continuer)=3;
                      c=0;  }
    				break;
    			}
    		break;

//avec souris
    		case SDL_MOUSEMOTION:

    				ex=0;
    				ng=0;
    				op=0;
    				lg=0;
    			if (event.motion.x>60 && event.motion.y>300 && event.motion.x<320 && event.motion.y<350 )
    			{
    			    ng=1; Mix_PlayChannel(1,sound,0);

    			}

    			else if (event.motion.x>60 && event.motion.y>420 && event.motion.x<320 && event.motion.y<470 )
    			{
    				op=1;
					Mix_PlayChannel(1,sound,0);

    			}
    			else if (event.motion.x>60 && event.motion.y>365 && event.motion.x<320 && event.motion.y<410 )
    			{
    				lg=1; Mix_PlayChannel(1,sound,0);

    			}
    			else if (event.motion.x>60 && event.motion.y>490 && event.motion.x<320 && event.motion.y<560 )
    			{
    				ex=1; Mix_PlayChannel(1,sound,0);
    			}

    		break;

    		case SDL_MOUSEBUTTONDOWN:
    			if (event.button.button==SDL_BUTTON_LEFT)
    			{
    				if (ng==1)
    				{
    					ng=2;
    					SDL_Delay (100);
    			(*continuer)=1;
					c=0;
    				}
    				else if (op==1)
    				{
    				op=2;
    				SDL_Delay (100);
    			(*continuer)=2;
					c=0;
    				}
    				else if (lg==1)
    				{
    				lg=2;
    				SDL_Delay (100);
    			(*continuer)=3;
					c=0;
    				}
    				else if (ex==1)
    				{
    			SDL_BlitSurface(exit[2],NULL,screen,&pos);
    						SDL_Flip(screen);
    				SDL_Delay (200);
					if (quit(screen)==1){
							(*continuer)=0;
					c= 0;}
    				}
    			}
    		break;


    	}

    	}
if (c==0) break;
 }
    	SDL_FreeSurface(background);
    	SDL_FreeSurface(newgame[2]);
    	SDL_FreeSurface(option[2]);
    	SDL_FreeSurface(exit[2]);
    	SDL_FreeSurface(newgame[0]);
    	SDL_FreeSurface(newgame[1]);
    	SDL_FreeSurface(option[0]);
    	SDL_FreeSurface(option[1]);
    	SDL_FreeSurface(loadgame[0]);
    	SDL_FreeSurface(exit[0]);
    	SDL_FreeSurface(exit[1]);
		
		TTF_CloseFont(policeTitre);
        Mix_FreeMusic(music);
}




