// GamePanel.cpp
#include "GamePanel.h"
#include "System.h"
#include "Constants.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>


namespace cwing {
/*
    Label::Label(SDL_Renderer* renderer, const std::string& text, int x, int y, int fontSize, SDL_Color textColor) : renderer(renderer) {
        TTF_Font* font = TTF_OpenFont("path_to_your_font.ttf", fontSize);
        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), textColor);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);

        int textWidth, textHeight;
        SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

        rect.x = x;
        rect.y = y;
        rect.w = textWidth;
        rect.h = textHeight;
    }

    void Label::draw() const {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
*/

    GamePanel::GamePanel(int x, int y, int w, int h) : Sprite(x, y, w, h){
            texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/ram.png").c_str() );        
    }
    GamePanel::~GamePanel(){
	    SDL_DestroyTexture(texture);
    }

    GamePanel* GamePanel::getInstance(int x , int y ,int w, int h) {
        return new GamePanel(x, y, w, h);
    }

    
       /* pointsTextLabel(renderer, "Points:", 10, 10, 20, {255, 255, 255, 255}),
        pointsValueLabel(renderer, "0", 100, 10, 20, {255, 255, 255, 255}),
        livesTextLabel(renderer, "Lives:", 200, 10, 20, {255, 255, 255, 255}),
        livesValueLabel(renderer, "3", 300, 10, 20, {255, 255, 255, 255}) {
*/
        
        //texture = nullptr;

        //int points = 0;
        //int lives = 3;
    

    void GamePanel::draw() const {
        const SDL_Rect &rect = getRect();
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
      /*  // ... övrig ritning
        pointsTextLabel.draw();
        pointsValueLabel.draw();
        livesTextLabel.draw();
        livesValueLabel.draw();
        */
    }

} // namespace cwing
