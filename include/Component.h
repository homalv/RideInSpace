#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL2/SDL.h>

class Component
{
public:
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void draw() const = 0;
	virtual void tick(int x, int y) {}
	const SDL_Rect& getRect() const { return rect; }
protected:
	Component(int x, int y, int w, int h) : rect{ x,y,w,h } {}
	SDL_Rect rect;
};

#endif
