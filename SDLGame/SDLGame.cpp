#include "stdafx.h"
#include "Public.h"
#include "Planet.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVENTS);
	win = SDL_CreateWindow("SDLGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	render = SDL_CreateRenderer(win, -1, 0);
	Start();
	for (int i = 0; i < AllPawns.size(); i++) {
		AllPawns.at(i)->Start();
	}
	while (GameRunning) {
		MainClock.Tick();
		Events();
		Update();
	}
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
	}