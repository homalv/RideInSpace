#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <string>

namespace cwing 
{
	class Rectangle : public Sprite
	{
	public:
		static Rectangle* getInstance(int x, int y, int w, int h);
		void mouseDown(const SDL_Event&);
		void mouseUp(const SDL_Event&);
        void tick();
		void draw() const;
		~Rectangle();
	protected:
		Rectangle(int x, int y, int w, int h);
	private:
		std::string text;
		SDL_Texture* texture;
		SDL_Texture* upIcon, *downIcon;
		bool isDown = false;
	};
}

#endif