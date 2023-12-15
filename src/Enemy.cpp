#include "MovableSprite.h"
#include "Enemy.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Constants.h"

namespace cwing 
{  
    Enemy::Enemy(int x, int y, int w, int h) : MovableSprite(x,y,w,h){
    texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/UppKnapp.png").c_str() );
	}
        
    Enemy::~Enemy(){
	    SDL_DestroyTexture(texture);
    }

    Enemy* Enemy::getInstance(int x, int y, int w, int h) {
        return new Enemy(x, y, w, h);
    }
        
    void tick() {}

    void Enemy::draw() const {
        const SDL_Rect &rect = getRect();
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
    } 
}
