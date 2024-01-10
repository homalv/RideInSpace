
#include "SoundManager.h"
#include "Constants.h"


namespace cwing {
        SoundManager::SoundManager(){
            Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
            backgroundMusic = Mix_LoadMUS((constants::gResPath + "sounds/rideInSpace.mp3").c_str());
            Mix_PlayMusic(backgroundMusic, -1);
        }


    SoundManager* SoundManager::getInstance() {
       

        return new SoundManager();
    }

    SoundManager::~SoundManager() {
        Mix_FreeMusic(backgroundMusic);
        Mix_CloseAudio();
    }

    void SoundManager::playBackgroundMusic(const std::string& filePath) {
       
    }
}
