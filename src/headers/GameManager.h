#pragma once
#include <iostream>
#include <fstream>
#include "GameTypes.h"
#include "Score.h"
#include "../Init_textures.h"
#include "../Init_sounds.h"
#include "../pak.h"
#include <SDL3/SDL.h>

// --------- Aliases ---------
using Surface = SDL_Surface; // For surfaces
using Texture = SDL_Texture; // For textures


class GameManager : public AnimationState, public Text, public ClientFixes {

    public:     

        // Startup
        GameManager () {
           StartGame();
        }

        // Cleanup (end)
        ~GameManager () { 
            EndGame();
        }

        // Main
        void StartGame(){
            forWindow();
            forRenderer();
            LoadTexture();
            forCoordinates();
            forMusic();
        }
        void forWindow();
        void forRenderer();
        void LoadTexture();
        void forCoordinates();
        void forMusic();
       
        void SetRenderColor(); 

        // ================= RENDER =================

        void RenderClear();  // !

        void RenderIdleChar(); // Update CHAR 
        void RenderNPC(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &srcreect ,SDL_FRect &coord, SDL_FlipMode &flip); // NPCS
        void RenderThings(SDL_Renderer *&rend, SDL_Texture *&texture, SDL_FRect &coord); // Coins, Map, fightmap, play, gameovermap
        
        void RenderPresent(); // !

        // ================= LOGIC =================

        void MovementChar(); // Movement char
        void MoveNPC(); // Move the NPC (rendernpc inside)
        void AllCollisionsAndScore(); // Update score and collisions
     
        // End
        void EndGame(){
            deleteObjects();
            ClearRenderer();
            ClearWindow();
            QuitTTF_And_SDL();
        }
        void ClearRenderer();
        void ClearWindow();
        void QuitTTF_And_SDL();
     
        // Client
        void forClient(); 

        // ================= COLLISION =================

        inline bool Collision(SDL_FRect& entity1Pos, SDL_FRect& entity2Pos) {
            return SDL_HasRectIntersectionFloat(&entity1Pos, &entity2Pos);
        }


        // ================= UPDATES ====================

        void updateScore();
        void ResetScore();
        void YouLost();
        void StartOver();

        // ================= MENU MUSIC =================

        void MenuMusic(); 
        
        // =========== "CONTINUE" TEXT EFFECT ===========

        void MoveTextContinue();

        //Pak
        SDL_Surface* LoadSurfaceFromPak( Pak *pak,  const std::string& path);

    private:   

        //---------------INIT---------------//
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;

        //For score
        Score *score = new Score; 
        //For assets
        Pak *pak = new Pak; 
        //For game state
        PlayerState *playerState = new PlayerState; 
        //For NPC state
        NpcState *npcState = new NpcState;
        //For effects state
        EffectState *effectState = new EffectState;
        //For music state
        Music *musicState = new Music;
        //For UI state
        UIState *uiState = new UIState; 
        //For input state 
        InputState *inputState = new InputState; 
        //For coordinates
        Coordinates *coordinates = new Coordinates;
        //For textures , surfaces , text
        InitTextures *init_texture = new InitTextures;
        //For sounds
        InitSounds *init_sound = new InitSounds;


        int WIDTH = 1280;
        int HEIGHT = 800;
        int showscore;   
        std::ofstream window_closed; // ClearWindow 
        void deleteObjects();

};
