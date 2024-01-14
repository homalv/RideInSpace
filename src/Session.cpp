#include "Session.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Sprite.h"
#include "System.h"
#include "Player.h"
#include <typeinfo>
#include "PlayerBullet.h"
#include "Constants.h"
#include <random>
#include "Enemy.h"
#include "EnemyBullet.h"
#include "GamePanel.h"
#include "Label.h"

namespace SpelMotor {

	Uint32 startDelayTime = 0; 
	
	void Session::add(Sprite* sprite) {
		added.push_back(sprite);
	}

	void Session::remove(Sprite* sprite) {
		removed.push_back(sprite);
	}

	void Session::addBackground(std::string backgroundLocInput){
		backgroundLoc = backgroundLocInput;
	}

	void Session::addPlayer(Player* addPlayer){
		newPlayer = addPlayer;
	}

	void Session::setPause(bool value){
		paused = value;
	}

	bool Session::getPause() const {
		return paused;
	}

	Player* Session::getPlayer() const {
		return newPlayer;
	}

	void Session::addPoints(){
		newPlayer->addPoints();
	}

	void Session::playSound(std::string soundLocInput){
		Mix_Chunk* sound = Mix_LoadWAV((constants::gResPath + soundLocInput).c_str());
		Mix_PlayChannel(-1, sound, 0);
	}

	void Session::addBackgroundMusic(std::string bgMLoc){
		Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
		Mix_Music* backgroundMusic = Mix_LoadMUS((constants::gResPath + bgMLoc).c_str());
		Mix_PlayMusic(backgroundMusic, -1);		
	}

	void Session::handleEndGame(){
		if(startDelayTime == 0)	{
			endGamelabels.push_back(labelGameOver);								
			paused = true;										
			//add(labelGameOver);
			startDelayTime = SDL_GetTicks();
		} else if (SDL_GetTicks() - startDelayTime >= 3000 && inEndGame == false) {										
			//add(labelRestart);						
			//add(labelQuit);
			endGamelabels.push_back(labelRestart);
    		endGamelabels.push_back(labelQuit);	
			inEndGame = true;														
		}	
	}

