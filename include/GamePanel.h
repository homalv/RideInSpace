// GamePanel.h
#ifndef GamePanel_H
#define GamePanel_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Sprite.h"

namespace cwing {
 
    class GamePanel : public Sprite {
    public:
        static GamePanel* getInstance(int x, int y, int w, int h);
        void draw() const;
        
        ~GamePanel();
    protected:
       GamePanel(int x, int y, int w, int h); 

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        SDL_Rect rect;
    };

} // namespace cwing

#endif
