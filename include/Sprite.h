#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <vector>

namespace cwing{

	class Sprite
	{
	public:
		virtual void draw() const = 0;
		virtual void tick() {};
		const SDL_FRect& getRect() const { return rect; }
		std::vector<float> getCenterPos(){
			std::vector<float> centerPos(2);
			centerPos[0] = getRect().x + getRect().w / 2;
			centerPos[1] = getRect().y + getRect().h / 2;
			return centerPos;
		};
		virtual void move(const SDL_Event&) {};
		virtual bool checkRemove() const { return removeThis; }
	protected:
		Sprite(float x, float y, float w, float h) : rect{ x,y,w,h } {}
		SDL_FRect rect;
		bool removeThis = false;
	};

}

#endif