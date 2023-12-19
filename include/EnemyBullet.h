#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H
#include "System.h"
#include <SDL2/SDL.h>
#include <vector>
#include "Bullet.h"

namespace cwing 
{
    class EnemyBullet : public Bullet{
        public:
            static EnemyBullet* getInstance(float x, float y, float currPlayerX, float currPlayerY);
            void tick();
            void calcDist();
            const SDL_FRect& getRect() const { return rect; }
            EnemyBullet(float x, float y, float currPlayerX, float currPlayerY);
        private:
            float playerX = 0;
            float playerY = 0;
            static const int width = 40;
            static const int height = 20;
            std::vector<float> dists; 
    };
}

#endif