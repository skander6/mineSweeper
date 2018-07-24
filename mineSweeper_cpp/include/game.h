#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
public:
	Game(int minecount, int x, int y);
	~Game();
	int update(int x, int y,int choice);
	int getnbc();
	void Lost();
private:

	Board board;
};

#endif
