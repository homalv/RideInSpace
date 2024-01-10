#ifndef SESSION_H
#define SESSION_H

#include "Sprite.h"
#include "Player.h"
#include <vector>
#include "EnemySpawner.h"

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
		bool getPause() const;
		void addEnemySpawner(EnemySpawner*& addedSpawn);
		void handleEndGame();
		void addPoints();
		Player* getPlayer() const;
	private:
		std::vector<Sprite*> spriteList;
		std::vector<Sprite*> added, removed;
		std::string backgroundLoc;
		Player* newPlayer;
		EnemySpawner* newSpawner;
		bool paused = false;
		Label* labelGameOver;
		Label* labelRestart;
		Label* labelQuit;
		bool inEndGame = false;
	};

	extern Session ses;
}

#endif