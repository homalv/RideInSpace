#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H
#include "Bullet.h"
#include "System.h"
#include <iostream>

namespace spacerider 
{
    class PlayerBullet : public Bullet {
        public:
            static PlayerBullet* getInstance(float x, float y);
            void tick();
            ~PlayerBullet(){}
        protected:
            PlayerBullet(float x, float y);
        private:            
            static const int width = 20;
            static const int height = 20;
    };
}



#endif