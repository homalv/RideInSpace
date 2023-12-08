#include "Constants.h"
#include "Rectangle.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <SDL2/SDL_image.h>

namespace cwing 
{

	Rectangle::Rectangle(int x, int y, int w, int h):Component(x,y,w,h)
	{
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/NerKnapp.png").c_str() );
	}

	Rectangle::~Rectangle()
	{
		SDL_DestroyTexture(texture);
	}

	Rectangle* Rectangle::getInstance(int x, int y, int w, int h) {
		return new Rectangle(x, y, w, h);
	}

	void Rectangle::mouseDown(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect()))
			isDown = true;
	}

	void Rectangle::mouseUp(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect()))
			isDown = false;
	}

    void Rectangle::tick (int mouseX, int mouseY) {
		if (isDown){
            rect.y = mouseY;
            rect.x = mouseX;
        }
	}

	void Rectangle::draw() const {

		const SDL_Rect &rect = getRect();

		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	}
}