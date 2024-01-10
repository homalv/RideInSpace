#include "Sprite.h"

namespace cwing{
    void Sprite::draw() const{
        const SDL_FRect &rect = getRect();
		
        SDL_RenderCopyF(sys.get_ren(), texture, NULL, &rect);
    }

    Sprite::~Sprite(){
	    SDL_DestroyTexture(texture);
    }
}