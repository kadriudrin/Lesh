#include "stdafx.h"
#include "Public.h"
#include <cmath>
#include "TileMap.h"

void TileMap::Draw()
{
	int looper = 0;
	for (int X = 0; X < NumberMap.size() / MapWidth; X++) {
		for (int Y = 0; Y <= MapWidth; Y++) {
			for (int i = 0; i < Tiles.size(); i++)
			{
				looper = (X * MapWidth) + Y;
				if (looper != NumberMap.size()){
					if (NumberMap.at(looper) == i)
					{
						Tiles.at(i).MyPawn.MyRect.x = Y * TileWidth;
						Tiles.at(i).MyPawn.MyRect.y = X * TileWidth;
						Tiles.at(i).MyPawn.Draw();
					}
					if (Tiles.at(i).Collidable) {
						Player.Move();
						if (Check(Player.NextRect, Tiles.at(i).MyPawn.MyRect)) {
							Player.SetAcc(0, 0);
							Player.SetVel(0, 0);
						}
						//else Player.SetVel(Hor * Player.VelSpd, Ver * Player.VelSpd);
					}
				}
				else {
					break;
				}
			};
		}
	}
} 

TileMap::TileMap(int TileW, int MapW)
{
	TileWidth = TileW;
	if (MapW == -1)
		MapWidth = sqrt(NumberMap.size());
	else
		MapWidth = MapW;
}

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

Tile::Tile(int i, Pawn m, bool isCollidable)
{
	ID = i;
	MyPawn = m;
	Collidable = isCollidable;
	if (Collidable)
		AllTiles.push_back(*this);
}