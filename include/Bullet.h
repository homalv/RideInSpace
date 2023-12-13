#ifndef BULLET_H
#define BULLET_H
#include "MovableSprite.h"

namespace cwing 
{
    class Bullet : public MovableSprite {
        public:
            static Bullet* getInstance(int x, int y, int w, int h);
            void draw() const;

            ~Bullet();
        protected:
            Bullet(int x, int y, int w, int h);
        private:
            int windowWidth;
            int windowHeight;
            SDL_Texture* texture;

    };
}



#endif