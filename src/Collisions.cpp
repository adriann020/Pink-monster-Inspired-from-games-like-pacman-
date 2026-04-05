#include "headers/Comp.h"

// Collisions and score increment (CollisionNPC in ResetScore and CollisionWALL in MovementChar -> both in Gameplay.cpp)
void DataEngine::AllCollisionsAndScore() { 

    // Coins-Char
    if(CollisionCoins(this->coordinates->coin0Rect, this->coordinates->destRect) == 1){
        this->score->forScore(); // Score increment 
        updateScore(); // Updates the score text


        this->coordinates->coin0Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin0Rect.y = rand() % (HEIGHT-100);
        
        SDL_ClearAudioStream(this->init_sound->get_streamCoin()); // Clear buffer (streamcoin's data)
        SDL_PutAudioStreamData(this->init_sound->get_streamCoin(), wave_soundCoin, wave_soundlenCoin); // Load stream data
        SDL_ResumeAudioStreamDevice(this->init_sound->get_streamCoin()); // Play the sound (which is in a paused state)
    
    }else if (CollisionCoins(this->coordinates->coin1Rect, this->coordinates->destRect) == 1){
        this->score->forScore(); // Score increment 
        updateScore(); // Updates the score text


        this->coordinates->coin1Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin1Rect.y = rand() % (HEIGHT-100);

        SDL_ClearAudioStream(this->init_sound->get_streamCoin()); // Clear buffer (streamcoin's data)
        SDL_PutAudioStreamData(this->init_sound->get_streamCoin(), wave_soundCoin, wave_soundlenCoin); // Load stream data 
        SDL_ResumeAudioStreamDevice(this->init_sound->get_streamCoin()); // Play the sound (which is in a paused state)

    }else if (CollisionCoins(this->coordinates->coin2Rect, this->coordinates->destRect) == 1){
        this->score->forScore(); // Score increment 
        updateScore(); // Updates the score text


        this->coordinates->coin2Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin2Rect.y = rand() % (HEIGHT-100);

        SDL_ClearAudioStream(this->init_sound->get_streamCoin()); // Clear buffer (streamcoin's data)
        SDL_PutAudioStreamData(this->init_sound->get_streamCoin(), wave_soundCoin, wave_soundlenCoin); // Load stream data
        SDL_ResumeAudioStreamDevice(this->init_sound->get_streamCoin()); // Play the sound (which is in a paused state)

    }else if (CollisionCoins(this->coordinates->coin3Rect, this->coordinates->destRect) == 1){
        this->score->forScore(); // Score increment 
        updateScore(); // Updates the score text

    
        this->coordinates->coin3Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin3Rect.y = rand() % (HEIGHT-100);

        SDL_ClearAudioStream(this->init_sound->get_streamCoin()); // Clear buffer (streamcoin's data)
        SDL_PutAudioStreamData(this->init_sound->get_streamCoin(), wave_soundCoin, wave_soundlenCoin); // Load stream data
        SDL_ResumeAudioStreamDevice(this->init_sound->get_streamCoin()); // Play the sound (which is in a paused state)

    }else if (CollisionCoins(this->coordinates->coin4Rect, this->coordinates->destRect) == 1){
        this->score->forScore(); // Score increment 
        updateScore(); // Updates the score text

     
        this->coordinates->coin4Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin4Rect.y = rand() % (HEIGHT-100);

        SDL_ClearAudioStream(this->init_sound->get_streamCoin()); // Clear buffer (streamcoin's data)
        SDL_PutAudioStreamData(this->init_sound->get_streamCoin(), wave_soundCoin, wave_soundlenCoin); // Load stream data
        SDL_ResumeAudioStreamDevice(this->init_sound->get_streamCoin()); // Play the sound (which is in a paused state)

    }else if (CollisionCoins(this->coordinates->coin5Rect, this->coordinates->destRect) == 1){
        this->score->forScore(); // Score increment 
        updateScore(); // Updates the score text

        this->coordinates->coin5Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin5Rect.y = rand() % (HEIGHT-100);
        
        SDL_ClearAudioStream(this->init_sound->get_streamCoin()); // Clear buffer (streamcoin's data)
        SDL_PutAudioStreamData(this->init_sound->get_streamCoin(), wave_soundCoin, wave_soundlenCoin); // Load stream data
        SDL_ResumeAudioStreamDevice(this->init_sound->get_streamCoin()); // Play the sound (which is in a paused state)
    }

 //Fixed things
    // Wall1-Coins 
    if(CollisionWALLCoins(this->coordinates->coin0Rect, this->coordinates->wall1Rect) == 1){

        this->coordinates->coin0Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin0Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin1Rect, this->coordinates->wall1Rect) == 1){

        this->coordinates->coin1Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin1Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin2Rect, this->coordinates->wall1Rect) == 1){

        this->coordinates->coin2Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin2Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin3Rect, this->coordinates->wall1Rect) == 1){

        this->coordinates->coin3Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin3Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin4Rect, this->coordinates->wall1Rect) == 1){

        this->coordinates->coin4Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin4Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin5Rect, this->coordinates->wall1Rect) == 1){

        this->coordinates->coin5Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin5Rect.y = rand() % (HEIGHT-100);

    }
 
    // Wall2-Coins
    if(CollisionWALLCoins(this->coordinates->coin0Rect, this->coordinates->wall2Rect) == 1){

        this->coordinates->coin0Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin0Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin1Rect, this->coordinates->wall2Rect) == 1){

        this->coordinates->coin1Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin1Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin2Rect, this->coordinates->wall2Rect) == 1){

        this->coordinates->coin2Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin2Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin3Rect, this->coordinates->wall2Rect) == 1){

        this->coordinates->coin3Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin3Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin4Rect, this->coordinates->wall2Rect) == 1){

        this->coordinates->coin4Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin4Rect.y = rand() % (HEIGHT-100);

    }else if(CollisionWALLCoins(this->coordinates->coin5Rect, this->coordinates->wall2Rect) == 1){

        this->coordinates->coin5Rect.x = rand() % (WIDTH-100); 
        this->coordinates->coin5Rect.y = rand() % (HEIGHT-100);

    }

}
