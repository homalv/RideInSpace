// GamePanel.cpp
#include "GamePanel.h"
#include <iostream>
#include <string>

namespace cwing {

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

    GamePanel* GamePanel::getInstance(int w, int h) {
        return new GamePanel(w, h);
    }

    GamePanel::GamePanel(int w, int h) : Sprite(0, 0, w, 50),
        pointsTextLabel(renderer, "Points:", 10, 10, 20, {255, 255, 255, 255}),
        pointsValueLabel(renderer, "0", 100, 10, 20, {255, 255, 255, 255}),
        livesTextLabel(renderer, "Lives:", 200, 10, 20, {255, 255, 255, 255}),
        livesValueLabel(renderer, "3", 300, 10, 20, {255, 255, 255, 255}) {

        int windowWidth = w;
        int windowHeight = 50;
        texture = nullptr;

        points = 0;
        lives = 3;
    }

    void GamePanel::draw() const {
        // ... övrig ritning
        pointsTextLabel.draw();
        pointsValueLabel.draw();
        livesTextLabel.draw();
        livesValueLabel.draw();
    }

} // namespace cwing
