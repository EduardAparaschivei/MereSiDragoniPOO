#include "GamePlay.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

GamePlay::GamePlay()
{

}

void GamePlay::Exploreaza()
{
	int sansa = obtineeveniment();

	if (sansa == 0)
	{
		cout << "Dragon!" << endl;
	}
	else if (sansa == 1)
	{
		cout << "Padure!" << endl;
	}
	else if (sansa == 2)
	{
		cout << "Magazin!" << endl;
	}
	else if (sansa == 3)
	{
		cout << "Lupi!" << endl;
	}
	else
	{
		cout << "Nimic!" << endl;
	}
}

void GamePlay::CreazaJucator(Jucator& jucator)
{
	int puncte = 5;
	char alegere;
	string nume;
	cout << "Introdu Nume: ";
	cin >> nume;
	jucator.setNume(nume);
	system("cls");
	cout << "Ai 5 puncte pentru a le pune in abilitati." << endl;
	while (puncte != 0)
	{
		cout << "Nume:" << jucator.getNume() << endl;
		cout << "Puncte ramase: " << puncte << endl;
		cout << "1.Putere-" << jucator.getPutere()
			<< "\n2.Inteligenta" << jucator.getInteligenta()
			<< "\n3.Agilitate" << jucator.getAgilitate()
			<< "\nDO: ";

		alegere = _getch();
		if (alegere == '1')
		{
			jucator.upPutere();
			puncte--;
		}
		else if (alegere == '2')
		{
			jucator.upInteligenta();
			puncte--;

		}
		else if (alegere == '3')
		{
			jucator.upAgilitate();
			puncte--;
		}
		else {
			cout << "Alegere incorecta!" << endl;
		}
		system("cls");

	}
	cout << "Nume: " << jucator.getNume() << " P: " << jucator.getPutere() << " I: " << jucator.getInteligenta() << " A: " << jucator.getAgilitate() << endl;
}

int GamePlay::obtineeveniment()
{
	

	int randomnr = rand() % 100;

	if (randomnr < 20)
	{
		return 0;
	}
	else if(randomnr < 40)
	{
		return 1;
	}
	else if (randomnr < 60)
	{
		return 2;
	}
	else if(randomnr < 70)
	{
		return 3;
	}
	else
	{
		return 4;
	}
}
