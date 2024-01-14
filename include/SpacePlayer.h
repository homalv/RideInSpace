#ifndef SPACEPLAYER_H
#define SPACEPLAYER_H
#include <Player.h>


namespace cwing 
{
    class SpacePlayer : public SpelMotor::Player {
    public:
        static SpacePlayer* getInstance(float x, float y, float w, float h);
        void spaceKeyPressed();
        ~SpacePlayer(){};
    protected:
        SpacePlayer(float x, float y, float w, float h);
        int counter = 0;
    private:
    };
}

#endif