#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "PlayerBullet.h"

namespace cwing 
{

	PlayerBullet::PlayerBullet(int x, int y) : Bullet(x,y,width,height)
	{	
		SDL_GetWindowSize(sys.get_win(), &windowWidth, &windowHeight);
	}

	PlayerBullet::~PlayerBullet(){}

	PlayerBullet* PlayerBullet::getInstance(int x, int y) {
		return new PlayerBullet(x, y);
	}

    void PlayerBullet::tick () {
		counter++;
		if(rect.x + rect.w > windowWidth){
			removeThis = true;
		}
		if (counter % 1 == 0){
			rect.x += 5;
		}
	}
}