#include "headers/GameManager.h"
// Everything below is running on loop in client -> Client.cpp !!!

//Update score  
void GameManager::updateScore() {

    showscore = this->score->getScore(); 

    std::string scoreText = "Score: " + std::to_string(showscore);

    if (this->init_texture->get_imageTextureScore()) {
        SDL_DestroyTexture(this->init_texture->get_imageTextureScore());
        this->init_texture->get_imageTextureScore() = nullptr;
    }

    this->init_texture->get_imageSurfaceTexts() = TTF_RenderText_Blended(font, scoreText.c_str(), 0, color); // Amandoua aici pt update
    this->init_texture->get_imageTextureScore() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceTexts());
    SDL_DestroySurface(this->init_texture->get_imageSurfaceTexts()); 

}

//Reset score
void GameManager::ResetScore(){
    if(CollisionNPC(this->coordinates->destRect, this->coordinates->npcRect) == 1 || CollisionNPC(this->coordinates->destRect, this->coordinates->blueNpcRect) == 1){

        this->uiState->showLOST = true; // Verifies collision with NPCs

        showscore = this->score->reset();
        std::string scoreText = "Score: " + std::to_string(showscore);

        if (this->init_texture->get_imageTextureScore()) { 
            SDL_DestroyTexture(this->init_texture->get_imageTextureScore());
            this->init_texture->get_imageTextureScore() = nullptr;
        }

        this->init_texture->get_imageSurfaceTexts() = TTF_RenderText_Blended(font, scoreText.c_str(), 0, color); // Amandoua aici for update
        this->init_texture->get_imageTextureScore() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceTexts());
        SDL_DestroySurface(this->init_texture->get_imageSurfaceTexts()); 
    }
}

