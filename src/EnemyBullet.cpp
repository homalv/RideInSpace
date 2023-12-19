#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "EnemyBullet.h"

namespace cwing 
{
    
	EnemyBullet::EnemyBullet(float x, float y, float currPlayerX, float currPlayerY): Bullet(x, y, width, height), playerX(currPlayerX), playerY(currPlayerY) {
        calcDist();
    }

	EnemyBullet* EnemyBullet::getInstance(float x, float y, float currPlayerX, float currPlayerY) {
		return new EnemyBullet(x, y, currPlayerX, currPlayerY);
	}

    void EnemyBullet::tick () {

        rect.x += dists[0] * 3.0f;
        rect.y += dists[1] * 3.0f;

	}

    void EnemyBullet::calcDist(){

        float deltaX = static_cast<float>(playerX - rect.x);
        float deltaY = static_cast<float>(playerY - rect.y);

        float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

        float directionX = deltaX / distance;
        float directionY = deltaY / distance;

        dists.push_back(directionX);
        dists.push_back(directionY);
    }
}