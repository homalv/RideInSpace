#ifndef PLAYER_H
#define PLAYER_H
#include <MovableSprite.h>
#include "PlayerBullet.h"
#include "Label.h"
#include <vector>

namespace cwing 
{
    class Player : public MovableSprite {
    public:
        static Player* getInstance(float x, float y, float w, float h);
        void tick();
        void move(const SDL_Scancode&);
        void stop(const SDL_Scancode&);
        void shoot();
        void looseLife();
        void addPoints();
        int getLives() const;
        int getPoints() const;
        bool isHit();
        void setHit(bool isHit);
        void resetPlayer();
        void checkCollision(const Sprite& other);
        float getHitBoxPosX();
		float getHitBoxPosY();
        ~Player(){};

    protected:
        Player(float x, float y, float w, float h);
    private:
        Uint32 lastShotTime = 0;
        bool movingLeft = false;
        bool movingRight = false;
        bool movingUp = false;
        bool movingDown = false;
        bool isPlayerHit = false;        
        int points = 0;
        int lives = 3;
        Uint32 hitTime = 3000;
        int counter = 0;
        int deathCounter = 0;
        //SDL_FRect hitbox;
    };
}

#endif