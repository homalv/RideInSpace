#ifndef MovableSprite_H
#define MovableSprite_H
#include <Sprite.h>

namespace SpelMotor
{
	class MovableSprite : public Sprite
	{
		public:
			std::vector<float> getCenterPos();
		protected:
			MovableSprite(float x, float y, float w, float h) : Sprite{ x,y,w,h } {
				SDL_GetWindowSize(sys.get_win(), &windowWidth, &windowHeight);
			}
			~MovableSprite(){};
			int windowWidth;
            int windowHeight;
			SDL_FRect hitbox;
	};
} 




#endif
