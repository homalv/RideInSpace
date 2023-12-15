#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "EnemyBullet.h"

namespace cwing 
{

	EnemyBullet::EnemyBullet(int x, int y, int currPlayerX, int currPlayerY) : Bullet(x,y,width,height){
        this->playerX = currPlayerX;
        this->playerY = currPlayerY;
        calcDist();
    }

	EnemyBullet* EnemyBullet::getInstance(int x, int y, int currPlayerX, int currPlayerY) {
		return new EnemyBullet(x, y, currPlayerX, currPlayerY);
	}

    void EnemyBullet::tick () {

        rect.x += static_cast<int>(dists[0] * 2);
        rect.y += static_cast<int>(dists[1] * 2);

		if(rect.x + rect.w > windowWidth){
			removeThis = true;
		}
	}

    void EnemyBullet::calcDist(){
        float deltaX = static_cast<float>(playerX - rect.x);
        float deltaY = static_cast<float>(playerY - rect.y);

        // Calculate the distance between current and target positions
        float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

        // Normalize the vector to maintain constant speed
        float directionX = deltaX / distance;
        float directionY = deltaY / distance;

        dists.push_back(directionX);
        dists.push_back(directionY);
    }
}