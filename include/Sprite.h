#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>

class Sprite
{
public:
	virtual void draw() const = 0;
	virtual void tick() {};
	const SDL_FRect& getRect() const { return rect; }
    virtual void move(const SDL_Event&) {};
	virtual bool checkRemove() const { return removeThis; }
protected:
	Sprite(float x, float y, float w, float h) : rect{ x,y,w,h } {}
	SDL_FRect rect;
	bool removeThis = false;
};

#endif