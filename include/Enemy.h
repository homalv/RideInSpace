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
            static Enemy* getInstance(float x, float y, float w, float h, int lives);        
            void draw() const;
            void tick() {
                rect.x -= 2;  
            };
            void looseLife(); 
        //    virtual void perform(Enemy* source){}
        ~Enemy();

        int getWindowHeight(){
            SDL_GetWindowSize(sys.get_win(), &windowWidth, &windowHeight);
            return windowHeight;
        }

        protected:
            Enemy(float x, float y, float w, float h, int lives);

        private:
            SDL_Texture* texture;
            int windowWidth;
            int windowHeight;
            int lives;
    };
}

#endif