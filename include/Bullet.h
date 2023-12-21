#ifndef BULLET_H
#define BULLET_H
#include "MovableSprite.h"

namespace cwing 
{
    class Bullet : public MovableSprite {
        public:
            static Bullet* getInstance(float x, float y, float w, float h);
            virtual void draw() const;
            virtual void tick() {};
            ~Bullet();
        protected:
            Bullet(float x, float y, float w, float h);
            int windowWidth;
            int windowHeight;
            static const int width = 40;
            static const int height = 20;
        private:
            SDL_Texture* texture;

    };
}



#endif