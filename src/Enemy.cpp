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
        
    void tick() {}

    void Enemy::looseLife(){
		this->lives --;
	};
 
}
