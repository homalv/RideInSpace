#include "Constants.h" //gResPath-contains path to your resources.
#include <SDL2/SDL.h>
#include "Session.h"
#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>

using namespace std;
using namespace cwing;

Session ses;

int main(int argc, char** argv) {

	ses.run();

	return 0;
}