#include "MovableSprite.h"
#include "Enemy.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "Session.h"
#include <iostream>

namespace cwing 
{  
    Enemy::Enemy(float x, float y, float w, float h, int livesInput) : MovableSprite(x,y,w,h){
        lives= livesInput;
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/enemy2.png").c_str() );
        enemyHitbox.x = rect.x;
    	enemyHitbox.y = rect.y;
    	enemyHitbox.w = rect.w;
    	enemyHitbox.h = rect.h;
	}

    Enemy* Enemy::getInstance(float x, float y, float w, float h, int lives) {
        return new Enemy(x, y, w, h, lives);
    }        

    void Enemy::looseLife(){
		lives --;
        if(lives<1)
            dies();
	};


    void Enemy::dies(){        
        // Byt ut texturvägen när enemy träffats.
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/enemy_crash.png").c_str());
        
    }

    int Enemy::getLives() const {
		return lives;
	};

    bool Enemy::isDead(){
        return lives<1;
    }

    void Enemy::setRemoveThis(bool value) {
        removeThis = value;
    }
       
    void Enemy::tick() {
        counter++;
        shotCounter++;
        if(rect.x + rect.w < 0){
			removeThis = true;
		}
        if(isDead()){
            endmyDeadTimer = SDL_GetTicks();
            if(stopTimer == 0){
                stopTimer = SDL_GetTicks();
            }
            if(endmyDeadTimer - stopTimer >= 2000){
                setRemoveThis(true);
            }
        }
        if(rect.x == 500){
            currTimer = SDL_GetTicks();
            if(stopTimer == 0){
                stopTimer = SDL_GetTicks();
            }
            if(currTimer - stopTimer >= 3000){
                rect.x--;
            }
        } else {
            rect.x -= 5;  
        }

        shoot(ses.getPlayer()->getHitBoxPosX(), ses.getPlayer()->getHitBoxPosY());

    };
 
    void Enemy::shoot(float playerX, float playerY){
        if(shotCounter >= (FPS*3)){
            shotCounter = 0;
            EnemyBullet* eb = EnemyBullet::getInstance(rect.x, rect.y, playerX, playerY);
            ses.playSound("sounds/laser_shot_enemy.mp3");
            ses.add(eb);
        }
    }

    void Enemy::checkCollision(const Sprite& other) {
        if(SDL_HasIntersectionF(&enemyHitbox, &other.getRect()) && !isDead()){
            const PlayerBullet* playerBullet = dynamic_cast<const PlayerBullet*>(&other);
            if(playerBullet != nullptr){
                ses.playSound("sounds/hit_sound_enemy.mp3");
                ses.addPoints();
                looseLife();
            }   
        }
	}
}
