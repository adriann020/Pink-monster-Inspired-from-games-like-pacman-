#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <fstream>
#include <vector>

// --------- Aliases ---------
using Surface = SDL_Surface; // For surfaces
using Texture = SDL_Texture; // For textures

class InitTextures {

    public:
    InitTextures();
    ~InitTextures();
    //---------------MAPS-WALLS-NPCS-CHAR---------------//
    inline auto& get_imageSurfaceChar() { return imageSurfaceChar; }
    inline auto& get_imageSurfaceForMaps() { return imageSurfaceForMaps; }
    inline auto& get_imageSurfaceForNPCs() { return imageSurfaceForNPCs; }
    inline auto& get_imageSurfaceForWalls() { return imageSurfaceForWalls; }
    
    inline auto& get_imageTextureChar() { return imageTextureChar; }
    inline auto& get_imageTextureMap() { return imageTextureMap; }
    inline auto& get_imageTextureFightmap() { return imageTextureFightmap; }
    inline auto& get_imageTexturePlay() { return imageTexturePlay; }
    inline auto& get_imageTextureGameOverMap() { return imageTextureGameOverMap; }
    inline auto& get_imageTextureNPC() { return imageTextureNPC; }
    inline auto& get_imageTextureBlueNPC() { return imageTextureBlueNPC; }

    inline auto& get_imageTextureWall1() { return imageTextureWall1; }
    inline auto& get_imageTextureWall2() { return imageTextureWall2; }
    auto& get_wallsFromVector(int index) { return wallsTextures.at(index); } // Refactor (not built in yet)

    //---------------COINS---------------//
    inline auto& get_imageSurfaceC0() { return imageSurfaceC0; }
    inline auto& get_imageTextureC0() { return imageTextureC0; }
    inline auto& get_imageTextureC1() { return imageTextureC1; }
    inline auto& get_imageTextureC2() { return imageTextureC2; }
    inline auto& get_imageTextureC3() { return imageTextureC3; }
    inline auto& get_imageTextureC4() { return imageTextureC4; }
    inline auto& get_imageTextureC5() { return imageTextureC5; }

    auto& get_coinsFromVector(int index) { return coinsTextures.at(index); } // Refactor (not built in yet)

     //---------------TEXTS---------------//
    inline auto& get_imageSurfaceTexts() { return textSurForTexts; }
    inline auto& get_imageTextureScore() { return textTexScore; }
    inline auto& get_imageTextureCont() { return textTexCont; }
    inline auto& get_imageTextureLOST() { return textTexLOST; }
    inline auto& get_imageTextureStartOver() { return textTexStartOver; }

    private: 
    //---------------MAPS-WALLS-NPCS-CHAR---------------//
        Surface *imageSurfaceChar; // char
        Surface *imageSurfaceForMaps; // mapa , fightmap, play, gameovermap
        Surface *imageSurfaceForNPCs; // owl,blue
        Surface *imageSurfaceForWalls; // walls

        Texture *imageTextureChar; // char 
        Texture *imageTextureMap; // map
        Texture *imageTextureFightmap; // fightmap
        Texture *imageTexturePlay; // play
        Texture *imageTextureGameOverMap; // gameovermap

        Texture *imageTextureNPC; // npc owl
        Texture *imageTextureBlueNPC; // npc blue

        Texture *imageTextureWall1; // wall1
        Texture *imageTextureWall2; // wall2

        std::vector<Texture*> wallsTextures; // 

        //---------------COINS---------------//
        Surface *imageSurfaceC0; 

        Texture *imageTextureC0; 
        Texture *imageTextureC1; 
        Texture *imageTextureC2; 
        Texture *imageTextureC3;
        Texture *imageTextureC4; 
        Texture *imageTextureC5; 

        std::vector<Texture*> coinsTextures; 

        //---------------TEXTS---------------//

        Surface *textSurForTexts; // score , cont, "you lost" ,  startover

        Texture *textTexScore; // score
        Texture *textTexCont; // cont
        Texture *textTexLOST; // "you lost"
        Texture *textTexStartOver; // startover

        // Validation
        std::ofstream file_InitTex;
        static int NrObjects;

}; 
