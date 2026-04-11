#include "headers/Comp.h"

void GameManager::RenderTextureRotated() { // Char
    if(this->playerState->fix){
        // could've done NULL instead of this->..->rotationAngle
         SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), NULL, &this->coordinates->destRect, this->playerState->rotationAngle, NULL, SDL_FLIP_HORIZONTAL);
    }else  SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), NULL, &this->coordinates->destRect, this->playerState->rotationAngle, NULL, SDL_FLIP_NONE);
}

void GameManager::RenderCharacter() {  //Char unused

    SDL_RenderTexture(renderer, this->init_texture->get_imageTextureChar(), NULL, &this->coordinates->destRect);
}

// RenderNPC

void GameManager::RenderNPC(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &srcreect ,SDL_FRect &coord, SDL_FlipMode &flip){
    SDL_RenderTextureRotated(rend, texture, &srcreect, &coord, 0, NULL, flip);
}

// RenderImportantThings

void GameManager::RenderImportantThings(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &coord) {
    SDL_RenderTexture(rend, texture, NULL, &coord); 
}

// RenderCoin

void GameManager::RenderCoin(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &coord) {
    SDL_RenderTexture(rend, texture, NULL , &coord);
}

