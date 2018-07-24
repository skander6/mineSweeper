#include <iostream>
#include <game.h>
#include <string>
#include <fstream>
#include <time.h>


using namespace std;


void getUserInput(int& result, const string message)
{
	cout << message;
	while(!(cin >> result))
	{
		cout << message;
	}
}


int main()
{   string nom;
     char input;
	int minecount, sizeX, sizeY, x, y, status,choice,i;
	cout<<"voulez vous jouer(entrer 'j') ou voir les scores(entrer 's') ?  ";
	cin>>input;
	system("cls");
	if (input=='j')
    {getUserInput(sizeY, "Entrer le nombre du ligne : ");
	getUserInput(sizeX, "Entrer le nombre du colonne : ");
	getUserInput(minecount, "Entrer le nombre des mines: ");
	system("cls");
	Game game(minecount, sizeX, sizeY);

	while(true)
	{

		cout<<"choisir la ligne: ";
		do
		cin>>y;
		while(sizeY<=y || y<0);
		cout<<endl;
		cout<<"choisir la colonne: ";
		do
		cin>>x;
		while(sizeX<=x || x<0);
		cout<<endl<<"voulez vous decouvrir une case(entrer 1) ou placer un drapeau(entrer 2) : " ;
		do
		cin>>choice;
		while(choice>2 || choice<1);

		status = game.update(x, y,choice);
		if(status == -1)
		{  game.Lost();
			cout << endl << "GAME OVER !" << endl;
			break;
		}
		if(status == 1)
		{

			cout << endl << "Congratulations ! vous avez gagne en " << game.getnbc()<< " coup(s) !" << endl;
			cout<<"entrer votre nom pour enregistrer le score : "<<endl;
			cin>>nom;
			ofstream fichier("score.txt", ios::app);
			fichier << nom <<" : "<<game.getnbc()<<endl;
			fichier.close();
			cout<<" THANK YOU "<<nom<<" !"<<endl;

			break;
		}
	}}
	else if (input=='s'){
         string contenu;
        ifstream fichier("score.txt", ios::in);
         while(getline(fichier, contenu))  // tant que l'on peut mettre la ligne dans "contenu"
        {
                cout << contenu << endl;  // on l'affiche
        }

	}
	else
        cout<<"votre choix est introuvable , relancez le jeu de nouveau !"<<endl;
	return 0;
}
