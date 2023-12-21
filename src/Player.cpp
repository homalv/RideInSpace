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

	Player::~Player()
	{
		SDL_DestroyTexture(texture);
	}

	Player* Player::getInstance(float x, float y, float w, float h) {
		return new Player(x, y, w, h);
	}

    /*
	
	void Player::mouseDown(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect()))
			isDown = true;
	}

	void Player::mouseUp(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect()))
			isDown = false;
	}

	*/

	void Player::setRightTrue(){
		movingRight = true;
	}
	void Player::setLeftTrue(){
		movingLeft = true;
	}
	void Player::setUpTrue(){
		movingUp = true;
	}
	void Player::setDownTrue(){
		movingDown = true;
	}
	void Player::setRightFalse(){
		movingRight = false;
	}
	void Player::setLeftFalse(){
		movingLeft = false;
	}
	void Player::setUpFalse(){
		movingUp = false;
	}
	void Player::setDownFalse(){
		movingDown = false;
	}

    void Player::tick () {
		SDL_GetWindowSize(sys.get_win(), &windowWidth, &windowHeight);
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

	void Player::draw() const {

		const SDL_FRect &rect = getRect();

		SDL_RenderCopyF(sys.get_ren(), texture, NULL, &rect);
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
		return SDL_HasIntersectionF(&hitbox, &other.getRect());
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