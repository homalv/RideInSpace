#include "EnemySpawner.h"
#include "Session.h"


namespace cwing {
    EnemySpawner::EnemySpawner(int x, int startY, int endY, float eSize) : Sprite(1, 1, 1, 1), nrOfPlaces((endY - startY) / eSize), xPos(x), firstPos(startY), enemySize(eSize), dist(1, nrOfPlaces), spawnVector(6, nullptr){
        setTexture("images/enemy2.png");        
    }

    EnemySpawner* EnemySpawner::getInstance(int x, int startY, int endY, float enemySize){
        return new EnemySpawner(x, startY, endY, enemySize);
    };

    void EnemySpawner::tick(){
        counter++;
        if(counter >= (FPS*2) && !SpelMotor::ses.getPause()){
            counter = 0;
            position = dist(rd);
            while(spawnVector[position - 1] != nullptr){
                position = dist(rd);
            }
            Enemy* newEnemy = Enemy::getInstance(700, firstPos + position * enemySize, 40, 40, 1);
            spawnVector[position-1] = newEnemy;
            SpelMotor::ses.add(newEnemy);
            forCounter = 0;
            for (Enemy* ptr : spawnVector) {
                if(ptr != nullptr){
                    if(ptr->checkRemove()){
                        spawnVector[forCounter] = nullptr;
                    }
                }
                forCounter++;
            }
        } else if(SpelMotor::ses.getPause()){
            clearVector();
        }
    }

    void EnemySpawner::clearVector(){
        if(SpelMotor::ses.getPause()){
            for (int i = 0; i < nrOfPlaces; ++i) {  
				SpelMotor::ses.remove(spawnVector[i]); //Tömmer hela vektorn på fiender så det blir lite lugnt.
				spawnVector[i] = nullptr;
			}
        }
    }

}