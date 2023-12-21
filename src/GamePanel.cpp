// GamePanel.cpp
#include "GamePanel.h"
#include "System.h"
#include "Constants.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>


namespace cwing {
    GamePanel::GamePanel(int x, int y, int w, int h) : Sprite(x, y, w, h){
            texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/ram.png").c_str() );        
    }
    GamePanel::~GamePanel(){
	    SDL_DestroyTexture(texture);
    }

    GamePanel* GamePanel::getInstance(int x , int y ,int w, int h) {
        return new GamePanel(x, y, w, h);
    }

    void GamePanel::draw() const {
        const SDL_FRect &rect = getRect();
        SDL_RenderCopyF(sys.get_ren(), texture, NULL, &rect);
    }

} // namespace cwing
