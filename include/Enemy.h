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
            void tick() {
                rect.x -= 2;  
            };
            void looseLife(); 
            ~Enemy(){};

        protected:
            Enemy(float x, float y, float w, float h, int lives);

        private:
            int lives;
    };
}

#endif