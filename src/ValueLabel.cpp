#include "ValueLabel.h"
#include "Player.h"

namespace SpelMotor {
    ValueLabel* ValueLabel::getInstance(int x, int y, int fontSize, int playerValue, int labelTypeInput, Player* playerPointer, Uint8 r, Uint8 g, Uint8 b){
		return new ValueLabel(x, y, fontSize, playerValue, labelTypeInput, playerPointer, r, g, b);
	}

	ValueLabel::ValueLabel(int x, int y, int fontSize, int playerValue, int labelTypeInput, Player* playerPointer, Uint8 r, Uint8 g, Uint8 b) : Label(x, y, fontSize, std::to_string(playerValue), r, g, b),
        playerPtr(playerPointer),
        playerLives(playerPointer->getLives()),
        playerPoints(playerPointer->getPoints()),
        labelType(labelTypeInput) {
    }

    void ValueLabel::updateLives(){
        if(playerPtr->getLives() != playerLives){
            playerLives = playerPtr->getLives();	
            std::string lives = std::to_string(playerPtr->getLives());
            SDL_DestroyTexture(texture);
            SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), lives.c_str(), { 50,0,10 });
            texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
            SDL_FreeSurface(surf);
        }	
    }

    void ValueLabel::updatePoints(){
        if(playerPtr->getPoints() != playerPoints){
            playerPoints = playerPtr->getPoints();	
            std::string points = std::to_string(playerPtr->getPoints());
            SDL_DestroyTexture(texture);
            SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), points.c_str(), { 50,0,10 });
            texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
            SDL_FreeSurface(surf);
        }
    }

    void ValueLabel::tick(){
        if(labelType == 0){
            updateLives();
        } else if(labelType == 1){
            updatePoints();
        }
    }
}