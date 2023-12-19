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
		void draw() const override;
		std::string getText() const;
		void setText(std::string newText);
		void setPlayer(Player* newPlayer);
		void updateLives();
		~Label();
	protected:
		Label(int x, int y, int w, int h, std::string txt);
	private:
		std::string text;
		SDL_Texture* texture;
		Player* playerPointer;
	};

}
#endif