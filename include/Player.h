#ifndef PLAYER_H
#define PLAYER_H
#include <MovableSprite.h>
#include <SDL2/SDL.h>
#include "System.h"
#include "PlayerBullet.h"

namespace cwing 
{
    class Player : public MovableSprite {
    public:
        static Player* getInstance(int x, int y, int w, int h);
        void draw() const;
        void tick() {
            SDL_GetWindowSize(sys.get_win(), &windowWidth, &windowHeight);
            if(movingRight && rect.x + rect.w < windowWidth){
                rect.x += 5;
            }
            if(movingLeft && rect.x > 5){
                rect.x -= 5;
            }
            if(movingUp && rect.y > 5){
                rect.y -= 5;
            }
            if(movingDown && rect.y + rect.h < windowHeight){
                rect.y += 5;
            }
        }
        void setRightTrue(){
            movingRight = true;
        }
        void setLeftTrue(){
            movingLeft = true;
        }
        void setUpTrue(){
            movingUp = true;
        }
        void setDownTrue(){
            movingDown = true;
        }
        void setRightFalse(){
            movingRight = false;
        }
        void setLeftFalse(){
            movingLeft = false;
        }
        void setUpFalse(){
            movingUp = false;
        }
        void setDownFalse(){
            movingDown = false;
        }
        PlayerBullet* shoot();
        ~Player();
    protected:
        Player(int x, int y, int w, int h);
    private:
        bool movingLeft = false;
        bool movingRight = false;
        bool movingUp = false;
        bool movingDown = false;
        int windowWidth;
        int windowHeight;
        SDL_Texture* texture;
    };
}

#endif