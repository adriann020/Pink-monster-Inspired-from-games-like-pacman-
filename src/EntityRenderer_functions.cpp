#include "headers/GameManager.h"

// Render Char (used for idle in MovementChar function and more)
void GameManager::RenderIdleChar() { 
    if(this->playerState->fix){
        // could've done NULL instead of this->..->rotationAngle 
         SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), NULL, &this->coordinates->destRect, this->playerState->rotationAngle, NULL, SDL_FLIP_HORIZONTAL);
    }else  SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), NULL, &this->coordinates->destRect, this->playerState->rotationAngle, NULL, SDL_FLIP_NONE);
}

// RenderNPC
void GameManager::RenderNPC(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &srcreect ,SDL_FRect &coord, SDL_FlipMode &flip){
    SDL_RenderTextureRotated(rend, texture, &srcreect, &coord, 0, NULL, flip);
}

// Render everything else (coins, map, fightmap, play, gameovermap)
void GameManager::RenderThings(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &coord) {
    SDL_RenderTexture(rend, texture, NULL, &coord); 
}
