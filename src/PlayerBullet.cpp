#include "System.h"
#include "Constants.h"
#include "PlayerBullet.h"

namespace spacerider {
	PlayerBullet::PlayerBullet(float x, float y) : Bullet(x,y,width,height){}

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