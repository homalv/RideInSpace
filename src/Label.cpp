#include "Label.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <iostream>
#include "Constants.h" 
#include <string>
#include "Player.h"

using namespace std;

namespace cwing 
{

	Label* Label::getInstance(int x, int y, int fontSize, std::string txt, Player* playerPtr) {
		return new Label(x, y, fontSize, txt, playerPtr);
	}

	Label::Label(int x, int y, int fontSize, std::string txt, Player* playerPtr):Sprite(x,y,1,1), text(txt), playerPointer(PlayerPtr){	
		TTF_Font* customFont = TTF_OpenFont((constants::gResPath + "fonts/STENCIL.ttf").c_str(), fontSize);    	
		int textWidth, textHeight;
    	TTF_SizeText(customFont, text.c_str(), &textWidth, &textHeight);
		rect.w = textWidth;
    	rect.h = textHeight;

		SDL_Surface* surf = TTF_RenderText_Solid(customFont, text.c_str(), { 60,0,10 });
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
	
}