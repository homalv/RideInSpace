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
		static Label* getInstance(int x, int y, int w, int h, std::string txt);
		std::string getText() const;
		void setText(std::string newText);
		void setPlayer(Player* newPlayer);
		void updateLives();
		void updatePoints();
		~Label(){};
	protected:
		Label(int x, int y, int w, int h, std::string txt);
	private:
		std::string text;
		Player* playerPointer;
	};

}
#endif