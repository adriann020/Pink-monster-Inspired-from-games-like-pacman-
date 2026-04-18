#include "headers/GameManager.h"
#include "Init_textures.h"
#include "Init_sounds.h"
#include <iostream>
#include <fstream>
#include <string>

void GameManager::forWindow() { 
    
    std::ofstream file("../data/logs.txt", std::ios::app);


    window = SDL_CreateWindow(
        "Game", 
        WIDTH , 
        HEIGHT, 0
    );
    

    if(!window) {   

        file << SDL_GetError() << std::endl;
        file.close();

        SDL_Quit();
        TTF_Quit();
        
        CloseClientWindowIssue = true; // Window Error issue fix
        return;

    }else {
        std::ofstream file("../data/logs.txt", std::ios::app);
        file << "[SYSTEM] -> The game has been opened successfully." << std::endl;
        file.close();
    }

   /* try {
        if (!window) {
            throw "[SYSTEM] -> The game couldn't open.";
        } else {
            throw "[SYSTEM] -> The game has been opened successfully.";
        }
    } catch (const char* msg) {
        file << msg << std::endl;
    }
    */

}

SDL_Surface* GameManager::LoadSurfaceFromPak( Pak *pak,  const std::string& path) {

    auto bytes = pak->read(path);
    std::ofstream file("../data/logs.txt", std::ios::app);
   

    if (bytes.empty()) {
        file << "[ERROR] Pak read failed: " << path << std::endl;
        file.close();
        return nullptr;
    }

    SDL_IOStream* io = SDL_IOFromConstMem(bytes.data(), bytes.size());
    
    if (!io) {
        file << "[ERROR] SDL_IOFromConstMem failed: " << SDL_GetError() << std::endl;
        file.close();
        return nullptr;
    }

    SDL_Surface* surface = SDL_LoadBMP_IO(io, true); 

    if(!surface) {
        file << "[ERROR] SDL_LoadBMP_IO failed: " << SDL_GetError() << std::endl;
        file.close();
        return nullptr;
    }

    return surface;
} 

void GameManager::forRenderer(){
    renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderVSync(renderer, 1); // smooth animations
}

void GameManager::LoadTexture() {

    
    auto CreateTextureAndDestroySurface = [&](SDL_Surface*& surface) -> SDL_Texture* {

        if (!surface) return nullptr;

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_DestroySurface(surface);
        surface = nullptr;

        /*if (!texture) {
            std::ofstream f("../data/logs.txt", std::ios::app);
            f << "[ERROR] Failed to create texture: " << SDL_GetError() << std::endl;
         }
        */

        return texture;
    }; // Only for char (useless)
 

    // ---------------- Main ----------------
    this->pak->open("assets.pak");

    this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pink.bmp" );
    this->init_texture->get_imageTextureChar() = CreateTextureAndDestroySurface(this->init_texture->get_imageSurfaceChar());

    this->init_texture->get_imageSurfaceForMaps() = LoadSurfaceFromPak( pak, "maps/202.bmp" );
    this->init_texture->get_imageTextureMap()  = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceForMaps());

    this->init_texture->get_imageSurfaceForMaps() = LoadSurfaceFromPak( pak, "maps/fightmap.bmp" );
    this->init_texture->get_imageTextureFightmap()  = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceForMaps());

    this->init_texture->get_imageSurfaceForMaps() = LoadSurfaceFromPak( pak, "menu/play1.bmp" );     
    this->init_texture->get_imageTexturePlay() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceForMaps());

    this->init_texture->get_imageSurfaceForMaps() = LoadSurfaceFromPak( pak, "maps/gameover.bmp" );
    this->init_texture->get_imageTextureGameOverMap() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceForMaps());
    SDL_DestroySurface(this->init_texture->get_imageSurfaceForMaps());

    // ---------------- NPC ------------------
    this->init_texture->get_imageSurfaceForNPCs() = LoadSurfaceFromPak(pak, "chars/owlrun.bmp");
    this->init_texture->get_imageTextureNPC()     = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceForNPCs());

    this->init_texture->get_imageSurfaceForNPCs() = LoadSurfaceFromPak(pak, "chars/bluerun.bmp");
    this->init_texture->get_imageTextureBlueNPC() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceForNPCs());
    SDL_DestroySurface(this->init_texture->get_imageSurfaceForNPCs());

    // ---------------- Walls ----------------
    this->init_texture->get_imageSurfaceForWalls() = LoadSurfaceFromPak( pak, "walls/wall2.bmp" );
    this->init_texture->get_imageTextureWall1() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceForWalls());
    this->init_texture->get_imageTextureWall2() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceForWalls());
    SDL_DestroySurface(this->init_texture->get_imageSurfaceForWalls());

    // ---------------- Coins ----------------
    this->init_texture->get_imageSurfaceC0() = LoadSurfaceFromPak( pak, "coins/coin0.bmp" );
    this->init_texture->get_imageTextureC0() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceC0());
    this->init_texture->get_imageTextureC1() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceC0());
    this->init_texture->get_imageTextureC2() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceC0());
    this->init_texture->get_imageTextureC3() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceC0());
    this->init_texture->get_imageTextureC4() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceC0());
    this->init_texture->get_imageTextureC5() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceC0());
    SDL_DestroySurface(this->init_texture->get_imageSurfaceC0());

    // ---------------- Texts ----------------
    // The things below are not taken from pak. (even for audio)
    this->init_texture->get_imageSurfaceTexts() = TTF_RenderText_Blended(font, "Score", 0, color); // score
    this->init_texture->get_imageTextureScore() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceTexts());

    this->init_texture->get_imageSurfaceTexts() = TTF_RenderText_Blended(font, " Press \"SPACE\" to play " , 0, color); // continue
    this->init_texture->get_imageTextureCont() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceTexts());

    this->init_texture->get_imageSurfaceTexts() = TTF_RenderText_Blended(font2, "YOU LOST", 0 , color2); // you lost
    this->init_texture->get_imageTextureLOST() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceTexts());

    this->init_texture->get_imageSurfaceTexts() = TTF_RenderText_Blended(font2, "Press \"SPACE\" to start over", 0 , color3);  // startover
    this->init_texture->get_imageTextureStartOver() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceTexts());
    SDL_DestroySurface(this->init_texture->get_imageSurfaceTexts());
}

