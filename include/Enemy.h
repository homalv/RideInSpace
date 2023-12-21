#ifndef Enemy_H
#define Enemy_H

#include "MovableSprite.h"
#include <SDL2/SDL.h>
#include "System.h"

namespace cwing {
    class Enemy : public MovableSprite {
        public:
            static Enemy* getInstance(float x, float y, float w, float h, int lives);        
            void tick() {
                if(rect.x + rect.w < 0){
			            removeThis = true;
		            } else {
                  rect.x -= 5;  
                }
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