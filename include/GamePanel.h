// GamePanel.h
#ifndef GamePanel_H
#define GamePanel_H


#include <string>
#include "Sprite.h"

namespace spelmotor {
 
    class GamePanel : public Sprite {
    public:
        static GamePanel* getInstance(int x, int y, int w, int h);
        ~GamePanel(){};
    protected:
       GamePanel(int x, int y, int w, int h); 
    };

}

#endif
