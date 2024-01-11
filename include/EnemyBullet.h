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
            ~EnemyBullet(){};
        protected:
            EnemyBullet(float x, float y, float currPlayerX, float currPlayerY);
        private:
            float playerX;
            float playerY;
            static const int width = 20;
            static const int height = 20;
            std::vector<float> dists; 
    };
}

#endif