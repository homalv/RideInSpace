#ifndef PLAYER_H
#define PLAYER_H
#include <MovableSprite.h>
#include <SDL2/SDL.h>
#include "System.h"
#include "PlayerBullet.h"
#include <vector>

namespace cwing 
{
    class Player : public MovableSprite {
    public:
        static Player* getInstance(float x, float y, float w, float h);
        void draw() const;
        void tick();
        void setRightTrue();
        void setLeftTrue();
        void setUpTrue();
        void setDownTrue();
        void setRightFalse();
        void setLeftFalse();
        void setUpFalse();
        void setDownFalse();
        PlayerBullet* shoot();
        bool checkCollision(const Sprite& other) const;
        void looseLife();
        void addPoints();
        int getLives() const;
        int getPoints() const;
        ~Player();
    protected:
        Player(float x, float y, float w, float h);
    private:
        Uint32 lastShotTime = 0;
        bool movingLeft = false;
        bool movingRight = false;
        bool movingUp = false;
        bool movingDown = false;
        int windowWidth;
        int windowHeight;
        SDL_Texture* texture;
        int points = 0;
        int lives = 3;
        SDL_FRect hitbox;
    };
}

#endif