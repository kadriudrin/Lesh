#ifndef Public_h
#define Public_h
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <iostream>
#include <vector>
using namespace std;

#ifndef Watch_h
#include "Watch.h"
extern Clock MainClock;
#endif // !Watch_h

extern SDL_Window* win;
extern SDL_Renderer* render;
extern bool GameRunning;
extern SDL_Rect Camera;
extern bool JumpKey;

#ifndef Pawn_h
#include "Pawn.h"
extern vector <Pawn*> AllPawns;
extern Pawn Player;
extern Pawn Other;
#endif

extern float Hor;

extern float Ver;

#ifndef TileMap_h
#include "TileMap.h"
extern vector<Tile> AllTiles;
#endif

#ifndef Collision_h
#include "Collision.h"
#endif

extern void Quit();
#endif