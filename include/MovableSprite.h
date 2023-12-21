#ifndef MovableSprite_H
#define MovableSprite_H
#include <SDL2/SDL.h>
#include <Sprite.h>

namespace cwing
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
	};
} 




#endif
