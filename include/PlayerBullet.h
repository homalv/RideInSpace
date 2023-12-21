#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H
#include "Bullet.h"
#include "System.h"
#include <SDL2/SDL.h>

namespace cwing 
{
    class PlayerBullet : public Bullet {
        public:
            static PlayerBullet* getInstance(float x, float y);
            void tick();
        protected:
            PlayerBullet(float x, float y);
    };
}



#endif