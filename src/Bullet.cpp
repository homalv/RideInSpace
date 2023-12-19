#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "Bullet.h"

namespace cwing 
{

	Bullet::Bullet(float x, float y, float w, float h) : MovableSprite(x,(y-(h/2)),w,h)
	{
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/bullet.png").c_str() );
		SDL_GetWindowSize(sys.get_win(), &windowWidth, &windowHeight);
	}

	Bullet::~Bullet()
	{
		SDL_DestroyTexture(texture);
	}

	Bullet* Bullet::getInstance(float x, float y, float w, float h) {
		return new Bullet(x, y, w, h);
	}

	void Bullet::draw() const {

		const SDL_FRect &rect = getRect();

		SDL_RenderCopyF(sys.get_ren(), texture, NULL, &rect);
	}
}