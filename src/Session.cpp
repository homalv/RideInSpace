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
#include "Enemy.h"

using namespace std;

#define FPS 80

namespace cwing 
{


	void Session::add(Sprite* sprite) {
		added.push_back(sprite);
	}

	void Session::remove(Sprite* sprite) {
		removed.push_back(sprite);
	}

	void Session::run() {
		SDL_Surface* bgSurf = IMG_Load((constants::gResPath + "images/space_bg.png").c_str()); //för bakgrundsbilden
    	SDL_Texture* bgTx = SDL_CreateTextureFromSurface(sys.get_ren(), bgSurf);  //för bakgrundsbilden
    	SDL_FreeSurface(bgSurf);
		
		bool quit = false;
		Uint32 tickInterval = 1000 / FPS, lastEnemyTimer = 0;
		Player* newPlayer = Player::getInstance(100, 100, 60, 60);
		Enemy* newEnemy;
		random_device rd;
		uniform_int_distribution<int> dist(1, 8);
		int bgWidth = 1501;  // Bredden på bakgrundsbilden
    	int bgHeight = 500;
		int bgX1 = 0;       // Position för den första kopian av bakgrundsbilden
    	int bgX2 = bgWidth; // Position för den andra kopian av bakgrundsbilden
		PlayerBullet* pb;
		bool spacePressed = false;
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
			
			Uint32 nextTick = SDL_GetTicks() + tickInterval, currentTime = SDL_GetTicks();
			SDL_Event event;

			if(currentTime - lastEnemyTimer >= 2000){
            	lastEnemyTimer = currentTime;
            	newEnemy = Enemy::getInstance(700, dist(rd) * 55, 30, 30);
				add(newEnemy);
        	}

			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode)
                    {
                    case SDL_SCANCODE_RIGHT:
                        newPlayer->setRightTrue();
                        break;
                    case SDL_SCANCODE_LEFT:
                        newPlayer->setLeftTrue();
                        break;
                    case SDL_SCANCODE_UP:
                        newPlayer->setUpTrue();
                        break;
                    case SDL_SCANCODE_DOWN:
                        newPlayer->setDownTrue();
                        break;
					case SDL_SCANCODE_SPACE:
						pb = newPlayer->shoot();
						if(pb != nullptr){
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
                        newPlayer->setRightFalse();
                        break;
                    case SDL_SCANCODE_LEFT:
                        newPlayer->setLeftFalse();
                        break;
                    case SDL_SCANCODE_UP:
                        newPlayer->setUpFalse();
                        break;
                    case SDL_SCANCODE_DOWN:
                        newPlayer->setDownFalse();
                        break;
                    default:
                        break;
                    }
					break;
				}
				 //switch
			} //inre while

			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);

			//Tick för player
			newPlayer->tick();

			if(spacePressed){
				
			}


			for (Sprite* c : spriteList){
				c->tick();
				if(c->checkRemove()){
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

			for (Sprite* c : spriteList)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		} // yttre while
	}
}