void GameManager::forCoordinates() {

    // ---------------- Main ----------------

    this->coordinates->mapRect.x = 0.0;   // map1
    this->coordinates->mapRect.y = 0.0;
    this->coordinates->mapRect.w = static_cast<float>(WIDTH); 
    this->coordinates->mapRect.h = static_cast<float>(HEIGHT);
    
    this->coordinates->destRect.x = 26;    // char
    this->coordinates->destRect.y = 550;
    this->coordinates->destRect.w = 60;
    this->coordinates->destRect.h = 60;

    this->coordinates->mapFightRect.x = 0.0;  // fightmap
    this->coordinates->mapFightRect.y = 0.0;
    this->coordinates->mapFightRect.w = static_cast<float>(WIDTH); 
    this->coordinates->mapFightRect.h = static_cast<float>(HEIGHT);
    
    this->coordinates->playRect.w = 400; // play
    this->coordinates->playRect.h = 400;
    this->coordinates->playRect.x = (WIDTH - this->coordinates->playRect.w) / 2 ;  
    this->coordinates->playRect.y = (HEIGHT - this->coordinates->playRect.h) / 2;

    this->coordinates->coin0Rect.x = 900;  // coins
    this->coordinates->coin0Rect.y = 380;
    this->coordinates->coin0Rect.w = 40;
    this->coordinates->coin0Rect.h = 40;

    this->coordinates->coin1Rect.x = 600; 
    this->coordinates->coin1Rect.y = 380;
    this->coordinates->coin1Rect.w = 40;
    this->coordinates->coin1Rect.h = 40;

    this->coordinates->coin2Rect.x = 420;
    this->coordinates->coin2Rect.y = 300;
    this->coordinates->coin2Rect.w = 40;
    this->coordinates->coin2Rect.h = 40;

    this->coordinates->coin3Rect.x = 300;
    this->coordinates->coin3Rect.y = 450;
    this->coordinates->coin3Rect.w = 40;
    this->coordinates->coin3Rect.h = 40;

    this->coordinates->coin4Rect.x = 300;
    this->coordinates->coin4Rect.y = 700;
    this->coordinates->coin4Rect.w = 40;
    this->coordinates->coin4Rect.h = 40;

    this->coordinates->coin5Rect.x = 600;
    this->coordinates->coin5Rect.y = 620;
    this->coordinates->coin5Rect.w = 40;
    this->coordinates->coin5Rect.h = 40;

    this->coordinates->gameovermapRect.x = 0; // gameovermap
    this->coordinates->gameovermapRect.y = 0;
    this->coordinates->gameovermapRect.w = static_cast<float>(WIDTH);
    this->coordinates->gameovermapRect.h = static_cast<float>(HEIGHT);

    // ---------------- Walls ----------------

    this->coordinates->wall1Rect.x = 380; // wall1
    this->coordinates->wall1Rect.y =  180;
    this->coordinates->wall1Rect.h = 100;
    this->coordinates->wall1Rect.w = 140;

    this->coordinates->wall2Rect.x = 750; //wall2
    this->coordinates->wall2Rect.y = 500;
    this->coordinates->wall2Rect.h = 100;
    this->coordinates->wall2Rect.w = 140;
 
    // ---------------- Texts ----------------

    this->coordinates->scoreRect.w = 70; // score textSurScore->w;
    this->coordinates->scoreRect.h = 40; // textSurScore->h;
    this->coordinates->scoreRect.x = (WIDTH - this->coordinates->scoreRect.w) / 2;
    this->coordinates->scoreRect.y = ((HEIGHT - this->coordinates->scoreRect.h) / 2) - 380;

    this->coordinates->contRect.w = 400; // continue aka press space to play
    this->coordinates->contRect.h = 50;
    this->coordinates->contRect.x = (WIDTH - this->coordinates->contRect.w) / 2;
    this->coordinates->contRect.y = 750;

    /*LOSTrect.w = 0 // lost (not used , but kept in case)
    LOSTrect.h = 0
    LOSTrect.x = (WIDTH - LOSTrect.w) / 2 ;
    LOSTrect.y = (HEIGHT - LOSTrect.h) / 2;
    */

    this->coordinates->StartOverRect.w = 300; // startover textSurLOST->w*2;
    this->coordinates->StartOverRect.h = 50;  // textSurLOST->h*2; 
    this->coordinates->StartOverRect.x = (WIDTH / 2) - 150; 
    this->coordinates->StartOverRect.y = 750;

    // ---------------- NPCS ----------------

    this->coordinates->npcRect.x = 20; // npc owl
    this->coordinates->npcRect.y = 300; 
    this->coordinates->npcRect.w = 60;
    this->coordinates->npcRect.h = 60;

    this->coordinates->blueNpcRect.x = 20; // npc blue
    this->coordinates->blueNpcRect.y = 640; 
    this->coordinates->blueNpcRect.w = 60;
    this->coordinates->blueNpcRect.h = 60;

}

