#include <game.h>
#include <iostream>
#include <time.h>

using namespace std;


Game::Game(int minecount, int sizeX, int sizey) : board(Board(minecount, sizeX, sizey))
{   board.nbm1=minecount;
    //1 afficher du plateau
	board.print();
}
int Game::getnbc(){return board.nbc;}
void Game::Lost(){board.Lostprint();}

Game::~Game()
{

}


int Game::update(int x, int y,int choice)
{   board.nbc=board.nbc+1;
    if (choice==1)
    {

	if(board.getData(x, y) == 'M')
	{
		// si mine , you lost
		return -1;
	} else if(board.getData(x, y) == 'X')
	{
		// si un blanc :
		board.checkEmptyField(x, y);
		// ni x ni m
	} else if(board.getData(x, y) == 'o'){
      //rien a faire
	}
	else {
		// envoi les donnés pour les affiché
		board.moveTotab(x, y);
	}
	if(board.getGameStatus() == 1) {
		board.print();
		return 1;
	}


	board.print();
	return 0;
}
else if (choice==2)
{  if(board.drap[x][y]!='D' && board.tab[x][y]=='#')
     {board.nbm1=board.nbm1-1;
    board.drap[x][y]='D';
    board.tab[x][y]='D';
    board.print();}
    else{
         board.nbm1=board.nbm1+1;
        board.tab[x][y]='#';
        board.print();
    }
    if(board.getGameStatus() == 1) {
		board.print();
		return 1;
	}

}
}
