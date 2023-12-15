#ifndef Enemy_H
#define Enemy_H

#include "MovableSprite.h"
#include <SDL2/SDL.h>
#include "System.h"

namespace cwing 
{
    class Enemy : public MovableSprite
	{
        public:
            static Enemy* getInstance(int x, int y, int w, int h);        
            void draw() const;
            void tick() {
                rect.x -= 2;  
            }; 
        //    virtual void perform(Enemy* source){}
        ~Enemy();

        int getWindowHeight(){
            SDL_GetWindowSize(sys.get_win(), &windowWidth, &windowHeight);
            return windowHeight;
        }

        protected:
            Enemy(int x, int y, int w, int h);

        private:
            SDL_Texture* texture;
            int windowWidth;
            int windowHeight;
    };
}

#endif