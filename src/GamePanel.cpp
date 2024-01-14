// GamePanel.cpp
#include "GamePanel.h"
#include "System.h"
#include "Constants.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>


namespace spelmotor {
    GamePanel::GamePanel(int x, int y, int w, int h) : Sprite(x, y, w, h){
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/ram.png").c_str() );        
    }

    GamePanel* GamePanel::getInstance(int x , int y ,int w, int h) {
        return new GamePanel(x, y, w, h);
    }
}