//NPC Movement
void GameManager::MoveNPC() {

    /*if (npcRect.x < destRect.x) { // npc follows char
        npcRect.x += speed2;
        flip = SDL_FLIP_NONE;
    }
    if (npcRect.x > destRect.x) {
        npcRect.x -= speed2;
        flip = SDL_FLIP_HORIZONTAL;
    }
    
    if (npcRect.y < destRect.y) {
        npcRect.y += speed2;
    }
    if (npcRect.y > destRect.y) {
        npcRect.y -= speed2;
    }*/

    float movement = this->npcState->speed2 * (deltaTime / 16); 

    // Owl NPC
    this->coordinates->srcrect2.x = sprite2 * 32;        
    this->coordinates->srcrect2.y = 0;
    this->coordinates->srcrect2.w = 32;
    this->coordinates->srcrect2.h = 64;

    if(this->coordinates->npcRect.x != 1219 && this->npcState->turn == false) {
        this->coordinates->npcRect.x += movement;
        RenderNPC(renderer, this->init_texture->get_imageTextureNPC(), this->coordinates->srcrect2 ,this->coordinates->npcRect, this->npcState->flip); // rendernpc
        if(this->coordinates->npcRect.x >= 1219){
            this->npcState->turn = true; this->npcState->flip = SDL_FLIP_HORIZONTAL; sprite2 = 0; // release
            this->npcState->turn4 = false;
        } 
    }

    if(this->npcState->turn == true && this->npcState->turn2  == false) {
        this->coordinates->npcRect.y -= movement;
        RenderNPC(renderer, this->init_texture->get_imageTextureNPC(), this->coordinates->srcrect2 ,this->coordinates->npcRect, this->npcState->flip); // rendernpc
        if(this->coordinates->npcRect.y <= 70){
            this->npcState->turn2 = true;  sprite2 = 0; // release
        }
    }

    if(this->npcState->turn2 == true && this->npcState->turn3 == false) {
        this->coordinates->npcRect.x -= movement;
        RenderNPC(renderer, this->init_texture->get_imageTextureNPC(), this->coordinates->srcrect2 ,this->coordinates->npcRect, this->npcState->flip); // rendernpc
        if(this->coordinates->npcRect.x <= 10){
            this->npcState->turn3 = true; this->npcState->flip = SDL_FLIP_NONE; sprite2 = 0; // release
        }
    }

    if(this->npcState->turn3 == true && this->npcState->turn4 == false) {
        this->coordinates->npcRect.y += movement;
        RenderNPC(renderer, this->init_texture->get_imageTextureNPC(), this->coordinates->srcrect2 ,this->coordinates->npcRect, this->npcState->flip); // rendernpc
        if(this->coordinates->npcRect.y >= 300){
            this->npcState->turn4 = true; sprite2 = 0; // release  
        }
    }

    if(this->npcState->turn4 == true) { // Reset
        this->npcState->turn = false;
        this->npcState->turn2 = false;
        this->npcState->turn3 = false;
        this->npcState->turn4 = false;
    }
    
    // Blue NPC
    this->coordinates->srcrect3.x = sprite3 * 32;        
    this->coordinates->srcrect3.y = 0;
    this->coordinates->srcrect3.w = 32;
    this->coordinates->srcrect3.h = 64;

    if(this->coordinates->blueNpcRect.x != 1219 && this->npcState->turnb == false) {
        this->coordinates->blueNpcRect.x += movement;
        RenderNPC(renderer, this->init_texture->get_imageTextureBlueNPC(), this->coordinates->srcrect3 ,this->coordinates->blueNpcRect, this->npcState->flipBlue); // rendernpc
        if(this->coordinates->blueNpcRect.x >= 1219){
            this->npcState->turnb = true; this->npcState->flipBlue = SDL_FLIP_HORIZONTAL; sprite3 = 0; // release
            this->npcState->turnb4 = false;
        } 
    }

    if(this->npcState->turnb == true && this->npcState->turnb2  == false) {
        this->coordinates->blueNpcRect.y -= movement;
        RenderNPC(renderer, this->init_texture->get_imageTextureBlueNPC(), this->coordinates->srcrect3 ,this->coordinates->blueNpcRect, this->npcState->flipBlue); // rendernpc
        if(this->coordinates->blueNpcRect.y <= 385){
            this->npcState->turnb2 = true;  sprite3 = 0; // release
        }
    }   

    if(this->npcState->turnb2 == true && this->npcState->turnb3 == false) {
        this->coordinates->blueNpcRect.x -= movement;
        RenderNPC(renderer, this->init_texture->get_imageTextureBlueNPC(), this->coordinates->srcrect3 ,this->coordinates->blueNpcRect, this->npcState->flipBlue); // rendernpc
        if(this->coordinates->blueNpcRect.x <= 10){
            this->npcState->turnb3 = true; this->npcState->flipBlue = SDL_FLIP_NONE; sprite3 = 0; // release
        }
    }

    if(this->npcState->turnb3 == true && this->npcState->turnb4 == false) {
        this->coordinates->blueNpcRect.y += movement;
        RenderNPC(renderer, this->init_texture->get_imageTextureBlueNPC(), this->coordinates->srcrect3 ,this->coordinates->blueNpcRect, this->npcState->flipBlue); // rendernpc
        if(this->coordinates->blueNpcRect.y >= 640){
            this->npcState->turnb4 = true; sprite3 = 0; // release  
        }
    }

    if(this->npcState->turnb4 == true) { // Reset
        this->npcState->turnb = false;
        this->npcState->turnb2 = false;
        this->npcState->turnb3 = false;
        this->npcState->turnb4 = false;
    }
    
}

