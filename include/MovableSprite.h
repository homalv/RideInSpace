#ifndef MovableSprite_H
#define MovableSprite_H
#include <SDL2/SDL.h>
#include <Sprite.h>

//Döp om till MovableSprite
class MovableSprite : public Sprite
{
public:
protected:
	MovableSprite(float x, float y, float w, float h) : Sprite{ x,y,w,h } {}
};

#endif
