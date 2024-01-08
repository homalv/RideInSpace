#include "EnemySpawner.h"
#include "Session.h"
#include <iostream>

namespace cwing 
{

    EnemySpawner::EnemySpawner(int x, int startY, int endY, float eSize) : nrOfPlaces((endY - startY) / eSize), xPos(x), firstPos(startY), enemySize(eSize), dist(1, nrOfPlaces), spawnVector(6, nullptr){
    }

    EnemySpawner* EnemySpawner::getInstance(int x, int startY, int endY, float enemySize){
        return new EnemySpawner(x, startY, endY, enemySize);
    };

    void EnemySpawner::tick(){
        counter++;
        if(counter >= (FPS*2)){
            counter = 0;
            position = dist(rd);
            while(spawnVector[position - 1] != nullptr){
                std::cout << "Position: " << position - 1 << std::endl;
                position = dist(rd);
            }
            Enemy* newEnemy = Enemy::getInstance(700, firstPos + position * enemySize, 40, 40, 1);
            spawnVector[position-1] = newEnemy;
            ses.add(newEnemy);
        }
        for (Enemy* ptr : spawnVector) {
            if (!isValidPointer(ptr)) {
                spawnVector.erase(spawnVector.begin() + position - 1);
            }
        }
    }

    bool EnemySpawner::isValidPointer(const Enemy* ptr) {
        return ptr != nullptr;  
    }

    /*
    
        if( !paused && currentTime - lastEnemyTimer >= 4000){
            position = dist(rd);
            
            while(vektor[position - 1] != nullptr){
                position = dist(rd);
            }

            newEnemy = Enemy::getInstance(700, position * 55, 40, 40, 1);
            vektor[position-1] = newEnemy;
            lastEnemyTimer = currentTime;
            add(newEnemy);
        }
    
    */

    void EnemySpawner::clearVector(){
        if(ses.getPause()){
            for (int i = 0; i < nrOfPlaces; ++i) {  
				ses.remove(spawnVector[i]); //Tömmer hela vektorn på fiender så det blir lite lugnt.
				spawnVector[i] = nullptr;
			}
        }
    }

}