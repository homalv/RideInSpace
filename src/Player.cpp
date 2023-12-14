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

	Player::Player(int x, int y, int w, int h) : MovableSprite(x,y,w,h)
	{
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/player_ship.png").c_str() );
	}

	Player::~Player()
	{
		SDL_DestroyTexture(texture);
	}

	Player* Player::getInstance(int x, int y, int w, int h) {
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
		}
		if(movingLeft && rect.x > 5){
			rect.x -= 5;
		}
		if(movingUp && rect.y > 5){
			rect.y -= 5;
		}
		if(movingDown && rect.y + rect.h < windowHeight){
			rect.y += 5;
		}
	}

	void Player::draw() const {

		const SDL_Rect &rect = getRect();

		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	}

	PlayerBullet* Player::shoot() {
		Uint32 currentTime = SDL_GetTicks();
		if(currentTime - lastShotTime >= 300){
			lastShotTime = currentTime;
			return PlayerBullet::getInstance(rect.x, rect.y);
		}
		return nullptr;
	}
}