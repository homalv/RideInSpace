#ifndef VALUELABEL_H
#define VALUELABEL_H

#include "Label.h"

namespace cwing 
{
	class ValueLabel: public Label
	{
	public:

		static ValueLabel* getInstance(int x, int y, int fontSize, int playerValue, int labelType, Player*& playerPointer,  Uint8 r=0, Uint8 g=0, Uint8 b=0);
		//std::string getText() const;
		//void setPlayer(Player* newPlayer);
		void updateLives();
		void updatePoints();
		void tick();
		//void tick();
		//void getPlayerLives();
		~ValueLabel(){};

	protected:
		ValueLabel(int x, int y, int fontSize, int playerValue, int labelType, Player*& playerPointer, Uint8 r, Uint8 g, Uint8 b);
	private:
		std::string text;
		int playerLives;
		int playerPoints;
		Player* playerPtr;
		int width;
		int height;
		int labelType;
	};
}

#endif

