#ifndef Pawn_h
#define Pawn_h
struct Pawn {
	float X, Y;
	float XVel, YVel;
	float XAcc, YAcc;
	float AccSpd;
	float VelSpd;
	float Gravity, JumpForce;
	SDL_Surface* MySurface = nullptr;
	SDL_Texture* MyTexture = nullptr;
	SDL_Rect MyRect;
	SDL_Rect NextRect;

	void Start();
	void Update();
	void Draw();
	void Move();

	void SetVel(float, float);
	void SetAcc(float, float);

	Pawn(){};

	Pawn(float nX, float nY, float Size, char* ImgLoc);
	~Pawn();
};
#endif