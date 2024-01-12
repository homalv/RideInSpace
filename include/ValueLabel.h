#ifndef VALUELABEL_H
#define VALUELABEL_H
#include "Label.h"

namespace SpelMotor 
{
	class ValueLabel: public Label
	{
	public:

		static ValueLabel* getInstance(int x, int y, int fontSize, int playerValue, int labelType, Player* playerPointer,  Uint8 r=0, Uint8 g=0, Uint8 b=0);
		void updateLives();
		void updatePoints();
		void tick();
		~ValueLabel(){};

	protected:
		ValueLabel(int x, int y, int fontSize, int playerValue, int labelType, Player* playerPointer, Uint8 r, Uint8 g, Uint8 b);
	private:
		Player* playerPtr;
		int playerLives;
		int playerPoints;
		int labelType;
		std::string text;
    	int width;
    	int height;
	};
}

#endif

