#include "MovableSprite.h"
#include "Player.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "PlayerBullet.h"
#include "Session.h"

namespace cwing 
{

	Player::Player(float x, float y, float w, float h) : MovableSprite(x,y,w,h)
	{
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/player_ship.png").c_str() );
		hitbox.x = rect.x;
    	hitbox.y = rect.y-10;
    	hitbox.w = 40;
    	hitbox.h = rect.h-10;
	}

	Player* Player::getInstance(float x, float y, float w, float h) {
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

    void Player::tick () {
		if(movingRight && rect.x + rect.w < windowWidth){
			rect.x += 5;
			hitbox.x += 5;
		}
		if(movingLeft && rect.x > 5){
			rect.x -= 5;
			hitbox.x -= 5;
		}
		if(movingUp && rect.y > 60){
			rect.y -= 5;
			hitbox.y -= 5;
		}
		if(movingDown && rect.y + rect.h < windowHeight){
			rect.y += 5;
			hitbox.y += 5;
		}
	}

	PlayerBullet* Player::shoot() {
		Uint32 currentTime = SDL_GetTicks();
		if(currentTime - lastShotTime >= 300){
			lastShotTime = currentTime;
			return PlayerBullet::getInstance(rect.x+rect.w, rect.y+(rect.h/2));
		}
		return nullptr;
	}

	bool Player::checkCollision(const Sprite& other) const{
		const MovableSprite* movableOther = dynamic_cast<const MovableSprite*>(&other);
		if(movableOther){
			return SDL_HasIntersectionF(&hitbox, &other.getRect());
		}
		return false;
	}

	void Player::setHit(bool isHit) {
        isPlayerHit = isHit;
        if (isHit) {
            // Byt ut texturvägen när spelaren är träffad
            texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/player_hit.png").c_str());
        } else {
            // Återställ texturvägen när spelaren inte är träffad
            texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/player_ship.png").c_str());
        }
    }

	bool Player::isHit(){
		return isPlayerHit;
	};

	void Player::resetPlayer(){
		points = 0;
		lives = 3;
	}
	
	void Player::looseLife(){
		this->lives --;
	};

    void Player::addPoints(){
		this->points ++;
	};

    int Player::getLives() const {
		return lives;
	};

    int Player::getPoints()const{
		return points;
	};
}