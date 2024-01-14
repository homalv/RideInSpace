#include "System.h"
#include "Constants.h"
#include "Bullet.h"

namespace spacerider {
	Bullet::Bullet(float x, float y, float w, float h) : MovableSprite(x,(y-(h/2)),w,h){
		setTexture("images/bullet.png");        		
	}

	Bullet* Bullet::getInstance(float x, float y, float w, float h) {
		return new Bullet(x, y, w, h);
	}
}