//CHAR Movement
void GameManager::MovementChar() {

    // Getting input everytime
    bool const up = this->inputState->state[SDL_SCANCODE_W];
    bool const down = this->inputState->state[SDL_SCANCODE_S];
    bool const left = this->inputState->state[SDL_SCANCODE_A];
    bool const right = this->inputState->state[SDL_SCANCODE_D];

    int keysPressed = up + down + left + right;

    float movement = this->playerState->speed * (deltaTime / 16); // 60 fps
    float knockbackAmount = this->playerState->speed * (deltaTime / 16); // Knockback char - walls
    

    // Reduces movement speed when multiple keys are pressed to prevent faster diagonal movement
    if (keysPressed >= 2) 
        movement *= 0.8;

    // idle
    if(keysPressed == 0) {
        sprite = 0; // release 

        if (this->init_texture->get_imageTextureChar()) { 
            SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
            this->init_texture->get_imageTextureChar() = nullptr;
        }

        this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pink.bmp" );
        this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
        SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());

        RenderTextureRotated(); // char updated 
    }

    if(right && left || up && left && right || down && left && right || up && left && down || up && right && down || up && down ) { // fixed bug la taste apasate simultan 
    
        if (this->init_texture->get_imageTextureChar()) { 
            SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
            this->init_texture->get_imageTextureChar() = nullptr;
        }

        this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pink.bmp" );
        this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
        SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());

        RenderTextureRotated(); // char updated 
        return;
    }    


    // fixed double texture bug
    if (up && right) { // diagonals
        
        this->playerState->doubletexturefix = true;

        if(this->coordinates->destRect.y <= 30){ // up block
            this->coordinates->destRect.y += 4;
        }

        if(this->coordinates->destRect.x >= 1211){ // right block
            this->coordinates->destRect.x -= 4;
        }

        this->coordinates->destRect.x += movement;
        this->coordinates->destRect.y -= movement;
        this->playerState->fix = false;

        this->coordinates->srcrect.x = sprite * 32;        
        this->coordinates->srcrect.y = 0;
        this->coordinates->srcrect.w = 32;
        this->coordinates->srcrect.h = 64;


        if (this->init_texture->get_imageTextureChar()) { 
            SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
            this->init_texture->get_imageTextureChar() = nullptr;
        }

        this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
        this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
        SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());

        SDL_RenderTexture(renderer, this->init_texture->get_imageTextureChar(), &this->coordinates->srcrect, &this->coordinates->destRect); // char updated

    }else if(up && left) {
            
            this->playerState->doubletexturefix = true;
    
            if(this->coordinates->destRect.y <= 30){ // up block
                this->coordinates->destRect.y += 4;
            }
    
            if(this->coordinates->destRect.x <= 10){ // left block
                this->coordinates->destRect.x += 4;
            }
    
            this->coordinates->destRect.x -= movement;
            this->coordinates->destRect.y -= movement;
            this->playerState->fix = true;
    
            this->coordinates->srcrect.x = sprite * 32;        
            this->coordinates->srcrect.y = 0;
            this->coordinates->srcrect.w = 32;
            this->coordinates->srcrect.h = 64;
    
    
            if (this->init_texture->get_imageTextureChar()) { 
                SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
                this->init_texture->get_imageTextureChar() = nullptr;
            }
    
            this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
            this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
            SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());

            SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), &this->coordinates->srcrect, &this->coordinates->destRect, 0 , NULL , SDL_FLIP_HORIZONTAL); // char updated

    }else if (down && right) {
            
            this->playerState->doubletexturefix = true;
    
            if(this->coordinates->destRect.y > 730){ // down block
                this->coordinates->destRect.y -= 4;
            }
    
            if(this->coordinates->destRect.x >= 1211){ // right block
                this->coordinates->destRect.x -= 4;
            }
    
            this->coordinates->destRect.x += movement;
            this->coordinates->destRect.y += movement;
            this->playerState->fix = false;
    
            this->coordinates->srcrect.x = sprite * 32;        
            this->coordinates->srcrect.y = 0;
            this->coordinates->srcrect.w = 32;
            this->coordinates->srcrect.h = 64;
    
    
            if (this->init_texture->get_imageTextureChar()) {
                SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
                this->init_texture->get_imageTextureChar() = nullptr;
            }
    
            this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
            this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
            SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());

            SDL_RenderTexture(renderer, this->init_texture->get_imageTextureChar(), &this->coordinates->srcrect, &this->coordinates->destRect); // char updated
            
    }else if(down && left) {
            
            this->playerState->doubletexturefix = true;
    
            if(this->coordinates->destRect.y > 730){ // down block
                this->coordinates->destRect.y -= 4;
            }
    
            if(this->coordinates->destRect.x <= 10){ // left block
                this->coordinates->destRect.x += 4;
            }
    
            this->coordinates->destRect.x -= movement;
            this->coordinates->destRect.y += movement;
            this->playerState->fix = true;
    
            this->coordinates->srcrect.x = sprite * 32;        
            this->coordinates->srcrect.y = 0;
            this->coordinates->srcrect.w = 32;
            this->coordinates->srcrect.h = 64;
    
    
            if (this->init_texture->get_imageTextureChar()) { 
                SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
                this->init_texture->get_imageTextureChar() = nullptr;
            }
    
            this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
            this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
            SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());

            SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), &this->coordinates->srcrect, &this->coordinates->destRect, 0 , NULL , SDL_FLIP_HORIZONTAL); // char updated

    }else this->playerState->doubletexturefix = false;


    // up
    if (up && this->coordinates->destRect.y - movement >= 0 && this->playerState->doubletexturefix == false) { 

        if(this->coordinates->destRect.y <= 30){
            this->coordinates->destRect.y += knockbackAmount;
        }

        this->coordinates->destRect.y -= movement;

        this->coordinates->srcrect.x = sprite * 32;        
        this->coordinates->srcrect.y = 0;
        this->coordinates->srcrect.w = 32;
        this->coordinates->srcrect.h = 64;

        if(this->playerState->fix == true) {
          
          if(this->init_texture->get_imageTextureChar()) {
              SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
              this->init_texture->get_imageTextureChar() = nullptr;
            }

          this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
          this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
          SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());
          SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), &this->coordinates->srcrect, &this->coordinates->destRect, 0 , NULL, SDL_FLIP_HORIZONTAL);

        }else {

          if (this->init_texture->get_imageTextureChar()) {
              SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
              this->init_texture->get_imageTextureChar() = nullptr;
             }

          this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
          this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
          SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());
          SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), & this->coordinates->srcrect, &this->coordinates->destRect , 0 , NULL, SDL_FLIP_NONE); 

        }
    
    }

    // down
    if (down && this->coordinates->destRect.y + this->coordinates->destRect.h + movement <= HEIGHT && this->playerState->doubletexturefix == false) { 

        if(this->coordinates->destRect.y > 730){
            this->coordinates->destRect.y -= knockbackAmount;
        }

        this->coordinates->destRect.y += movement;

        this->coordinates->srcrect.x = sprite * 32;       
        this->coordinates->srcrect.y = 0;
        this->coordinates->srcrect.w = 32;
        this->coordinates->srcrect.h = 64;

        if(this->playerState->fix == false){

           if (this->init_texture->get_imageTextureChar()) {
                SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
                this->init_texture->get_imageTextureChar() = nullptr;
            }

           this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
           this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
           SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());
           SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), & this->coordinates->srcrect, &this->coordinates->destRect , 0 , NULL, SDL_FLIP_NONE); 

        }else {

            if (this->init_texture->get_imageTextureChar()) {
                SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
                this->init_texture->get_imageTextureChar() = nullptr;
            }
                
            this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
            this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
            SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());
            SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), & this->coordinates->srcrect, &this->coordinates->destRect , 0 , NULL, SDL_FLIP_HORIZONTAL); 
        }

    }

    // left
    if (left && this->coordinates->destRect.x - movement >= 0 && this->playerState->doubletexturefix == false) { 

        if(this->coordinates->destRect.x <= 10){
            this->coordinates->destRect.x += knockbackAmount;
        }

        this->coordinates->destRect.x -= movement;
        this->playerState->fix = true;

        this->coordinates->srcrect.x = sprite * 32;       
        this->coordinates->srcrect.y = 0;
        this->coordinates->srcrect.w = 32;
        this->coordinates->srcrect.h = 64;

        if (this->init_texture->get_imageTextureChar()) {
            SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
            this->init_texture->get_imageTextureChar() = nullptr;
        }

        this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
        this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
        SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());

        SDL_RenderTextureRotated(renderer, this->init_texture->get_imageTextureChar(), &this->coordinates->srcrect, &this->coordinates->destRect, 0 , NULL, SDL_FLIP_HORIZONTAL); 

    }

    // right
    if (right && this->coordinates->destRect.x + this->coordinates->destRect.w + movement <= WIDTH && this->playerState->doubletexturefix == false) { 

        if(this->coordinates->destRect.x >= 1211){
            this->coordinates->destRect.x -= knockbackAmount;
        }

        this->coordinates->destRect.x += movement;
        this->playerState->fix = false;

        this->coordinates->srcrect.x = sprite * 32;        
        this->coordinates->srcrect.y = 0;
        this->coordinates->srcrect.w = 32;
        this->coordinates->srcrect.h = 64;

        if (this->init_texture->get_imageTextureChar()) {
            SDL_DestroyTexture(this->init_texture->get_imageTextureChar());
            this->init_texture->get_imageTextureChar() = nullptr;
        }

        this->init_texture->get_imageSurfaceChar() = LoadSurfaceFromPak( pak, "chars/pinkrun.bmp" );
        this->init_texture->get_imageTextureChar() = SDL_CreateTextureFromSurface(renderer, this->init_texture->get_imageSurfaceChar());
        SDL_DestroySurface(this->init_texture->get_imageSurfaceChar());

        SDL_RenderTexture(renderer, this->init_texture->get_imageTextureChar(), & this->coordinates->srcrect, &this->coordinates->destRect); 

    }

        // Collisions char - walls 
        if (CollisionWall(this->coordinates->wall1Rect, this->coordinates->destRect) == 1 || CollisionWall(this->coordinates->wall2Rect, this->coordinates->destRect) == 1) {

        // DOAR W
        if (up && !down && !left && !right) {
            this->coordinates->destRect.y += knockbackAmount;
        }

        // DOAR S
        else if (down && !up && !left && !right) {
            this->coordinates->destRect.y -= knockbackAmount;
        }

        // DOAR A
        else if (left && !right && !up && !down) {
            this->coordinates->destRect.x += knockbackAmount;
        }

        // DOAR D
        else if (right && !left && !up && !down) {
            this->coordinates->destRect.x -= knockbackAmount;
        }

        // W + A
        else if (up && left && !down && !right) {
            this->coordinates->destRect.y += knockbackAmount;
            this->coordinates->destRect.x += knockbackAmount;
        }

        // W + D
        else if (up && right && !down && !left) {
            this->coordinates->destRect.y += knockbackAmount;
            this->coordinates->destRect.x -= knockbackAmount;
        }

        // S + A
        else if (down && left && !up && !right) {
            this->coordinates->destRect.y -= knockbackAmount;
            this->coordinates->destRect.x += knockbackAmount;
        }

        // S + D
        else if (down && right && !up && !left) {
            this->coordinates->destRect.y -= knockbackAmount;
            this->coordinates->destRect.x -= knockbackAmount;
        }

        // Dreapta + sus + jos 
        else if(right && up && down && !left){
            this->coordinates->destRect.x -= knockbackAmount;
        }

        // Stanga + sus + jos
        else if(left && up && down && !right){
            this->coordinates->destRect.x += knockbackAmount;
        }
        
        // Sus + dreapta + stanga
        else if(up && right && left && !down){
            this->coordinates->destRect.y += knockbackAmount;
        }

        // Jos + dreapta + stanga
        else if(down && right && left && !up){
            this->coordinates->destRect.y -= knockbackAmount;
        }
    }
   
}

