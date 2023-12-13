#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H
#include "Bullet.h"

namespace cwing 
{
    class PlayerBullet : public Bullet {
        public:
            static PlayerBullet* getInstance(int x, int y);
            void draw() const;

            ~PlayerBullet();
        protected:
            PlayerBullet(int x, int y);
        private:
            static const int width = 3;
            static const int height = 3;
            SDL_Texture* texture;
    };
}



#endif