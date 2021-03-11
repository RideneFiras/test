#include"quit.h"
int quit (SDL_Surface *ecran)
{
	SDL_Surface *bg,*exit[5];
	int n=0,t,done=1;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	bg=IMG_Load("graphic/menu/background-menu.jpg");
	exit[4]=IMG_Load("graphic/menu/exit_msg.png");
    exit[0]=IMG_Load("graphic/menu/exit_msg_yes_selected.png");
	exit[1]=IMG_Load("graphic/menu/exit_msg_no_selected.png");
	exit[2]=IMG_Load("graphic/menu/exit_msg_yes_clicked.png");
	exit[3]=IMG_Load("graphic/menu/exit_msg_no_clicked.png");

    while(done)
    {
    	SDL_BlitSurface(bg,NULL,ecran,&pos);
    	SDL_BlitSurface(exit[n],NULL,ecran,&pos);
    	SDL_Flip(ecran);
    	SDL_WaitEvent(&event);

    	switch(event.type)
    	{
			//avec clavier
    		case SDL_KEYDOWN:

    		    switch(event.key.keysym.sym)
    			{
    			case SDLK_LEFT:
    				if (n==4) n=0;

                                if (n==0 && t==0)
				{
				n++;

				}
				else if (n==1 && t==0)
				{
					n--;

				}
					break;

			case SDLK_RIGHT:
				if (n==4) n=0;
				if (n==0)
				{
				        n++;

				}
				else if (n==1)
					{
						n--;

					}
					break;

			case SDLK_RETURN:
					if (n==0)
				{SDL_BlitSurface(exit[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				                SDL_Delay (200);
						SDL_FreeSurface(bg);
						SDL_FreeSurface(exit[n]);
						return 1;
				}
						else if (n==1)
						{SDL_BlitSurface(exit[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				                SDL_Delay (200);
						SDL_FreeSurface(bg);
						SDL_FreeSurface(exit[n]);
						return 0;
						}
					break;

    			        }
    		break;
// avec souris

    		case SDL_MOUSEMOTION:
			n=4;
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					n=0;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					SDL_BlitSurface(exit[2],NULL,ecran,&pos);
    				        SDL_Flip(ecran);
    				        SDL_Delay (200);
					return 1;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392 )
				{
					SDL_BlitSurface(exit[3],NULL,ecran,&pos);
    					SDL_Flip(ecran);
    				        SDL_Delay (200);
					return 0;
				}
			break;

    	}
    }

}
