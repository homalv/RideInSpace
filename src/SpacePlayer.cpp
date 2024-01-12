#include "SpacePlayer.h"
#include "Constants.h"
#include "Session.h"
#include "PlayerBullet.h"

namespace cwing 
{	
	SpacePlayer::SpacePlayer(float x, float y, float w, float h) : Player(x,y,w,h) {}

	SpacePlayer* SpacePlayer::getInstance(float x, float y, float w, float h){
		return new SpacePlayer(x, y, w, h);
	}

    void SpacePlayer::spaceKeyPressed(){
		if(getCounter() >= (FPS*1)){
			resetCounter();
			PlayerBullet* pb = PlayerBullet::getInstance(rect.x+rect.w, rect.y+(rect.h/2));
			ses.playSound("sounds/laser_shot.mp3");
			ses.add(pb);
		}
	}
}