#include "stdafx.h"
#include "Public.h"
#include "Collision.h"

bool Check(SDL_Rect one, SDL_Rect two)
{
	return (one.x < two.x + two.w &&
		one.x + one.w > two.x &&
		one.y < two.y + two.h &&
		one.h + one.y > two.y);
}

bool CheckHor(SDL_Rect one, SDL_Rect two)
{
	return (one.x < two.x + two.w &&
		one.x + one.w > two.x);
}

bool CheckVer(SDL_Rect one, SDL_Rect two)
{
	return (one.y < two.y + two.h &&
		one.h + one.y > two.y);
}