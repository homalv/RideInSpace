#include "System.h"
#include "Constants.h"
#include "EnemyBullet.h"

namespace cwing 
{
    
	EnemyBullet::EnemyBullet(float x, float y, float currPlayerX, float currPlayerY): Bullet(x, y, width, height), playerX(currPlayerX), playerY(currPlayerY) {
        calcDist();
        // Ladda ljudfilen när en Bullet skapas
        sound_EnemyShot = Mix_LoadWAV((constants::gResPath + "sounds/laser_shot_enemy.mp3").c_str());
        // Spela upp ljudet
        Mix_PlayChannel(-1, sound_EnemyShot, 0);
    }

	EnemyBullet* EnemyBullet::getInstance(float x, float y, float currPlayerX, float currPlayerY) {
		return new EnemyBullet(x, y, currPlayerX, currPlayerY);
	}

    void EnemyBullet::tick () {

        if(rect.x < -100){
			removeThis = true;
		}
        if(rect.y < -100){
			removeThis = true;
		}
        if(rect.x + rect.w > windowWidth+100){
			removeThis = true;
		}
        if(rect.y + rect.h > windowHeight+100){
			removeThis = true;
		}

        rect.x += dists[0] * 3.0f;
        rect.y += dists[1] * 3.0f;

	}

    void EnemyBullet::calcDist(){

        std::vector<float> centerPos = getCenterPos();

        float deltaX = static_cast<float>(playerX - centerPos[0]);
        float deltaY = static_cast<float>(playerY - centerPos[1]);

        float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

        float directionX = deltaX / distance;
        float directionY = deltaY / distance;

        dists.push_back(directionX);
        dists.push_back(directionY);
    }
}