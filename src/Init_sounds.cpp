#include "Init_sounds.h" 
#include <fstream>
#include <SDL3/SDL.h>

int InitSounds::NrObjects = 0;

InitSounds::InitSounds() {
    NrObjects++;
    
    if(NrObjects == 1) {
        file_InitSound.open("../data/logs.txt", std::ios::app);
        file_InitSound << "[SYSTEM] -> Initializing sounds...\n";
        file_InitSound.close();
    }
}

InitSounds::~InitSounds() {

   if (SDL_WasInit(SDL_INIT_AUDIO)) {
    if (streamMenu) {
        SDL_ClearAudioStream(streamMenu);
        streamMenu = nullptr;
    }

    if (streamCoin) {
        SDL_ClearAudioStream(streamCoin);
        streamCoin = nullptr;
    }
 }
    
    NrObjects--;
    if(NrObjects == 0) {
        file_InitSound.open("../data/logs.txt", std::ios::app);
        file_InitSound << "[SYSTEM] -> Destroying sounds...\n";
        file_InitSound.close();
    }
    
}