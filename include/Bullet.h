#ifndef BULLET_H
#define BULLET_H
#include "MovableSprite.h"

using namespace spelmotor;

namespace spacerider 
{
    class Bullet : public MovableSprite {
        public:
            static Bullet* getInstance(float x, float y, float w, float h);
            virtual void tick() {};
            ~Bullet(){};
        protected:
            Bullet(float x, float y, float w, float h);

        private:

    };
}



#endif