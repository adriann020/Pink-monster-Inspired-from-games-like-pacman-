#include <iostream>
#include "headers/GameManager.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL.h> 
#include <Windows.h>

extern void execute(); // makepak.cpp

int main(int argc, char** argv) {

    //Load assets from pak 
    //execute();

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // Video, audio
    TTF_Init(); // Texts
 
    GameManager *startGame = new GameManager; // Startup

    HANDLE mutex = CreateMutex(NULL, TRUE, "MyUniqueAppMutexName"); // Just one client 
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        MessageBox(NULL, "Another client is already running.", "Client Check", MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

    HWND windowHandle = GetConsoleWindow();
	ShowWindow(windowHandle,SW_HIDE); // No console

    //------------------------------------------------------------

    // Client
    startGame->forClient();

    ReleaseMutex(mutex);

    delete startGame; // Cleanup (end)

    return 0;
}

