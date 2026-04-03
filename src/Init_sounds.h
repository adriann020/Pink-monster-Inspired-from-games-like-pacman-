#pragma once
#include <SDL3/SDL.h>
#include <fstream>

class InitSounds {
    public:
    InitSounds();
    ~InitSounds();
    
    inline SDL_AudioStream*& get_streamMenu() { return streamMenu; } // menu music
    inline SDL_AudioStream*& get_streamCoin() { return streamCoin; } // coin sound

    private:
    SDL_AudioStream *streamMenu; // menu music
    SDL_AudioStream *streamCoin; // coin sound
    std::ofstream file_InitSound;
    static int NrObjects;

};

