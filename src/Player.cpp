#include "MovableSprite.h"
#include "Player.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "PlayerBullet.h"
#include <iostream>
#include "Session.h"

namespace SpelMotor {
	Player::Player(float x, float y, float w, float h) : MovableSprite(x,y,w,h){
		setTexture("images/player_ship.png");
		hitbox.x = rect.x;
    	hitbox.y = rect.y-10;
    	hitbox.w = 40;
    	hitbox.h = rect.h-10;
	}

	Player* Player::getInstance(float x, float y, float w, float h){
		return new Player(x, y, w, h);
	}

	void Player::move(const SDL_Scancode& scancode){
		if(scancode == SDL_SCANCODE_RIGHT){
			movingRight = true;
		} else if(scancode == SDL_SCANCODE_LEFT){
			movingLeft = true;
		} else if(scancode == SDL_SCANCODE_DOWN){
			movingDown = true;
		} else if(scancode == SDL_SCANCODE_UP){
			movingUp = true;
		}
	}

	void Player::stop(const SDL_Scancode& scancode){
		if(scancode == SDL_SCANCODE_RIGHT){
			movingRight = false;
		} else if(scancode == SDL_SCANCODE_LEFT){
			movingLeft = false;
		} else if(scancode == SDL_SCANCODE_DOWN){
			movingDown = false;
		} else if(scancode == SDL_SCANCODE_UP){
			movingUp = false;
		}
	}
	
	void Player::tick (){
		counter++;
		if(movingRight && rect.x + rect.w < windowWidth){
			rect.x += 5;
			hitbox.x += 5;
		}
		if(movingLeft && rect.x > 5){
			rect.x -= 5;
			hitbox.x -= 5;
		}
		if(movingUp && rect.y > 70){
			rect.y -= 5;
			hitbox.y -= 5;
		}
		if(movingDown && rect.y + rect.h < windowHeight){
			rect.y += 5;
			hitbox.y += 5;
		}

		if (isPlayerHit && counter >= (FPS*3) && lives>0) {
			// Om det har gått 2 sekunder sedan träffen, återställ skeppet
			std::cout << "Waiting" << std::endl;
			setHit(false);
			ses.setPause(false);
		}
		
		if(lives<1){
			ses.handleEndGame();
		}
	}

	void Player::setHit(bool isHit){
        isPlayerHit = isHit;
        if (isHit){
            // Byt ut texturvägen när spelaren är träffad
            texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/player_hit.png").c_str());
        } else {
            // Återställ texturvägen när spelaren inte är träffad
            texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/player_ship.png").c_str());
        }
    }

	int Player::getCounter() const {
		return counter;
	}

	void Player::resetCounter() {
		counter = 0;
	}

	void Player::checkCollision(const Sprite& other){
		if(SDL_HasIntersectionF(&hitbox, &other.getRect()) && counter >= (FPS*3)){
			counter = 0;
			ses.setPause(true);
			setHit(true);
			ses.playSound("sounds/hit_sound.mp3");
			looseLife();
		}
	}
	
	float Player::getHitBoxPosX(){
		return hitbox.x;
	}

	float Player::getHitBoxPosY(){
		return hitbox.y;
	}

	void Player::reset(){
		setHit(false);
		points = 0;
		lives = 3;
	}
	
	void Player::looseLife(){
		this->lives--;
	};

    void Player::addPoints(){
		this->points++;
	};

    int Player::getLives() const {
		return lives;
	};

    int Player::getPoints()const{
		return points;
	};
}