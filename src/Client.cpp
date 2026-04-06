#include "headers/Comp.h"
#include <fstream>
#include <unistd.h>

void DataEngine::forClient() {

    bool run = true;
    while (run) {

        if(CloseClientWindowIssue == true) run = false; // Window Error issue fix

        now = SDL_GetTicksNS(); // speed ..
        deltaTime = (now - last) / 1'100'000.0; 
        last = now;  // ..

        ticks = SDL_GetTicks(); // for sprites
        //seconds = ticks / 1000; // useless
        sprite = (ticks / 110) % 6; // char 
        sprite2 = (ticks / 110) % 6; // npc owl
        sprite3 = (ticks / 110) % 6; // npcs blue

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                
                    run = false;
            
                    break;

                case SDL_EVENT_KEY_DOWN:
                    switch (event.key.scancode) {
                        case SDL_SCANCODE_SPACE:

                            StartOver(); // Update

                            break;
                    }
                    break;
            }
         
        }

        RenderClear();
        //-------------------------------------------------

        // Menu 
        RenderImportantThings(renderer, this->init_texture->get_imageTextureMap(), this->coordinates->mapRect); // Map1
        RenderImportantThings(renderer, this->init_texture->get_imageTexturePlay(), this->coordinates->playRect); // Play
        RenderImportantThings(renderer, this->init_texture->get_imageTextureCont(), this->coordinates->contRect); // Continue
        MoveTextContinue(); // Move text continue
        
        // MenuMusic
        if(musicState->stopmenumusic == false){
            MenuMusic(); // [ON]
        }

        // Ready to change the map
        if (this->uiState->play == true) {
        
            this->uiState->changeMap = true;
            musicState->stopmenumusic = true;

            SDL_DestroyTexture(this->init_texture->get_imageTexturePlay()); // Play
            SDL_DestroyTexture(this->init_texture->get_imageTextureMap()); // Map1
            SDL_DestroyTexture(this->init_texture->get_imageTextureCont()); // Cont
            SDL_ClearAudioStream(this->init_sound->get_streamMenu()); // [OFF] MenuMusic buffer clear (streamMenu's data)

        }

        // Changes the map
        if (this->uiState->changeMap == true) {

            RenderImportantThings(renderer, this->init_texture->get_imageTextureFightmap(), this->coordinates->mapFightRect); // Fightmap

            RenderImportantThings(renderer, this->init_texture->get_imageTextureWall1(), this->coordinates->wall1Rect); // Wall1
            RenderImportantThings(renderer, this->init_texture->get_imageTextureWall2(), this->coordinates->wall2Rect); // Wall2

            RenderCoin(renderer, this->init_texture->get_imageTextureC0(), this->coordinates->coin0Rect); // Coins
            RenderCoin(renderer, this->init_texture->get_imageTextureC1(), this->coordinates->coin1Rect);
            RenderCoin(renderer, this->init_texture->get_imageTextureC2(), this->coordinates->coin2Rect);
            RenderCoin(renderer, this->init_texture->get_imageTextureC3(), this->coordinates->coin3Rect);
            RenderCoin(renderer, this->init_texture->get_imageTextureC4(), this->coordinates->coin4Rect);
            RenderCoin(renderer, this->init_texture->get_imageTextureC5(), this->coordinates->coin5Rect);

            // MoveNpc and rendernpc in it.
            MoveNPC();

            // Movement for character
            MovementChar();

            // Score text
            RenderImportantThings(renderer, this->init_texture->get_imageTextureScore() , this->coordinates->scoreRect); // score (updated in updateScore)

 
        }

        // Collisions
        AllCollisionsAndScore();

        // Updates
        ResetScore();
        YouLost();

        //-------------------------------------------------
        RenderPresent();
    }
}