	void Session::run() {			
		SDL_Surface* bgSurf = IMG_Load((constants::gResPath + backgroundLoc).c_str()); 
    	SDL_Texture* bgTx = SDL_CreateTextureFromSurface(sys.get_ren(), bgSurf); 
    	SDL_FreeSurface(bgSurf);
		bool quit = false;
		Uint32 tickInterval = 1000 / FPS;

		int bgWidth = 1501;  // Bredd  och höjd bakgrundsbild
    	int bgHeight = 520;
		int bgX1 = 0;       // Position för första kopian av bakgrundsbild
    	int bgX2 = bgWidth; // Position för andra kopian av bakgrundsbild

		labelGameOver = Label::getInstance(300 , 250, 64, "GAME OVER" , 85, 0, 14);
		labelRestart = Label::getInstance(300, 360, 34, "RESTART   "  , 150, 150, 150);
		labelQuit = Label::getInstance(300, 440, 34, "QUIT      "  , 150, 150, 150);

		while (!quit) {
			// Uppdatera x-positionerna för båda kopior av bakgrundsbilden
        	bgX1 -= 3;
        	bgX2 -= 3;
			if (bgX1 <= -bgWidth) { 
				bgX1 = bgX2 + bgWidth; // Återställ bgX1
	        }
			if (bgX2 <= -bgWidth) { // Återställ bgX2
				bgX2 = bgX1 + bgWidth;
        	}
			// Ritar den första kopien av bakgrundsbilden
        	SDL_Rect srcRect1 = {0, 0, bgWidth, bgHeight};
        	SDL_Rect destRect1 = {bgX1, 0, bgWidth, bgHeight};
        	SDL_RenderCopy(sys.get_ren(), bgTx, &srcRect1, &destRect1);
        	// Ritar den andra kopien av bakgrundsbilden för sömlös loop
        	SDL_Rect srcRect2 = {0, 0, bgWidth, bgHeight};
        	SDL_Rect destRect2 = {bgX2, 0, bgWidth, bgHeight};
        	SDL_RenderCopy(sys.get_ren(), bgTx, &srcRect2, &destRect2); 
			
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;

			float mouseXFloat, mouseYFloat;
			while (SDL_PollEvent(&event)) {				
				switch (event.type) {
					case SDL_QUIT: quit = true; 
						break;
					case SDL_KEYDOWN:
						if(!paused){
                    		switch (event.key.keysym.scancode){
                    			case SDL_SCANCODE_RIGHT:
                        			newPlayer->move(SDL_SCANCODE_RIGHT);
                        			break;
                    			case SDL_SCANCODE_LEFT:
                        			newPlayer->move(SDL_SCANCODE_LEFT);
                        			break;
                    			case SDL_SCANCODE_UP:
                        			newPlayer->move(SDL_SCANCODE_UP);
                        			break;
                    			case SDL_SCANCODE_DOWN: 
                        			newPlayer->move(SDL_SCANCODE_DOWN);
                        			break;
								case SDL_SCANCODE_SPACE:
									newPlayer->spaceKeyPressed();
									break;
                    			default:
                        			break;
							}		
                    	}
                    	break;

                	case SDL_KEYUP:
                    	switch (event.key.keysym.scancode){
                    		case SDL_SCANCODE_RIGHT:
                        		newPlayer->stop(SDL_SCANCODE_RIGHT);
                        		break;
                    		case SDL_SCANCODE_LEFT:
                        		newPlayer->stop(SDL_SCANCODE_LEFT);
                        		break;
                    	case SDL_SCANCODE_UP:
                        		newPlayer->stop(SDL_SCANCODE_UP);
                        		break;
                    	case SDL_SCANCODE_DOWN:
                        		newPlayer->stop(SDL_SCANCODE_DOWN);
                        		break;
                    	default:
                        	break;
                    	}
						break;
						

					case SDL_MOUSEBUTTONDOWN:
						int mouseX, mouseY;
						SDL_GetMouseState(&mouseX, &mouseY);
						mouseXFloat = static_cast<float>(mouseX);
						mouseYFloat = static_cast<float>(mouseY);

						if (labelRestart->isPointInside(mouseXFloat, mouseYFloat)) {
							newPlayer->reset();
							/*
							remove(labelQuit);
							remove(labelGameOver);
							remove(labelRestart);
							*/
							endGamelabels.clear();
							startDelayTime = 0;
							paused = false;
							inEndGame = false;
						}
				
						if (labelQuit->isPointInside(mouseXFloat, mouseYFloat)){																		
							GamePanel* gameOverPanel = GamePanel::getInstance(1,1, 700, 520);	
							add(gameOverPanel);
							Label* labelGoodBye = Label::getInstance(220, 240, 64, "GOOD BYE!"  , 60, 0, 10);
							add(labelGoodBye);							
							startDelayTime = SDL_GetTicks();
							quit = true;																									
						}
						break;
					default:
						break;	
				} //switch
			} //inre while

			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);
			newPlayer->tick();		
			for (Sprite* c : spriteList){
				c->tick();
				if(c->checkRemove()){
					remove(c);
				}
			}

			for (Sprite* c : added){
				spriteList.push_back(c);
			added.clear();
			}
			for (Sprite* c : removed){
				for (std::vector<Sprite*>::iterator i = spriteList.begin(); i != spriteList.end();){
					if (*i == c){
						delete *i;				
						i = spriteList.erase(i);
					} else {
						i++;
					}
				}
			}
			removed.clear();

			for	(Sprite* c1 : spriteList){
				for(Sprite* c2 : spriteList){

					c1->checkCollision(*c2);
				}
				newPlayer->checkCollision(*c1);
			}

			newPlayer->draw();

			for (Sprite* c : spriteList)
				c->draw();

			for (Label* l : endGamelabels)
				l->draw();

			SDL_RenderPresent(sys.get_ren());
			//std::cout << "Sprite draw" << std::endl;
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0){
				SDL_Delay(delay);
			}
		} // yttre while
	}

	Session ses;
}
