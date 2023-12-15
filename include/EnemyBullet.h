#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H
#include "Bullet.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <vector>

namespace cwing 
{
    class EnemyBullet : public Bullet {
        public:
            static EnemyBullet* getInstance(int x, int y, int currPlayerX, int currPlayerY);
            void tick();
            void calcDist();
        protected:
            EnemyBullet(int x, int y, int currPlayerX, int currPlayerY);
        private:
            int playerX = 0;
            int playerY = 0;
            static const int width = 40;
            static const int height = 20;
            std::vector<float> dists; 
    };
}



#endif