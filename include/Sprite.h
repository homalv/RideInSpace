#ifndef SPRITE_H
#define SPRITE_H
#include <vector>
#include "System.h"
#include "Constants.h"

namespace spelmotor{

	class Sprite
	{
	public:
		virtual void draw() const;
		virtual void tick() {};
		virtual void setHit(bool isHit) {};
		const SDL_FRect& getRect() const { return rect; }
		virtual bool checkRemove() const { return removeThis; }
		virtual void checkCollision(const Sprite& other){};
		bool hasIntersection(SDL_FRect hitBox, const Sprite& other){ return SDL_HasIntersectionF(&hitBox, &other.getRect());};
		virtual float getHitBoxPosX() {return 0.0;};
		virtual float getHitBoxPosY() {return 0.0;};
		virtual ~Sprite();
	protected:
		Sprite(float x, float y, float w, float h) : rect{ x,y,w,h } {}
		void setTexture(std::string textLocation);	
		SDL_FRect rect;
		bool removeThis = false;
		SDL_Texture* texture;
		SDL_FRect hitbox;
	};
}

#endif