// GamePanel.h
#ifndef GamePanel_H
#define GamePanel_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Sprite.h"

namespace cwing {

    class Label {
    public:
        Label(SDL_Renderer* renderer, const std::string& text, int x, int y, int fontSize, SDL_Color textColor);
        void draw() const;

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        SDL_Rect rect;
    };

    class GamePanel : public Sprite {
    public:
        static GamePanel* getInstance(int w, int h);
        void draw() const;

    protected:
        GamePanel(int w, int h);

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        SDL_Rect rect;

        Label pointsTextLabel;
        Label pointsValueLabel;
        Label livesTextLabel;
        Label livesValueLabel;

        int points;
        int lives;
    };

} // namespace cwing

#endif
