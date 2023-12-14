#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H
#include "Bullet.h"
#include "System.h"
#include <SDL2/SDL.h>

namespace cwing 
{
    class PlayerBullet : public Bullet {
        public:
            static PlayerBullet* getInstance(int x, int y);
            void tick();
        protected:
            PlayerBullet(int x, int y);
        private:
            static const int width = 20;
            static const int height = 20;
    };
}



#endif