#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "PlayerBullet.h"

namespace cwing 
{

	PlayerBullet::PlayerBullet(int x, int y) : Bullet(x,y,width,height)
	{
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/NerKnapp.png").c_str() );
	}

	PlayerBullet::~PlayerBullet()
	{
		SDL_DestroyTexture(texture);
	}

	PlayerBullet* PlayerBullet::getInstance(int x, int y) {
		return new PlayerBullet(x, y);
	}

    /*

    void PlayerBullet::tick () {}

    */

	void PlayerBullet::draw() const {

		const SDL_Rect &rect = getRect();

		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	}
}