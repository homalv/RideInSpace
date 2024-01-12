#include "Sprite.h"
#include <SDL2/SDL.h>

namespace SpelMotor{
    void Sprite::draw() const{
        const SDL_FRect &rect = getRect();
		
        SDL_RenderCopyF(sys.get_ren(), texture, NULL, &rect);
    }

    Sprite::~Sprite(){
	    SDL_DestroyTexture(texture);
    }

    void Sprite::removeTexture(SDL_Texture* textureToRemove){
         SDL_DestroyTexture(texture);
    }
}