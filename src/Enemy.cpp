#include "MovableSprite.h"
#include "Enemy.h"
#include "System.h"
#include "Constants.h"
#include "Session.h"
#include <iostream>

namespace spacerider {  
    Enemy::Enemy(float x, float y, float w, float h, int livesInput) : MovableSprite(x,y,w,h){
        lives= livesInput;
        setTexture("images/enemy2.png");   
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
        if(lives<1){
            dies();
        }
	};


    void Enemy::dies(){        
        // Byt ut texturvägen när enemy träffats.
        setTexture("images/enemy_crash.png");                
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
            if(stopTimer1 == 0){
                stopTimer1 = counter;
            }
            if(counter - stopTimer1 >= FPS){
                setRemoveThis(true);
            }
        }
        if(rect.x == 500){
            if(stopTimer2 == 0){
                stopTimer2 = counter;
            }
            if(counter - stopTimer2 >= FPS*3){
                stopTimer2 = 0;
                rect.x--;
            }
        } else {
            if(!isDead()){
                rect.x -= 5;  
            }
        }

        shoot(spelmotor::ses.getPlayer()->getHitBoxPosX(), spelmotor::ses.getPlayer()->getHitBoxPosY());

    };
 
    void Enemy::shoot(float playerX, float playerY){
        if(shotCounter >= (FPS*3) && !isDead()){
            shotCounter = 0;
            EnemyBullet* eb = EnemyBullet::getInstance(rect.x, rect.y, playerX, playerY);
            spelmotor::ses.playSound("sounds/laser_shot_enemy.mp3");
            spelmotor::ses.add(eb);
        }
    }

    void Enemy::checkCollision(const Sprite& other) {
        if(hasIntersection(enemyHitbox, other) && !isDead()){
            const PlayerBullet* playerBullet = dynamic_cast<const PlayerBullet*>(&other);
            if(playerBullet != nullptr){
                spelmotor::ses.playSound("sounds/hit_sound_enemy.mp3");
                spelmotor::ses.addPoints();
                looseLife();
            }   
        }
	}
}
