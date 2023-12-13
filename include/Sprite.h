#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>

class Sprite
{
public:
	virtual void draw() const = 0;
	virtual void tick() {};
	const SDL_Rect& getRect() const { return rect; }
    virtual void move(const SDL_Event&) {};
	virtual bool checkRemove() const { return removeThis; }
protected:
	Sprite(int x, int y, int w, int h) : rect{ x,y,w,h } {}
	SDL_Rect rect;
	bool removeThis = false;
};

#endif