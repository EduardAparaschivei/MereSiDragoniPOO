#include <iostream>
#include <stdio.h>
#include "Core.h"
#include "Jucator.h"
#include "Obiect.h"
#include "Dragon.h"
#include "Arma.h"
#include "ObiectSpecial.h"
#include "Oras.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

string numeFisier = "Jucator.txt";
string numeFisierDragoni = "Dragoni.txt";
string numeFisierOras = "Orase.txt";
Jucator jucator;
Dragon dragon;
int puncte = 5;
int alegere;
int sansa;

void Wrn()
{
	cout << "Alegere incorecta!" << endl;
}
void MainMenu()
{
	
	
	do {
		system("cls");
		cout << "Mere si Dragoni\n1.Start Joc\n2.Continuare Joc\n3.Instructiuni\n4.Exit" << endl;
		cout << "Do: ";
		cin >> alegere;
		switch (alegere)
		{
		case 1:
		{
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

				cin >> alegere;
				if (alegere == 1)
				{
					jucator.upPutere();
					puncte--;
				}
				else if (alegere == 2)
				{
					jucator.upInteligenta();
					puncte--;

				}
				else if (alegere == 3)
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
			while (true)
			{

				cout << "Esti gata sa incepi jocul?\n1.DA\n2.Nu\nDO:";
				cin >> alegere;
				if (alegere == 1)
				{
					jucator.salvareFisier();
					alegere = 4;
					break;
				}
				else if (alegere == 2)
				{
					break;
				}
				else
				{
					Wrn();
				}
			}
		}
		break;

		case 2:
		{
			ifstream file(numeFisier);
			if (!file.is_open())
			{
				cout << "Fisier gol sau inexistent!" << endl;
				getchar();
				break;
			}
			Jucator jucator2(numeFisier);
			jucator = jucator2;
			alegere = 4;
		}
		break;
		default:

			break;
		}

	} while (alegere != 4);
}
void Exploreaza()
{
	sansa = rand() % 100 + 1;
	if (sansa <= 30)
	{
		cout << "Ai gasit un oras!" << endl;
		this_thread::sleep_for(chrono::seconds(3));
	}
	else
	{
		
		while (true)
		{
			cout << "Ai gasit un dragon!\nLupti?\n1.Da\n2.Nu\nDO: ";
			cin >> alegere;
			if (alegere == 1)
			{
				alegere = 3;
				break;
			}
			else if (alegere == 2)
			{
				break;
			}
			else
			{
				Wrn();
			}
		}
	}
}
void Lupta()
{
	do {
		system("cls");
		cout << "Lupta a inceput!\nViata Jucator:"<<jucator.getHp()<<"\nViata Dragon: "<<dragon.getHp()<<"\n1.Ataca\n2.Foloseste obiect\n3.Fugi!\nDO: ";
		cin >> alegere;
		switch (alegere)
		{
		case 1:
		{
			dragon.setHp(dragon.getHp() - (10 * jucator.getPutere()));
			cout << "Ai provocat " << 10 * jucator.getPutere() << " daune dragonului!" << endl;
			jucator.setHp(jucator.getHp() - (dragon.getDaune() * dragon.getDificultate()));
			cout << "Dragonul ti-a provocat " << dragon.getDaune() * dragon.getDificultate() << " daune!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
		}break;

		default:
			break;
		}

	} while (alegere != 3 && dragon.getHp() > 0);
	alegere = 0;
}

int main()
{
	
	Oras oras1(numeFisierOras, 1);
	oras1.Info();
	oras1.printObiecte();



	/**
	MainMenu();
	do {
		system("cls");
		jucator.Info();
		cout << "Ce vrei sa faci acum?\n1.Exploreaza\n2.Inapoi la meniu\nDO: ";
		if (alegere != 3)
		{
			cin >> alegere;
		}
		switch (alegere)
		{
		case 1:
		{
			Exploreaza();
		}
		break;

		case 3:
		{
			Dragon dragon2(numeFisierDragoni,jucator.getStagiu());
			dragon = dragon2;
			Lupta();
		}break;
		default:
		{
			Wrn();
		}
			break;
		}

	} while (true);
	**/


			
	return 0;

}

