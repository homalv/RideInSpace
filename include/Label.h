#ifndef LABEL_H
#define LABEL_H

#include "Sprite.h"
#include "Player.h"
#include <string>
#include <SDL2/SDL.h>

namespace cwing 
{

	class Label: public Sprite
	{
	public:

		static Label* getInstance(int x, int y, int fontSize, std::string txt, Uint8 r=0, Uint8 g=0, Uint8 b=0);
		std::string getText() const;
		void setText(std::string newText);
		//void setPlayer(Player* newPlayer);
		int getWidth() const;
		int getHeight() const;
		bool isPointInside(float x, float y)const;
		//void tick();
		//void getPlayerLives();
		~Label(){};

	protected:
		Label(int x, int y, int fontSize, std::string txt, Uint8 r, Uint8 g, Uint8 b);
	private:
		std::string text;
		int currLives;
		int currPoints;
		//Player* playerPointer;
		int width;
		int height;
	};

}
#endif