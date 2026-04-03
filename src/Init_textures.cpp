#include "Init_textures.h"

int InitTextures::NrObjects = 0;

InitTextures::InitTextures() {
    NrObjects++;

    if (NrObjects == 1)
    {
        file_InitTex.open("../data/logs.txt", std::ios::app);
        file_InitTex << "[SYSTEM] -> Initializing ALL textures...\n";
        file_InitTex.close();
    }

}

InitTextures::~InitTextures() {

    // -------- SURFACES --------
    if(imageSurfaceChar){ SDL_DestroySurface(imageSurfaceChar); imageSurfaceChar = nullptr; }
    if(imageSurfaceForMaps){ SDL_DestroySurface(imageSurfaceForMaps); imageSurfaceForMaps = nullptr; }
    if(imageSurfaceForNPCs){ SDL_DestroySurface(imageSurfaceForNPCs); imageSurfaceForNPCs = nullptr; }
    if(imageSurfaceForWalls){ SDL_DestroySurface(imageSurfaceForWalls); imageSurfaceForWalls = nullptr; }

    // -------- TEXTURES --------
    if(imageTextureChar){ SDL_DestroyTexture(imageTextureChar); imageTextureChar = nullptr; }
    if(imageTextureMap){ SDL_DestroyTexture(imageTextureMap); imageTextureMap = nullptr; }
    if(imageTextureFightmap){ SDL_DestroyTexture(imageTextureFightmap); imageTextureFightmap = nullptr; }
    if(imageTexturePlay){ SDL_DestroyTexture(imageTexturePlay); imageTexturePlay = nullptr; }
    if(imageTextureGameOverMap){ SDL_DestroyTexture(imageTextureGameOverMap); imageTextureGameOverMap = nullptr; }
    if(imageTextureNPC){ SDL_DestroyTexture(imageTextureNPC); imageTextureNPC = nullptr; }
    if(imageTextureBlueNPC){ SDL_DestroyTexture(imageTextureBlueNPC); imageTextureBlueNPC = nullptr; }

    if(imageTextureWall1){ SDL_DestroyTexture(imageTextureWall1); imageTextureWall1 = nullptr; }
    if(imageTextureWall2){ SDL_DestroyTexture(imageTextureWall2); imageTextureWall2 = nullptr; }

    for (auto& texture : wallsTextures) { // Refactor (not built in yet)
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }

    for (auto& texture : coinsTextures) { // Refactor (not built in yet)
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }

    if(imageTextureC0){ SDL_DestroyTexture(imageTextureC0); imageTextureC0 = nullptr; }
    if(imageTextureC1){ SDL_DestroyTexture(imageTextureC1); imageTextureC1 = nullptr; }
    if(imageTextureC2){ SDL_DestroyTexture(imageTextureC2); imageTextureC2 = nullptr; }
    if(imageTextureC3){ SDL_DestroyTexture(imageTextureC3); imageTextureC3 = nullptr; }
    if(imageTextureC4){ SDL_DestroyTexture(imageTextureC4); imageTextureC4 = nullptr; }
    if(imageTextureC5){ SDL_DestroyTexture(imageTextureC5); imageTextureC5 = nullptr; }

    // -------- TEXT --------
    if(textTexScore){ SDL_DestroyTexture(textTexScore); textTexScore = nullptr; }
    if(textTexCont){ SDL_DestroyTexture(textTexCont); textTexCont = nullptr; }
    if(textTexLOST){ SDL_DestroyTexture(textTexLOST); textTexLOST = nullptr; }
    if(textTexStartOver){ SDL_DestroyTexture(textTexStartOver); textTexStartOver = nullptr; }

    NrObjects--;

    if(NrObjects == 0){
       file_InitTex.open("../data/logs.txt", std::ios::app);
       file_InitTex << "[SYSTEM] -> Destroying ALL textures...\n";
       file_InitTex.close();
    }
}