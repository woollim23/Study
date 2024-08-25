#pragma once

enum
{
	BOARD_MAX_SIZE = 100
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL,

};

class Board
{
public:
	Board();
	~Board();

private:
	TileType _tile[BOARD_]
};

