#include "stdafx.h"
#include "Public.h"
#include "Pawn.h"

Pawn::Pawn(float nX, float nY, float Size, char* ImgLoc) {
	X = Y = XVel = YVel = XAcc = YAcc = 0;
	MyRect.x = X = nX;
	MyRect.y = Y = nY;
	MyRect.w = MyRect.h = Size;
	MySurface = IMG_Load(ImgLoc);
	if (!MySurface)
		cout << "Failed To Load File: \"" << ImgLoc << "\"" << endl;
	else {
		MyTexture = SDL_CreateTextureFromSurface(render, MySurface);
		if (!MyTexture)
			cout << "Failed To Create Texture From Surface!" << endl;
		else {
			SDL_FreeSurface(MySurface);
			AllPawns.push_back(this);
		}
	}
	cout << X << endl;
	cout << Y << endl;
}

Pawn::~Pawn()
{
}

void Pawn::Start() {

}
void Pawn::Update() {
	SetVel((XVel + XAcc), (YVel + YAcc));
	X += XVel*MainClock.dt;
	Y += YVel*MainClock.dt;
	NextRect = MyRect;
	NextRect.x += XVel*MainClock.dt;
	NextRect.y += YVel*MainClock.dt;
	MyRect.x = X;
	MyRect.y = Y;
}
void Pawn::Draw() {
	MyRect.x -= Camera.x;
	MyRect.y -= Camera.y;
	SDL_RenderCopy(render, MyTexture, 0, &MyRect);
}

void Pawn::Move()
{
	YAcc = Gravity;
	Player.SetAcc(Hor * Player.AccSpd, YAcc);
	if (JumpKey) {
		YVel = -JumpForce;
	}
}

void Pawn::SetVel(float xv, float yv)
{
	XVel = xv;
	YVel = yv;
}

void Pawn::SetAcc(float xa, float ya)
{
	XAcc = xa;
	YAcc = ya;
}