void GameManager::forMusic() { 

    SDL_LoadWAV("soundsandmusic/formenu2.wav", &musicState->wave_spec, &musicState->wave_sound, &musicState->wave_soundlen);
    SDL_LoadWAV("soundsandmusic/coin.wav", &musicState->wave_specCoin, &musicState->wave_soundCoin, &musicState->wave_soundlenCoin);

    this->init_sound->get_streamMenu() = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &musicState->wave_spec, nullptr, nullptr);
    this->init_sound->get_streamCoin() = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &musicState->wave_specCoin, nullptr, nullptr);

    SDL_PutAudioStreamData(this->init_sound->get_streamMenu(), musicState->wave_sound, musicState->wave_soundlen); // Loaded already here

}


//-----------------------------------------------  Important
void GameManager::SetRenderColor() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
}

void GameManager::RenderClear() {
    SDL_RenderClear(renderer);
}

void GameManager::RenderPresent() {
    SDL_RenderPresent(renderer);
}
//------------------------------------------------

void GameManager::ClearRenderer() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}

void GameManager::ClearWindow() {

    window_closed.open("../data/logs.txt", std::ios::app);
    window_closed << "[SYSTEM] -> The game has been closed successfully." << std::endl;
    window_closed.close();


    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}

void GameManager::deleteObjects(){
    delete this->score; // pointer for score
    this->score = nullptr; // pointer for score
    delete this->pak; // pointer for pak
    this->pak = nullptr; // pointer for pak
    delete this->playerState; // pointer for game state
    this->playerState = nullptr; // pointer for game state
    delete this->npcState; // pointer for npc state
    this->npcState = nullptr; // pointer for npc state
    delete this->effectState; // pointer for effect state
    this->effectState = nullptr; // pointer for effect state
    delete this->musicState; // pointer for music state
    this->musicState = nullptr; // pointer for music state
    delete this->uiState; // pointer for UI state
    this->uiState = nullptr; // pointer for UI state
    delete this->inputState; // pointer for input state
    this->inputState = nullptr; // pointer for input state
    delete this->coordinates; // pointer for coordinates
    this->coordinates = nullptr; // pointer for coordinates
    
    delete this->init_texture; // pointer for textures
    this->init_texture = nullptr; // pointer for textures
    delete this->init_sound; // pointer for sounds
    this->init_sound = nullptr; // pointer for sounds
}

void GameManager::QuitTTF_And_SDL() {
    TTF_Quit();
    SDL_Quit();
}
