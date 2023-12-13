#include "Constants.h" //gResPath-contains path to your resources.
#include <SDL2/SDL.h>
#include "Session.h"
#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>
#include "PlayerBullet.h"

using namespace std;
using namespace cwing;

Session ses;

int main(int argc, char** argv){ 

	//PlayerBullet* pb = PlayerBullet::getInstance(50, 50);

	//ses.add(pb);
	
	ses.run();

	return 0;
}