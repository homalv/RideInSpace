#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "Bullet.h"

namespace cwing 
{

	Bullet::Bullet(int x, int y, int w, int h) : MovableSprite(x,(y-(h/2)),w,h)
	{
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/bullet.png").c_str() );
		SDL_GetWindowSize(sys.get_win(), &windowWidth, &windowHeight);
	}

	Bullet::~Bullet()
	{
		SDL_DestroyTexture(texture);
	}

	Bullet* Bullet::getInstance(int x, int y, int w, int h) {
		return new Bullet(x, y, w, h);
	}

	void Bullet::draw() const {

		const SDL_Rect &rect = getRect();

		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	}
}