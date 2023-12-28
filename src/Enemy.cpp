#include "MovableSprite.h"
#include "Enemy.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"

namespace cwing 
{  
    Enemy::Enemy(float x, float y, float w, float h, int lives) : MovableSprite(x,y,w,h){
        this->lives = lives;
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/enemy2.png").c_str() );
	}

    Enemy* Enemy::getInstance(float x, float y, float w, float h, int lives) {
        return new Enemy(x, y, w, h, lives);
    }
        
    void Enemy::tick() {
        if(rect.x + rect.w < 0){
			removeThis = true;
		}else if(rect.x == 500){
            currTimer = SDL_GetTicks();
            if(stopTimer == 0){
                stopTimer = SDL_GetTicks();
            }
            if(currTimer - stopTimer >= 7000){
                rect.x--;
            }
        } else {
            rect.x -= 5;  
        }
    };

    void Enemy::looseLife(){
		this->lives --;
	};

    EnemyBullet* Enemy::shoot(float playerX, float playerY){
        shootTimer = SDL_GetTicks();
        if(stopShootTimer == 0){
                stopShootTimer = SDL_GetTicks();
        }
        if(shootTimer - stopShootTimer >= 2000){
            stopShootTimer = shootTimer;
            return EnemyBullet::getInstance(rect.x, rect.y, playerX, playerY);
        }
        return nullptr;
    }
}
