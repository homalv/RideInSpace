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
        enemyHitbox.x = rect.x;
    	enemyHitbox.y = rect.y-10;
    	enemyHitbox.w = 40;
    	enemyHitbox.h = rect.h-10;
	}

    Enemy* Enemy::getInstance(float x, float y, float w, float h, int lives) {
        return new Enemy(x, y, w, h, lives);
    }        

    void Enemy::isDead(){
        if (lives<1) {
            // Byt ut texturvägen när enemy träffats.
            texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/enemy_crash.png").c_str());
        }
    }

    int Enemy::getLives(){
		return lives;
	};

    void Enemy::tick() {
        if(rect.x + rect.w < 0){
                removeThis = true;
        } 
        else{
            rect.x -= 5;  
        }
    }; 

    void Enemy::looseLife(){
		lives --;
        if(lives<1)
        isDead();
	};

    bool Enemy::checkCollision(const Sprite& other) const{
		const MovableSprite* movableOther = dynamic_cast<const MovableSprite*>(&other);
		if(movableOther){
			return SDL_HasIntersectionF(&enemyHitbox, &other.getRect());
		}
		return false;
	}
 
}
