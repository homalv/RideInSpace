#ifndef SESSION_H
#define SESSION_H

#include "Sprite.h"
#include "Player.h"
#include <vector>

namespace cwing 
{
	class Session
	{
	public:
		void add(Sprite* spriteList);
		void remove(Sprite* spriteList);
		void run();
		void addBackground(std::string backgroundLocInput);
		void addPlayer(Player* addedPlayer);
		void setPause(bool value);
		void playSound(std::string soundLoc);
	private:
		std::vector<Sprite*> spriteList;
		std::vector<Sprite*> added, removed;
		std::string backgroundLoc;
		Player* newPlayer;
		bool paused = false;
	};

	extern Session ses;
}

#endif