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
#include "EnemySpawner.h"

int main(int argc, char** argv){

	SpelMotor::ses.addBackgroundMusic("sounds/rideInSpace.mp3");
	SpelMotor::GamePanel* gamePanel = SpelMotor::GamePanel::getInstance(20,5, 660, 55);	
	SpelMotor::ses.add(gamePanel);
	SpelMotor::Label* labelPoints = SpelMotor::Label::getInstance(50, 13, 22, "Total Points: ", 60, 0, 10);
	SpelMotor::ses.add(labelPoints);
	SpelMotor::Label* labelLives = SpelMotor::Label::getInstance(50, 38, 22, "Total Lives: ", 60, 0, 10);
	SpelMotor::ses.add(labelLives);

	SpelMotor::ses.addBackground("images/space_bg.png");

	cwing::SpacePlayer* newPlayer = cwing::SpacePlayer::getInstance(100, 100, 60, 60);

	SpelMotor::ses.addPlayer(newPlayer);
  
	//Player* newPlayer = Player::getInstance(100, 100, 60, 60);
	//ses.addPlayer(newPlayer);

	SpelMotor::ValueLabel* actualPoints = SpelMotor::ValueLabel::getInstance(220, 13, 22 , newPlayer->getPoints(), 1, newPlayer, 60, 0, 10);
	SpelMotor::ses.add(actualPoints);

	SpelMotor::ValueLabel* actualLives = SpelMotor::ValueLabel::getInstance(220, 38, 22 , newPlayer->getLives(), 0, newPlayer, 60, 0, 10);
	SpelMotor::ses.add(actualLives);

	cwing::EnemySpawner* enemySpawner = cwing::EnemySpawner::getInstance(500, 100, 465, 55.0);
	SpelMotor::ses.add(enemySpawner);

	SpelMotor::ses.run();

	return 0;

}