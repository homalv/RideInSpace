#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "MovableSprite.h"
#include <iostream>

namespace SpelMotor 
{
    class Player : public MovableSprite {

    public:
        static Player* getInstance(float x, float y, float w, float h);
        void tick();
        void move(const SDL_Scancode&);
        void stop(const SDL_Scancode&);
        virtual void spaceKeyPressed() {};
        void looseLife();
        void addPoints();
        int getLives() const;
        int getPoints() const;
        void setHit(bool isHit);
        void reset();
        int getCounter() const;
        void resetCounter();
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
        int lives = 1;
        Uint32 hitTime = 3000;
        int counter = 0;
        int deathCounter = 0;
        //SDL_FRect hitbox;
    };
}

#endif