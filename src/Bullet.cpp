#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"
#include "Bullet.h"

namespace cwing 
{

	Bullet::Bullet(float x, float y, float w, float h) : MovableSprite(x,(y-(h/2)),w,h){
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/bullet.png").c_str() );
		// Ladda ljudfilen när en Bullet skapas
        shotSound = Mix_LoadWAV((constants::gResPath + "sounds/laser_shot.mp3").c_str());
        // Spela upp ljudet
        Mix_PlayChannel(-1, shotSound, 0);
	}

	Bullet* Bullet::getInstance(float x, float y, float w, float h) {
		return new Bullet(x, y, w, h);
	}
}