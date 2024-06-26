#ifndef Enemy_H
#define Enemy_H

#include "MovableSprite.h"
#include "System.h"
#include "EnemyBullet.h"
#include "PlayerBullet.h"
#include <iostream>

namespace spacerider {
    class Enemy : public spelmotor::MovableSprite {
        public:
            static Enemy* getInstance(float x, float y, float w, float h, int lives);        
            void tick(); 
            void checkCollision(const Sprite& other);
            void looseLife();
            int getLives() const;
            bool isDead();
            void setRemoveThis(bool value);
            void shoot(float playerX, float playerY);
            ~Enemy(){}

        protected:
            Enemy(float x, float y, float w, float h, int lives);

        private:
            void dies();
            SDL_FRect enemyHitbox;
            int lives;
            int stopTimer1 = 0;
            int stopTimer2 = 0;
            Uint32 endmyDeadTimer = 0;
            Uint32 currTimer = 0;
            Uint32 stopShootTimer = 0;
            Uint32 shootTimer = 0;
            int counter = 0;
            int shotCounter = 0;
    };
}

#endif