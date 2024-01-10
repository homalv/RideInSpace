#include "System.h"
#include "Constants.h"
#include "PlayerBullet.h"

namespace cwing 
{

	PlayerBullet::PlayerBullet(float x, float y) : Bullet(x,y,width,height){
		// Ladda ljudfilen när en Bullet skapas
        sound_PlayerShot = Mix_LoadWAV((constants::gResPath + "sounds/laser_shot.mp3").c_str());
        // Spela upp ljudet
        Mix_PlayChannel(-1, sound_PlayerShot, 0);
	}

	PlayerBullet* PlayerBullet::getInstance(float x, float y) {
		return new PlayerBullet(x, y);
	}

    void PlayerBullet::tick () {

		if(rect.x + rect.w > windowWidth){
			removeThis = true;
		}
		rect.x += 10;
	}
}