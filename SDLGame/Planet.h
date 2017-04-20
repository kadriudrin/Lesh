#ifndef Planet_h
#define Planet_h

Pawn New;

Pawn Old;

TileMap LagunaMap(300);

Tile GroundT;

void Start() {
	Camera.w = 1500;
	Camera.h = 1500;
	Player = Pawn(1, 1, 50, "Src/Cover.jpg");
	Player.AccSpd = 10.f;
	Player.VelSpd = 500.f;
	Player.Gravity = 5;
	Player.JumpForce = 500;

	int map1[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 1, 1, 0, 0, 0,
		1, 0, 0, 1, 0, 0, 0, 0,
		1, 0, 0, 1, 1, 0, 0, 0,
		1, 0, 0, 1, 0, 0, 0, 0,
		1, 1, 0, 1, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};
	LagunaMap.NumberMap.assign(map1, map1 + 64);
	LagunaMap.SetMapWidth();
	Old = Pawn(1, 1, 300, "Src/Cover.jpg");
	LagunaMap.Tiles.push_back(Tile(0, Pawn(0, 0, 25, "l")));
	LagunaMap.Tiles.push_back(Tile(1, Old, true));

	//Other = Pawn(200, 200, 100, "Src/Cover_1.1.jpg");
}

void Update() {
	SDL_RenderClear(render);
	LagunaMap.Draw();
	Player.Update();
	JumpKey = false;
	Other.Draw();
	Player.Draw();
	Camera.x = Player.X;
	Camera.y = Player.Y;
	Camera.x = (Camera.x + Player.MyRect.w / 2) - 640 / 2;
	Camera.y = (Camera.y + Player.MyRect.h / 2) - 480 / 2;
	SDL_RenderPresent(render);
}

void Events() {
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
		switch (ev.type)
		{
		case SDL_QUIT:
			Quit();
		case SDL_KEYDOWN:
			switch (ev.key.keysym.scancode)
			{
			case SDL_SCANCODE_A:
				Hor = -1;
				break;
			case SDL_SCANCODE_D:
				Hor = 1;
				break;
			case SDL_SCANCODE_W:
				Ver = -1;
				break;
			case SDL_SCANCODE_S:
				Ver = 1;
				break;
			default:
				break;
			}
			switch (ev.key.keysym.sym)
			{
			case SDLK_SPACE:
				JumpKey = true;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (ev.key.keysym.scancode)
			{
			case SDL_SCANCODE_A:
			case SDL_SCANCODE_D:
				Hor = 0;
				break;
			case SDL_SCANCODE_W:
			case SDL_SCANCODE_S:
				Ver = 0;
				break;
			case SDL_SCANCODE_SPACE:
				JumpKey = false;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}
#endif