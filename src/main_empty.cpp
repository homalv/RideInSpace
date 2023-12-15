#include "Constants.h" //gResPath-contains path to your resources.
#include <SDL2/SDL.h>
#include "Session.h"
#include "Sprite.h"
#include "Enemy.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>
#include "PlayerBullet.h"

using namespace std;
using namespace cwing;

class TestEnemy: public Enemy{
	public:
	TestEnemy() :Enemy(700, 460, 40, 40){}
	//void perform(){}
};

Session ses;

int main(int argc, char** argv){ 
	
	ses.run();

	return 0;
}