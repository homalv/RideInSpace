#include "Constants.h" //gResPath-contains path to your resources.
#include "Rectangle.h"
#include <SDL2/SDL.h>
#include "Session.h"
#include "Component.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>

using namespace std;
using namespace cwing;

Session ses;

int main(int argc, char** argv) {

	/*
	Pistol* pistol = new Pistol();
	ses.add(pistol);
	ses.run();
	*/

	Rectangle* newR = Rectangle::getInstance(100, 100, 40, 40);
	ses.add(newR);
	ses.run();

	return 0;
}