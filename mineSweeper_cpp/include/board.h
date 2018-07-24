#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	Board(int mines, int sizex, int sizey);
	~Board();
	void print();
	char getData(int x, int y);
	void moveTotab(int x, int y);
	void checkEmptyField(int x, int y);
	int addToMinecount(int x, int y, int& minecount);
	int getGameStatus();
	void Lostprint();
	int nbm1;//les mines qui seront affiché
	const int nbm2;//les mines réeles
	int nbc;
	char** drap;
	char** tab;

private:

//un tableau privé pour les donnés
	char** data;

	const int sizeX;
	const int sizeY;
};

#endif
