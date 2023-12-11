#include "MovableSprite.h"
#include "Player.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"

namespace cwing 
{

	Player::Player(int x, int y, int w, int h) : MovableSprite(x,y,w,h)
	{
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/NerKnapp.png").c_str() );
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

    void Player::tick () {}

    */

	void Player::draw() const {

		const SDL_Rect &rect = getRect();

		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	}
}