#ifndef TileMap_h
#define TileMap_h

struct Tile;

class TileMap
{
public:
	vector<Tile> Tiles;
	vector<int> NumberMap;
	int TileWidth;
	int MapWidth;
	void Draw();
	TileMap(int TileW, int MapW = -1);
	TileMap();
	void SetMapWidth() { MapWidth = sqrt(NumberMap.size()); }
	~TileMap();
};

struct Tile {
	int ID;
	Pawn MyPawn;
	bool Collidable;
	Tile() {};
	Tile(int, Pawn, bool isCollidable = false);
};
#endif