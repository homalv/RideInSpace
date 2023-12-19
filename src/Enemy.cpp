#include "MovableSprite.h"
#include "Enemy.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"

namespace cwing 
{  
    Enemy::Enemy(float x, float y, float w, float h) : MovableSprite(x,y,w,h){
    texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/enemy2.png").c_str() );
	}
        
    Enemy::~Enemy(){
	    SDL_DestroyTexture(texture);
    }

    Enemy* Enemy::getInstance(float x, float y, float w, float h) {
        return new Enemy(x, y, w, h);
    }
        
    void tick() {}

    void Enemy::draw() const {
        const SDL_FRect &rect = getRect();
        SDL_RenderCopyF(sys.get_ren(), texture, NULL, &rect);
    } 
}
