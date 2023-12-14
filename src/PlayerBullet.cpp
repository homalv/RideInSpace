#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "PlayerBullet.h"

namespace cwing 
{

	PlayerBullet::PlayerBullet(int x, int y) : Bullet(x,y,width,height){}

	PlayerBullet* PlayerBullet::getInstance(int x, int y) {
		return new PlayerBullet(x, y);
	}

    void PlayerBullet::tick () {

		if(rect.x + rect.w > windowWidth){
			removeThis = true;
		}
		rect.x += 5;
	}
}