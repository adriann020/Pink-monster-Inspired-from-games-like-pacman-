#include "headers/GameManager.h"

void GameManager::MoveTextContinue() {

    float speedText = 0.8 * (deltaTime / 16); 

    if(this->coordinates->contRect.y != 700 && this->effectState->turntextcont == false ) {
        this->coordinates->contRect.y -= speedText; 
        if(this->coordinates->contRect.y  <= 700 ) {
            this->effectState->turntextcont = true; 
        }
    }

    if(this->effectState->turntextcont == true) {
        this->coordinates->contRect.y += speedText;
        if(this->coordinates->contRect.y >= 750) {
            this->effectState->turntextcont = false; 
        }
    }
    
}

