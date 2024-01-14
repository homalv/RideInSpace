#ifndef SESSION_H
#define SESSION_H

#include "Sprite.h"
#include "Player.h"
#include <vector>
#include "Label.h"

namespace spelmotor
{
	class Session
	{
	public:
		void add(Sprite* spriteList);
		void remove(Sprite* spriteList);
		void run();
		void addBackground(std::string backgroundLocInput);
		void setPause(bool value);
		void playSound(std::string soundLoc);
		void addPlayer(Player* addPlayer);
		bool getPause() const;
		void handleEndGame();
		void addBackgroundMusic(std::string bgMLoc);
		Player* getPlayer() const;
		void addPoints();
	private:
		std::vector<Sprite*> spriteList;
		std::vector<Sprite*> added, removed;
		std::vector<Label*> endGamelabels;
		std::string backgroundLoc;
		bool paused = false;
		Label* labelGameOver;
		Label* labelRestart;
		Label* labelQuit;
		Player* newPlayer;
		bool inEndGame = false;
	};

	extern Session ses;
}

#endif