#include "stdafx.h"
#include "Public.h"

Clock MainClock;

SDL_Window* win;
SDL_Renderer* render;
bool GameRunning = true;
SDL_Rect Camera;
bool JumpKey;
Pawn Player;
Pawn Other;
float Hor;
float Ver;

vector <Pawn*> AllPawns;
vector <Tile> AllTiles;

void Quit() {
	GameRunning = false;
}