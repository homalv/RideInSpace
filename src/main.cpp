#include "Constants.h" //gResPath-contains path to your resources.
#include "Session.h"
#include "Sprite.h"
#include "Enemy.h"
#include "System.h"
#include <string>
#include "PlayerBullet.h"
#include "GamePanel.h"
#include "Label.h"
#include "ValueLabel.h"
#include "SpacePlayer.h"

using namespace std;
using namespace cwing;
using namespace SpelMotor;

int main(int argc, char** argv){

	GamePanel* gamePanel = GamePanel::getInstance(20,5, 660, 55);	
	ses.add(gamePanel);
	Label* labelPoints = Label::getInstance(50, 13, 22, "Total Points: ", 60, 0, 10);
	ses.add(labelPoints);
	Label* labelLives = Label::getInstance(50, 38, 22, "Total Lives: ", 60, 0, 10);
	ses.add(labelLives);

	ses.addBackground("images/space_bg.png");

	SpacePlayer* newPlayer = SpacePlayer::getInstance(100, 100, 60, 60);

	ses.addPlayer(newPlayer);

	//Player* newPlayer = Player::getInstance(100, 100, 60, 60);
	//ses.addPlayer(newPlayer);

	ValueLabel* actualPoints = ValueLabel::getInstance(220, 13, 22 , newPlayer->getPoints(), 1, newPlayer, 60, 0, 10);
	ses.add(actualPoints);

	ValueLabel* actualLives = ValueLabel::getInstance(220, 38, 22 , newPlayer->getLives(), 0, newPlayer, 60, 0, 10);
	ses.add(actualLives);

	EnemySpawner* enemySpawner = EnemySpawner::getInstance(500, 100, 465, 55.0);
	ses.add(enemySpawner);
	
	ses.run();

	return 0;
}