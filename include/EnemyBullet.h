#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H
#include "Bullet.h"
#include "System.h"
#include <SDL2/SDL.h>

namespace cwing 
{
    class EnemyBullet : public Bullet {
        public:
            static EnemyBullet* getInstance(int x, int y);
            void tick();
        protected:
            EnemyBullet(int x, int y);
        private:
            static const int width = 40;
            static const int height = 20;
    };
}



#endif