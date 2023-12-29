#include "Session.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Player.h"
#include <typeinfo>
#include "PlayerBullet.h"
#include "Constants.h"
#include <random>
#include <vector>
#include "Enemy.h"
#include "EnemyBullet.h"
#include "GamePanel.h"
#include "Label.h"
#include <iostream>

using namespace std;

#define FPS 80

namespace cwing 
{
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

	void Session::addPlayer(Player* addedPlayer){
		newPlayer = addedPlayer;
	}

	void Session::setPause(bool value){
		paused = value;
	}

	void Session::playSound(std::string soundLocInput){
		Mix_Chunk* sound = Mix_LoadWAV((constants::gResPath + soundLocInput).c_str());
		Mix_PlayChannel(-1, sound, 0);
	}

	void Session::run() {		
		Enemy* vektor[8] = {nullptr};
		int position;
		SDL_Surface* bgSurf = IMG_Load((constants::gResPath + backgroundLoc).c_str()); 
    	SDL_Texture* bgTx = SDL_CreateTextureFromSurface(sys.get_ren(), bgSurf); 
    	SDL_FreeSurface(bgSurf);
		
		//bool pause = false;
		bool quit = false;
		Uint32 tickInterval = 1000 / FPS, lastEnemyTimer = 0, playerHitTimer = 4000;
		Enemy* newEnemy;

		/*

		Label* actualPoints = Label::getInstance(220, 13, 22 , std::to_string(newPlayer->getPoints()),nullptr, 60, 0, 10);
		actualPoints->setPlayer(newPlayer);
		add(actualPoints);

		Label* actualLives = Label::getInstance(220, 38, 22 , std::to_string(newPlayer->getLives()),nullptr, 60, 0, 10);
		actualLives->setPlayer(newPlayer);
		add(actualLives);

		*/



		random_device rd;
		uniform_int_distribution<int> dist(1, 8);
		int bgWidth = 1501;  // Bredd  och höjd bakgrundsbild
    	int bgHeight = 520;
		int bgX1 = 0;       // Position för första kopian av bakgrundsbild
    	int bgX2 = bgWidth; // Position för andra kopian av bakgrundsbild
		PlayerBullet* pb;
		EnemyBullet* eb;
		Label* labelGameOver = Label::getInstance(300 , 250, 64, "GAME OVER" , 85, 0, 14);
		Label* labelRestart = Label::getInstance(300, 360, 34, "RESTART   "  , 150, 150, 150);
		Label* labelQuit = Label::getInstance(300, 440, 34, "QUIT      "  , 150, 150, 150);
		
		while (!quit) {
			// Uppdatera x-positionerna för båda kopior av bakgrundsbilden
        	bgX1 -= 1;
        	bgX2 -= 1;
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

			if(newPlayer->getLives()<1){
				if(startDelayTime == 0)	{											
					paused = true;	
					newPlayer->setHit(true);											
					add(labelGameOver);
					startDelayTime = SDL_GetTicks();
				} 
				else if ( SDL_GetTicks() - startDelayTime >= 3000) {										
					add(labelRestart);						
					add(labelQuit);					
					startDelayTime = 0;										
				}													
			}
			
			Uint32 nextTick = SDL_GetTicks() + tickInterval, currentTime = SDL_GetTicks();
			SDL_Event event;
			if( !paused && currentTime - lastEnemyTimer >= 4000){
            	position = dist(rd);
				
				while(vektor[position - 1] != nullptr){
					position = dist(rd);
				}

				newEnemy = Enemy::getInstance(700, position * 55, 40, 40, 1);
				vektor[position-1] = newEnemy;
				lastEnemyTimer = currentTime;
				add(newEnemy);
        	}

			/*
			if(currentTime - lastEnemyTimer >= 2000){
            	lastEnemyTimer = currentTime;
				std::vector centerPos = newPlayer->getCenterPos();
            	EnemyBullet* eBullet = EnemyBullet::getInstance(400, 300, centerPos[0], centerPos[1]);
				add(eBullet);
        	}
			*/


			while (SDL_PollEvent(&event)) {				
				switch (event.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_KEYDOWN:
				if(!paused){
                    switch (event.key.keysym.scancode)
                    {
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
						pb = newPlayer->shoot();
						if(pb != nullptr && !paused){
							add(pb);
						}
						break;
                    default:
                        break;
                    }
                    break;
					
                case SDL_KEYUP:
                    switch (event.key.keysym.scancode)
                    {
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
				}	

				case SDL_MOUSEBUTTONDOWN:
				int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);
				float mouseXFloat = static_cast<float>(mouseX);
				float mouseYFloat = static_cast<float>(mouseY);
				
					if (labelRestart->isPointInside(mouseXFloat, mouseYFloat)){						
						newPlayer->resetPlayer();
						remove(labelQuit);
						remove(labelGameOver);
						remove(labelRestart);
						//actualLives->updateLives();
						//actualPoints->updatePoints();
						for (int i = 0; i < 8; ++i) {
							remove(vektor[i]);
							vektor[i] = nullptr;
						}
						lastEnemyTimer = SDL_GetTicks(); 
						paused = false;
					}
				
					if (labelQuit->isPointInside(mouseXFloat, mouseYFloat)){																		
						GamePanel* gameOverPanel = GamePanel::getInstance(1,1, 700, 520);	
						add(gameOverPanel);
						Label* labelGoodBye = Label::getInstance(220, 240, 64, "GOOD BYE!"  , 60, 0, 10);
						add(labelGoodBye);							
						startDelayTime = SDL_GetTicks();
						//SDL_Delay(1500);
						quit = true;																									
					}
				
				break;
				}
				 //switch
			} //inre while

			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);

			//Tick för player
			newPlayer->tick();

			for (Sprite* c : spriteList){
				c->tick();
				if(c->checkRemove()){
					vektor[position-1]= nullptr;
					remove(c);
				}
			}

			for (Sprite* c : added)
				spriteList.push_back(c);
			added.clear();

			for (Sprite* c : removed) {
				for (vector<Sprite*>::iterator i = spriteList.begin();
					i != spriteList.end();)
				{
					if (*i == c) 
					{
						i = spriteList.erase(i);
					}
					else {
						i++;
					}
				}
			}
			removed.clear();

			//SDL_SetRenderDrawColor(sys.get_ren(), 0, 0, 35, 255);
			//SDL_RenderClear(sys.get_ren());

			//Draw för player
			newPlayer->draw();


			for	(Sprite* c1 : spriteList){
				Enemy* enemy = dynamic_cast<Enemy*>(c1);
				if(enemy != nullptr){
					for(Sprite* c2 : spriteList){
						newEnemy->checkCollision(*c2);
					}
				}
				if(newPlayer->checkCollision(*c1) && currentTime - playerHitTimer >= 3000){
					playerHitTimer = currentTime;
					//pause = true;
					//newPlayer->setHit(true);       // Här anropas en ny bild via setHit. 
					//Mix_PlayChannel(-1, hit_sound, 0);
					/*														
					for (int i = 0; i < 8; ++i) {  
						remove(vektor[i]); //Tömmer hela vektorn på fiender så det blir lite lugnt.
						vektor[i] = nullptr;
					}
					*/
					//newPlayer->looseLife();
					//actualLives->updateLives();
				}
				if(PlayerBullet* playerBullet = dynamic_cast<PlayerBullet*>(c1)){
					if(playerBullet != nullptr){
						if(newEnemy->checkCollision(*playerBullet)){						
						newPlayer->addPoints();
						//actualPoints->updatePoints();
						newEnemy->looseLife();
						newEnemy->draw();
						}
					}
				} 

				Enemy* enemyObject = dynamic_cast<Enemy*>(c1);
				if(!paused && enemyObject != nullptr){
					eb = enemyObject->shoot(newPlayer->getRect().x, newPlayer->getRect().y);

					if(!paused && eb != nullptr && !paused){
						add(eb);
					}
				}
			}

			if (newPlayer->isHit() && currentTime - playerHitTimer >= 3000  && newPlayer->getLives()>0) {
    			// Om det har gått 2 sekunder sedan träffen, återställ skeppet
    			newPlayer->setHit(false);
				paused = false;
			}

			for (Sprite* c : spriteList)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		} // yttre while
	}

	Session ses;
}
