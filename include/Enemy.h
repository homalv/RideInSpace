#ifndef Enemy_H
#define Enemy_H

#include "MovableSprite.h"
#include <SDL2/SDL.h>
#include "System.h"
#include "EnemyBullet.h"

namespace cwing {
    class Enemy : public MovableSprite {
        public:
            static Enemy* getInstance(float x, float y, float w, float h, int lives);        
            void tick(); 
            bool checkCollision(const Sprite& other) const;
            void looseLife();
            int getLives();
            
            EnemyBullet* shoot(float playerX, float playerY);
            ~Enemy(){};

        protected:
            Enemy(float x, float y, float w, float h, int lives);

        private:
            void isDead();
            SDL_FRect enemyHitbox;
            int lives;
            Uint32 stopTimer = 0;
            Uint32 currTimer = 0;
            Uint32 stopShootTimer = 0;
            Uint32 shootTimer = 0;
    };
}

#endif