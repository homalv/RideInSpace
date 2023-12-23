#include "Label.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <iostream>
#include "Constants.h" 
#include <string>
#include "Player.h"
#include "Sprite.h"

using namespace std;

namespace cwing 
{

	Label* Label::getInstance(int x, int y, int fontSize, std::string txt, Player* playerPtr, Uint8 r, Uint8 g, Uint8 b) {
		return new Label(x, y, fontSize, txt, playerPtr, r, g, b);
	}

	Label::Label(int x, int y, int fontSize, std::string txt, Player* playerPtr, Uint8 r, Uint8 g, Uint8 b)
			: Sprite(x,y,0,0), text(txt), playerPointer(playerPtr){	
		TTF_Font* customFont = TTF_OpenFont((constants::gResPath + "fonts/STENCIL.ttf").c_str(), fontSize);    	

    	TTF_SizeText(customFont, text.c_str(), &width, &height);
		rect.w = width;
    	rect.h = height;

		SDL_Surface* surf = TTF_RenderText_Solid(customFont, text.c_str(), { r,g,b, 255 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
		TTF_CloseFont(customFont);
	}

	void Label::draw() const {
		SDL_RenderCopyF(sys.get_ren(), texture, NULL, &getRect());
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

	void Label::setPlayer(Player* newPlayer){
		playerPointer = newPlayer;
	}

	void Label::updateLives() {
		if(playerPointer){	
			std::string lives;		
			lives =std::to_string(playerPointer->getLives());

			SDL_DestroyTexture(texture);
			SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), lives.c_str(), { 50,0,10 });
			texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
			SDL_FreeSurface(surf);
		}	
	}

	void Label::updatePoints() {
		if(playerPointer){	
			std::string points;		
			points =std::to_string(playerPointer->getPoints());

			SDL_DestroyTexture(texture);
			SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), points.c_str(), { 50,0,10 });
			texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
			SDL_FreeSurface(surf);
		}	
	}

	int Label::getWidth() const{
		return width;
	};


	int Label::getHeight() const{
		return height;
	};
		
	bool Label::isPointInside(float x, float y)const{
		SDL_FRect rect = getRect();
    	return (x >= rect.x && x < rect.x + width && y >= rect.y && y < rect.y + height);		
	};
	
}