#ifndef PLAYER_H
#define PLAYER_H
#include <MovableSprite.h>
#include <SDL2/SDL.h>
#include "PlayerBullet.h"
#include <vector>

namespace cwing 
{
    class Player : public MovableSprite {
    public:
        static Player* getInstance(float x, float y, float w, float h);
        void tick();
        void move(const SDL_Scancode&);
        void stop(const SDL_Scancode&);
        PlayerBullet* shoot();
        bool checkCollision(const Sprite& other) const;
        void looseLife();
        void addPoints();
        int getLives() const;
        int getPoints() const;
        ~Player(){};
    protected:
        Player(float x, float y, float w, float h);
    private:
        Uint32 lastShotTime = 0;
        bool movingLeft = false;
        bool movingRight = false;
        bool movingUp = false;
        bool movingDown = false;
        int points = 0;
        int lives = 3;
        SDL_FRect hitbox;
    };
}

#endif