#include "Label.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <iostream>
#include <string>

using namespace std;

namespace cwing 
{

	Label* Label::getInstance(int x, int y, int w,
		int h, std::string txt) 
	{
		return new Label(x, y, w, h, txt);
	}

	Label::Label(int x, int y, int w, int h, const std::string txt): Sprite(x,y,w,h), text(txt)
	{	int textWidth, textHeight;
    	TTF_SizeText(sys.get_font(), text.c_str(), &textWidth, &textHeight);
		rect.w = textWidth;
    	rect.h = textHeight;

		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 50,0,10 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
	}

	void Label::draw() const {
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
	}

	Label::~Label()
	{
		SDL_DestroyTexture(texture);
	}

	string Label::getText() const {
		return text;
	}
	void Label::setText(std::string newText) {
		text = newText;
		SDL_DestroyTexture(texture);
		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(),
			text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
	}
	
}