//Loss
void GameManager::YouLost() {

    if(this->uiState->showLOST == true){

        this->uiState->startover = true;
        //SDL_RenderTexture(renderer, this->init_textures->get_imageTextureLOST(), NULL, &LOSTrect);
        SDL_RenderTexture(renderer, this->init_texture->get_imageTextureGameOverMap(), NULL, &this->coordinates->gameovermapRect);

        this->coordinates->destRect.x = 0;    // char (hidden)
        this->coordinates->destRect.y = 1200;

        this->coordinates->npcRect.x = 1200; // npc (hidden)
        this->coordinates->npcRect.y = 0;

        this->coordinates->blueNpcRect.x = 1200; // npc (hidden)
        this->coordinates->blueNpcRect.y = 0;

        this->coordinates->gameovermapRect.h = HEIGHT; // back to normal
        this->coordinates->gameovermapRect.w = WIDTH; 

        SDL_RenderTexture(renderer, this->init_texture->get_imageTextureStartOver(), NULL, &this->coordinates->StartOverRect); // peste render gameovermap sa se vada

        this->playerState->speed = 0; // char
        this->npcState->speed2 = 0; // npc
        
    }else this->uiState->startover = false;
    
}

//StartOver
void GameManager::StartOver() {
    
    this->uiState->play = true; // Menu ended

    this->uiState->showLOST = false; // Startover , map etc ended

    if(this->uiState->startover == true) {

        this->playerState->speed = 3.5; // char original var
        this->npcState->speed2 = 4; // npc original var
    
        this->coordinates->destRect.x = 26;   // char original var
        this->coordinates->destRect.y = 550;
    
        this->coordinates->npcRect.x = 19; // npc (to 19 , it is != 20 in movenpc)
        this->coordinates->npcRect.y = 300;

        this->coordinates->blueNpcRect.x = 19; // npc (to 19 , it is != 20 in movenpc)
        this->coordinates->blueNpcRect.y = 640;

    }

    this->coordinates->gameovermapRect.h = 0; 
    this->coordinates->gameovermapRect.w = 0; 

}

//MenuMusic
void GameManager::MenuMusic() {

    SDL_ResumeAudioDevice(SDL_GetAudioStreamDevice(this->init_sound->get_streamMenu()));

}
