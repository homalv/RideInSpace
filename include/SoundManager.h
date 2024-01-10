#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <string>
#include <SDL2/SDL_mixer.h>


namespace cwing {
    class SoundManager{
    public:
        
        ~SoundManager();
        void playBackgroundMusic(const std::string& filePath);
        static SoundManager* getInstance();

    protected:
        SoundManager();
        
    private:
        Mix_Music* backgroundMusic;
    };
}
#endif