#include "MovableSprite.h"

namespace SpelMotor{
    std::vector<float> MovableSprite::getCenterPos(){
		std::vector<float> centerPos(2);
		centerPos[0] = getRect().x + getRect().w / 2;
		centerPos[1] = getRect().y + getRect().h / 2;
		return centerPos;
    };
}