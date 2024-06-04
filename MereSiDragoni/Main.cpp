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
#include "GamePlay.h"

using namespace std;

string numeFisier = "Jucator.txt";
string numeFisierDragoni = "Dragoni.txt";
string numeFisierOras = "Orase.txt";
Jucator jucator;
Oras oras;
Arma* arma = nullptr;
Dragon dragon;
GamePlay Joc;
int puncte = 5;
int alegere;
int sansa;

void Wrn()
{
	cout << "Alegere incorecta!" << endl;
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
	

	//jucator.addArma(arma1);
	//jucator.addArma(arma2);
	
	Joc.MeniuPrincipal(jucator, arma,numeFisier,numeFisierDragoni,oras,numeFisierOras);

	
	




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

