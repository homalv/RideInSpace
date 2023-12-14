#ifndef BULLET_H
#define BULLET_H
#include "MovableSprite.h"

namespace cwing 
{
    class Bullet : public MovableSprite {
        public:
            static Bullet* getInstance(int x, int y, int w, int h);
            virtual void draw() const;
            virtual void tick() {};
            ~Bullet();
        protected:
            Bullet(int x, int y, int w, int h);
            int windowWidth;
            int windowHeight;
        private:
            SDL_Texture* texture;

    };
}



#endif