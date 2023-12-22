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
		void gameOver();
		void playGame();
		//Player const player;
	private:
		std::vector<Sprite*> spriteList;
		std::vector<Sprite*> added, removed;
		enum GameState {
            Playing,
            GameOver
        };
        GameState gameState = Playing; 
	};
}

#endif