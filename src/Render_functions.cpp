#include "headers/Comp.h"
#include <iostream>
#include <string>


void DataEngine::RenderTextureRotated() { // Char
    if(this->gameState->fix){
         SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), NULL, &this->coordinates->destRect, this->gameState->rotationAngle, NULL, SDL_FLIP_HORIZONTAL);
    }else  SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), NULL, &this->coordinates->destRect, this->gameState->rotationAngle, NULL, SDL_FLIP_NONE);
}

void DataEngine::RenderCharacter() {  //Char unused

    SDL_RenderTexture(renderer, this->init_texture->get_imageTextureChar(), NULL, &this->coordinates->destRect);
}

//----------------------------------------------------------------------------------- RenderNPC

void DataEngine::RenderNPC(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &srcreect ,SDL_FRect &coord, SDL_FlipMode &flip){
    SDL_RenderTextureRotated(rend, texture, &srcreect, &coord, 0, NULL, flip);
}

//----------------------------------------------------------------------------------- RenderImportantThings

void DataEngine::RenderImportantThings(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &coord) {
    SDL_RenderTexture(rend, texture, NULL, &coord); 
}

//----------------------------------------------------------------------------------- RenderCoin

void DataEngine::RenderCoin(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &coord) {
    SDL_RenderTexture(rend, texture, NULL , &coord);
}

