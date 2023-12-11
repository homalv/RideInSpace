#include "Session.h"
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "System.h"
#include "Player.h"
#include <typeinfo>

using namespace std;

#define FPS 80

namespace cwing 
{


	void Session::add(Sprite* comp) {
		added.push_back(comp);
	}

	void Session::remove(Sprite* comp) {
		removed.push_back(comp);
	}

	void Session::run() {
		bool quit = false;
		Uint32 tickInterval = 1000 / FPS;
		Player* newPlayer = Player::getInstance(100, 100, 40, 40);
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT: quit = true; break;
				/*
				case SDL_MOUSEBUTTONDOWN:
					for (Sprite* c : spriteList){
						c->mouseDown(event);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					for (Sprite* c : spriteList)
						c->mouseUp(event);
					break;
				*/
				case SDL_KEYDOWN:
					switch (event.key.keysym.scancode)
					{
					case SDL_SCANCODE_RIGHT:
						newPlayer->updateRight();
						break;
					case SDL_SCANCODE_LEFT:
						newPlayer->updateLeft();
						break;
					case SDL_SCANCODE_UP:
						newPlayer->updateUp();
						break;
					case SDL_SCANCODE_DOWN:
						newPlayer->updateDown();
						break;
					default:
						break;
					}
					break;
				case SDL_KEYUP:
					switch (event.key.keysym.scancode)
					{
					case SDL_SCANCODE_RIGHT:
						newPlayer->updateRight();
						break;
					case SDL_SCANCODE_LEFT:
						newPlayer->updateLeft();
						break;
					case SDL_SCANCODE_UP:
						newPlayer->updateUp();
						break;
					case SDL_SCANCODE_DOWN:
						newPlayer->updateDown();
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

			for (Sprite* c : spriteList){
				c->tick();
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

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());

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
