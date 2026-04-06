#include "headers/Comp.h"


void DataEngine::MoveTextContinue() {

    float speedText = 0.8 * (deltaTime / 16); 

    if(this->coordinates->contRect.y != 700 && this->gameState->turntextcont == false ) {
        this->coordinates->contRect.y -= speedText; 
        if(this->coordinates->contRect.y  <= 700 ) {
            this->gameState->turntextcont = true; 
        }
    }

    if(this->gameState->turntextcont == true) {
        this->coordinates->contRect.y += speedText;
        if(this->coordinates->contRect.y >= 750) {
            this->gameState->turntextcont = false; 
        }
    }
    
}

