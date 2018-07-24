#include <board.h>
#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;


Board::Board(int mines, int sizex, int sizey) : sizeX(sizex), sizeY(sizey),nbm2(mines)
{   nbc=0;
    nbm1=0;
    //nbm2=mines;

	 drap= new char* [sizeX];
	tab= new char* [sizeX];
	data = new char* [sizeX];
	for(int i = 0; i < sizeX; i++){
        drap[i] = new char[sizeY];
		tab[i] = new char[sizeY];
		data[i] = new char[sizeY];
	}

	// remplir les champs avec des #
	for(int y = 0; y < sizeY; y++)
	{
		for(int x = 0; x < sizeX; x++)
		{  drap[x][y] = '#';
			tab[x][y] = '#';
			data[x][y] = '#';
		}
	}

	//je mets les mines dans data
	for(int i = 0; i < mines; i++)
	{
		int x, y;
		while(true)
		{
			x = rand() % sizeX;
			y = rand() % sizeY;
			if(data[x][y] != 'M')
			{
				data[x][y] = 'M';
				break;
			}
		}
	}

	//je mets le numéro des mines dans data
	for(int y = 0; y < sizeY; y++)
	{
		for(int x = 0; x < sizeX; x++)
		{
			if(data[x][y] != 'M')
			{
				int minecount = 0;
				addToMinecount(x - 1, y - 1, minecount);
				addToMinecount(x, y - 1, minecount);
				addToMinecount(x + 1, y - 1, minecount);
				addToMinecount(x - 1, y, minecount);
				addToMinecount(x + 1, y, minecount);
				addToMinecount(x - 1, y + 1, minecount);
				addToMinecount(x, y + 1, minecount);
				addToMinecount(x + 1, y + 1, minecount);
				char c = (char)(((int)'0')+minecount);
				if (c!='0')
				data[x][y] = c;
				else
				data[x][y] = 'X';

			}
		}
	}
}

Board::~Board()
{

	for(int i = 0; i < sizeY; i++)
	{
		delete[] data[i];
		delete[] tab[i];
	}

	delete[] data;
	delete[] tab;
}


//le board apés l update du jeu
void Board::print()
{   system("cls");
    cout<<"__________________________"<<endl<<endl;
    cout<<"le nombre du coup: "<<nbc<<endl;
    cout<<"le nombre du mine: "<<nbm1<<endl<<endl;
    cout<<"__________________________"<<endl<<endl;
   // cout<<"   "<<"**************************************************************"<<endl;

	cout << endl << "   ";
	//cout<<"\t\t   ";
	cout<<"   "<<"  *  *  *  *  ";
	for(int i = 0; i < sizeX; i++)
	{

		cout << "*"<<"  ";
	}
	cout<<" *  *  *  *  *";
	cout << endl << "   ";
	cout<<"\t\t   ";

//numéro colonne
	for(int i = 0; i < sizeX; i++)
	{
         printf("%2d  ", i);
		//cout << i<<"  ";
	}
	cout << endl << endl;
//numero des lignes
	for(int y = 0; y < sizeY; y++)
	{   cout<<"   *";
	    cout<<"\t\t";
	    if (y<10)
		cout << y << "  ";
		else
         cout<<y<<" ";
		for(int x = 0; x < sizeX; x++)
		{
           printf("%2c  ",tab[x][y]);
			//cout << tab[x][y]<<"  ";
		}
		cout <<"\t\t *"<< endl;
	}
	cout << endl;
	cout<<"    "<<"  *  ";

	for(int i = 0; i < sizeX; i++)
	{

		cout << "*"<<"  ";
	}
	cout<<"*  *  *  *  *  *  *  *  *";
	cout<<endl<<"_______________________________________"<<endl<<endl;
}
void Board::Lostprint()
   {system("cls");
    cout<<"__________________________"<<endl<<endl;
    cout<<"le nombre du coup: "<<nbc<<endl;
    cout<<"le nombre du mine: "<<nbm1<<endl<<endl;
    cout<<"__________________________"<<endl<<endl;
   // cout<<"   "<<"**************************************************************"<<endl;

	cout << endl << "   ";
	//cout<<"\t\t   ";
	cout<<"   "<<"   *  *  *  *  ";
	for(int i = 0; i < sizeX; i++)
	{

		cout << "*"<<"  ";
	}
	cout<<" *  *  *  * ";
	cout << endl << "   ";
	cout<<"\t\t   ";
//numéro colonne
	for(int i = 0; i < sizeX; i++)
	{
         printf("%2d  ", i);
		//cout << i<<"  ";
	}
	cout << endl << endl;
//numero des lignes
	for(int y = 0; y < sizeY; y++)
	{   cout<<"   *";
	    cout<<"\t\t";
	    if (y<10)
		cout << y << "  ";
		else
         cout<<y<<" ";
		for(int x = 0; x < sizeX; x++)
		{
           printf("%2c  ",data[x][y]);
			//cout << tab[x][y]<<"  ";
		}
		cout <<"\t\t *"<< endl;
	}
	cout << endl;
	cout<<"   "<<"  *  * ";

	for(int i = 0; i < sizeX; i++)
	{

		cout << "*"<<"  ";
	}
	cout<<"*  *  *  *  *  *  *  *";
	cout<<endl<<"_______________________________________"<<endl<<endl;
}

char Board::getData(int x, int y)
{
	if(x < sizeX && y < sizeY && x >= 0 && y >= 0)
	{
		return data[x][y];
	}


	return 'o';

}


void Board::moveTotab(int x, int y)
{
	tab[x][y] = data[x][y];
}


void Board::checkEmptyField(int x, int y)
{
	if(x >= 0 && y >= 0 && x < sizeX && y < sizeY)
	{
		if(data[x][y] == 'X' && tab[x][y] == '#'){
			tab[x][y] = 'X';
			checkEmptyField(x - 1, y - 1);
			checkEmptyField(x, y - 1);
			checkEmptyField(x + 1, y - 1);
			checkEmptyField(x - 1, y);
			checkEmptyField(x + 1, y);
			checkEmptyField(x -1, y + 1);
			checkEmptyField(x, y + 1);
			checkEmptyField(x + 1, y + 1);
		} else {
			moveTotab(x, y);
		}
	}
}

// si data feha mine j incrimente
int Board::addToMinecount(int x, int y, int& minecount){
	if(x >= 0 && x < sizeX && y >= 0 && y < sizeY)
	{
		if(data[x][y] == 'M') minecount++;
	}
	return 0;
}

//0 pour continuer et 1 pour ganger
int Board::getGameStatus()
{int flag=0;
	for(int y = 0; y < sizeY; y++)
	{
		for(int x = 0; x < sizeX; x++)
		{

			if(tab[x][y] == 'D') {
				if(data[x][y] != 'M')
				{
					return 0;
				}
				else if(data[x][y] == 'M')
                    {flag ++;

                    }
			}

		}
	}
	if(flag<nbm2 || flag>nbm2)
        {return 0;}
        else if (flag==nbm2)
        {return 1;}
}
