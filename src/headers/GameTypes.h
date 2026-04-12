#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>


// --------- Aliases ---------
using RectF = SDL_FRect; // For coordinates
using Color = SDL_Color; // For text's color
using Font = TTF_Font; // For text's font


struct ClientFixes {

  bool CloseClientWindowIssue = false; // Window Error issue fixed

};

struct PlayerState { 
  
  float speed = 3.5; // Char
  float rotationAngle = 0; // (not used yet)
  float imgWidth = 1000, imgHeight = 1000; // char (not used)
  
  bool fix = false; // Char (0 left/1 right)
  bool doubletexturefix = false; // Fixed char double texture 

};

struct EffectState {
  bool turntextcont = false; // Continue text effect
};

struct NpcState {

  // For NPCS Movement
  float speed2 = 4; // Npcs

  bool turn = false; // right Npc owl
  bool turn2 = false; // up Npc owl
  bool turn3 = false; // left Npc owl
  bool turn4 = false; // down Npc owl

  bool turnb = false; // right Npc blue
  bool turnb2 = false; // up Npc blue
  bool turnb3 = false; // left Npc blue
  bool turnb4 = false; // down Npc blue

  // Left-Right direction for sprites
  SDL_FlipMode flip = SDL_FLIP_NONE; // Npc owl
  SDL_FlipMode flipBlue = SDL_FLIP_NONE; // Npc blue
};

struct InputState {
  const bool *state = SDL_GetKeyboardState(NULL);
};

struct UIState {

  bool changeMap = false; // Changemap
  bool play = false; // Play 
  
  bool showLOST = false; // Showlost 
  bool startover = false; // Reset check

};


struct AnimationState {

  Uint64 now = SDL_GetTicksNS(); // speed
  Uint64 last = now;
  float deltaTime = 0; // characters movement (speed)

  Uint64 ticks = SDL_GetTicks(); // for sprites
  Uint64 seconds = ticks / 1000; // (not used yet)

  Uint64 sprite = 0; // char
  Uint64 sprite2 = 0; // npc owl
  Uint64 sprite3 = 0; // npc blue

};

struct Coordinates { 

  RectF mapRect; // Map
  RectF destRect; // Char
  RectF mapFightRect; // Fight map
  RectF playRect; // Play
  RectF gameovermapRect; // Gameovermap

  RectF coin0Rect; // Coins
  RectF coin1Rect; 
  RectF coin2Rect; 
  RectF coin3Rect; 
  RectF coin4Rect; 
  RectF coin5Rect; 

  RectF scoreRect; // Score text
  RectF contRect; // Continue text
  RectF LOSTrect; // "you lost" text
  RectF StartOverRect; // Start over text

  RectF npcRect; // Npc owl
  RectF blueNpcRect; // Npc blue
  
  RectF wall1Rect; // Wall1
  RectF wall2Rect; // Wall2

  RectF srcrect = { 0, 0, 32, 64 }; // for frame (char)
  RectF srcrect2 = { 0, 0, 32, 64 }; // for frame (npc owl)
  RectF srcrect3 = { 0, 0, 32, 64 }; // for frame (npc blue)


};

struct Text { const
     
  Color color = {255, 255, 255, 255}; 
  Color color2 = {0xff, 0 , 0}; // used for "you lost" text , but not used anymore (kept in case)
  Color color3 = {255 , 255, 255, 255}; // Press ... to play

  Font *font = TTF_OpenFont("fonts/moldy.ttf", 33);
  Font *font2 = TTF_OpenFont("fonts/moldy.ttf", 33);

};

struct Music {

   SDL_AudioSpec wave_spec; // Menu
   Uint8 * wave_sound;
   Uint32 wave_soundlen;

   SDL_AudioSpec wave_specCoin; // Coin
   Uint8 * wave_soundCoin;
   Uint32 wave_soundlenCoin;

   const int SDL_AUDIO_DEVICE_DEFAULT_OUTPUT = 0xFFFFFFFF;
   bool stopmenumusic = false; // Stop menu music

};

