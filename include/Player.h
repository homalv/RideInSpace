#ifndef PLAYER_H
#define PLAYER_H
#include <MovableSprite.h>
#include <SDL2/SDL.h>

namespace cwing 
{


    class Player : public MovableSprite {
    public:
        static Player* getInstance(int x, int y, int w, int h);
        void draw() const;
        void tick() {
            if(movingRight){
                rect.x += 5;
            }
            if(movingLeft){
                rect.x -= 5;
            }
            if(movingUp){
                rect.y -= 5;
            }
            if(movingDown){
                rect.y += 5;
            }
        }
        void updateRight(){
            movingRight = !movingRight;
        }
        void updateLeft(){
            movingLeft = !movingLeft;
        }
        void updateUp(){
            movingUp = !movingUp;
        }
        void updateDown(){
            movingDown = !movingDown;
        }
        ~Player();
    protected:
        Player(int x, int y, int w, int h);
    private:
        bool movingLeft = false;
        bool movingRight = false;
        bool movingUp = false;
        bool movingDown = false;
        SDL_Texture* texture;
    };
}

#endif