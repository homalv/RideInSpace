#ifndef Enemy_H
#define Enemy_H

#include "MovableSprite.h"
#include <SDL2/SDL.h>
#include "System.h"

namespace cwing {
    class Enemy : public MovableSprite {
        public:
            static Enemy* getInstance(float x, float y, float w, float h, int lives);        
            void tick(); 
            bool checkCollision(const Sprite& other) const;
            void looseLife();
            int getLives();
            
            ~Enemy(){};

        protected:
            Enemy(float x, float y, float w, float h, int lives);

        private:
            void isDead();
            SDL_FRect enemyHitbox;
            int lives;
            
    };
}

#endif