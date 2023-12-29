#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <vector>
#include "System.h"

namespace cwing{

	class Sprite
	{
	public:
		virtual void draw() const;
		virtual void tick() {};
		const SDL_FRect& getRect() const { return rect; }
		std::vector<float> getCenterPos();
		virtual bool checkRemove() const { return removeThis; }
		virtual bool checkCollision(const Sprite& other) {return false;};
		virtual ~Sprite();
	protected:
		Sprite(float x, float y, float w, float h) : rect{ x,y,w,h } {}
		SDL_FRect rect;
		bool removeThis = false;
		SDL_Texture* texture;
		SDL_FRect hitbox;
	};
}

#endif