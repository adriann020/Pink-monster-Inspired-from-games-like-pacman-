#include <iostream>
#include "headers/GameManager.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL.h> 
#include <Windows.h>

/**
 * Builds a new asset package (PAK) from game resources.
 *
 * This function is implemented in makepak.cpp and is intended
 * to be used for packaging assets (textures)
 * into a single distributable file.
 *
 * Note:
 * - Safe to call from the main thread.
 * - Performs heavy file I/O and processing.
 * - Typically used during development or build steps,
 *   not during normal game runtime.
*/
extern void execute(); // check makepak.cpp for more info

int main(int argc, char** argv) {

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // Video, audio
    TTF_Init(); // Texts
 
    GameManager *startGame = new GameManager; // Startup

	// Ensure only one instance of the application is running
    HANDLE mutex = CreateMutex(NULL, TRUE, "MyUniqueAppMutexName"); 
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        MessageBox(NULL, "Another client is already running.", "Client Check", MB_OK | MB_ICONEXCLAMATION);
        return 1;
    }

	// Hide console window (for release mode)
    HWND windowHandle = GetConsoleWindow();
	ShowWindow(windowHandle,SW_HIDE); 

    // Client
    startGame->forClient();

    ReleaseMutex(mutex);

    delete startGame; // Cleanup (end)

    return 0;
}
