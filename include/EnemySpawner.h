#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H
#include "System.h"
#include <vector>
#include "Enemy.h"
#include <random>
#include "Constants.h"

namespace cwing 
{
    class EnemySpawner{
        public:
            static EnemySpawner* getInstance(int x, int startY, int endY, float enemySize);
            void tick();
            EnemySpawner(int x, int startY, int endY, float enemySize);
            bool isValidPointer(const Enemy* ptr);
            void clearVector();
            ~EnemySpawner(){};
        private:
            int nrOfPlaces = 0;
            int xPos = 0;
            int firstPos = 0;
            int counter = 0;
            int position = 0;
            int enemySize = 0;
            std::uniform_int_distribution<int> dist; 
            std::vector<Enemy*> spawnVector;
            std::random_device rd; 
    };
}



#endif