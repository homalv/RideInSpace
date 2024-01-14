#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"

namespace SpelMotor{


    void Sprite::draw() const{
        const SDL_FRect &rect = getRect();
		
        SDL_RenderCopyF(sys.get_ren(), texture, NULL, &rect);
    }

    Sprite::~Sprite(){
	    SDL_DestroyTexture(texture);
    }

    void Sprite::setTexture(std::string textLocaltion){
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + textLocaltion).c_str() );

    }
}