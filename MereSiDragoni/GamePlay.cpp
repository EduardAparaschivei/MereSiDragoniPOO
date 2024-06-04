#include "GamePlay.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

GamePlay::GamePlay()
{

}
//Meniul Principal al jocului
void GamePlay::MeniuPrincipal(Jucator& jucator, Arma*& arma, string numeFisier, string numeFisier2,Oras& oras, string numeFisierOrase)
{
	char alegere;
	do {
		cout << "1.Start Joc\n2.Reluare Joc\n3.Ajutor\n0.Exit\nAlege: ";
		alegere = _getch();
		switch (alegere)
		{
		case '1':
		{
			GamePlay::CreazaJucator(jucator);
			alegere = '0';
			break;
		}
		case '2':
		{
			GamePlay::PreiaJucator(jucator, numeFisier);
			if (jucator.getNume() != "")
			{
				alegere = '0';
			}
			break;
		}
		case '0':
			exit(0);
			break;
			
		default:
			cout << "Alegere inexistenta!" << endl;
			break;
		}
		system("cls");
	} while (alegere != '0');
	StagiuNeutru(jucator, arma,numeFisier,numeFisier2,oras,numeFisierOrase);
}

//Meniul de dupa meniul pricipal
void GamePlay::StagiuNeutru(Jucator& jucator, Arma*& arma, string numeFisier, string numeFisier2,Oras& oras, string numeFisierOrase)
{
	char alegere;
	do {
		cout << "1.Exploreaza\n2.Foloseste Obiect\n3.Afiseaza detalii caracter\n0.Inapoi la meniu\nAlege: ";
		alegere = _getch();
		switch (alegere)
		{
		case '1':
		{
			GamePlay::Exploreaza(jucator,arma,numeFisier,numeFisier2,oras,numeFisierOrase);
			break;
		}
		case '2':
			GamePlay::EchipeazaArma(jucator, arma,numeFisier);
		default:
			break;
		case '3':
			system("cls");
			jucator.Info();
			cout << "Arma echipata: ";
			if (arma != nullptr)
			{
				arma->Info();
			}
			cout << "\nInventar:" << endl;
			if (jucator.getDimInventar() != 0)
			{
				jucator.printObiecte();
			}
			this_thread::sleep_for(chrono::seconds(5));
			break;
		}
		system("cls");
	} while (alegere != '0');
	GamePlay::MeniuPrincipal(jucator,arma,numeFisier,numeFisier2,oras,numeFisierOrase);
}

//Metoda pentru realizarea actiunii de explorare
void GamePlay::Exploreaza(Jucator& jucator, Arma*& arma, string numeFisier, string numeFisier2, Oras& oras, string numeFisierOrase)
{
	int sansa = obtineeveniment();

	if (sansa == 0)
	{
		cout << "Dragon!\nLupti?(1.DA/2.NU):";
		char alege = _getch();
		if (alege == '1')
		{
			Lupta(jucator, arma, numeFisier, numeFisier2);
		}
	}
	else if (sansa == 1)
	{
		cout << "Ai gasit un mar in padure!" << endl;
		ObiectSpecial mar("mar", "Mar", 1, 0, 10, 10);
		jucator.addObiectSpecial(mar);
	}
	else if (sansa == 2)
	{
		cout << "Ai ajuns intr-un Oras.\nVrei sa vizitezi magazinul?(1.Da/2.Nu):";
		char alege = _getch();
		if (alege == '1')
		{
			ViziteazaMagazin(jucator, oras,numeFisierOrase);
		}
	}
	else if (sansa == 3)
	{
		cout << "Ai fost atacat de lupi!\n-5 HP" << endl;
		jucator.setHp(jucator.getHp() - 5);
		if (jucator.getHp() < 0)
		{
			cout << "Ai murit!";
			exit(0);
		}
	}
	else if(sansa == 4)
	{
		cout << "Nimic!" << endl;
	}
	else
	{
		cout << "Ai gasit o arma!" << endl;
		Arma arma;
		jucator.addArma(arma);
	}
	this_thread::sleep_for(chrono::seconds(1));
}

//Metoda pentru a folosi un obiect aflat in inventarul jucatorului
void GamePlay::EchipeazaArma(Jucator& jucator,Arma*& arma, string numeFisier)
{
	if (jucator.getDimInventar() == 0)
	{
		cout << "Invetar GOL!";
		this_thread::sleep_for(chrono::seconds(2));
		return;
	}
	do {
		system("cls");
		jucator.printObiecte();
		cout << "Alege un Item: ";
		char input = _getch();
		int obiectales = input - '0';
		obiectales =obiectales-1;
		if (obiectales >= jucator.getDimInventar() || obiectales < 0)
		{
			cout << "Obiect Inexistent!";
			break;
		}
		Obiect* temporar = jucator.getObiect(obiectales);
		if (Arma* armaselectata = dynamic_cast<Arma*>(temporar))
		{
			cout << "Arma echipata!" << endl;
			arma = armaselectata;
			break;
		}
		ObiectSpecial* specialselectat = dynamic_cast<ObiectSpecial*>(temporar);
		if (specialselectat->getTip() == "mar")
		{
			cout << "Ai mancat un mar!";
			jucator.setHp(jucator.getHp() + 20);
			jucator.removeObiect(obiectales);
			jucator.salvareFisier();
			PreiaJucator(jucator, numeFisier);
			break;
		}
		
	}while(true);
	this_thread::sleep_for(chrono::seconds(1));
}

//metoda pentru a crea o entiate jucator noua
void GamePlay::CreazaJucator(Jucator& jucator)
{
	jucator.setPutere();jucator.setAgilitate();jucator.setInteligenta();
	jucator.setBani(0);jucator.setHp(100);jucator.setScor(0);
	jucator.setXP(0);jucator.setLevel();jucator.setStagiu(1);
	system("cls");
	int puncte = 5;
	char alegere;
	string nume;
	cout << "Introdu Nume: ";
	cin >> nume;
	jucator.setNume(nume);
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
	jucator.salvareFisier();

}

//metoda pentru a continua jocul cu o entitate jucator luata din fisier
void GamePlay::PreiaJucator(Jucator& jucator,string numeFisier)
{
	ifstream file(numeFisier);
	if (!file.is_open())
	{
		cout << "\nNu s-a gasit nimic!(Apasa ENTER)" << endl;
		getchar();
		return;
	}
	Jucator jucator2(numeFisier);
	jucator = jucator2;

}

//metoda pentru sistemul de lupta
void GamePlay::Lupta(Jucator& jucator,Arma*& arma,string numeFisier, string numeFisier2)
{	
	Dragon dragon(numeFisier2,jucator.getStagiu());
	char alegere;
	do {
		system("cls");
		cout << "Lupta a inceput!\nViata Jucator:" << jucator.getHp() << "\nDragon: "; dragon.Info(); cout<< "\n1.Ataca\n2.Foloseste obiect\n3.Fugi!\nDO: ";
		alegere = _getch();
		switch (alegere)
		{
		case '1':
		{
			if (arma != nullptr)
			{
				dragon.setHp(dragon.getHp() - (10 * jucator.getPutere())-arma->getPutereAtac());
				DegradareItem(jucator, arma);
			}
			else
			{
				dragon.setHp(dragon.getHp() - (10 * jucator.getPutere()));
			}
			if (arma != nullptr)
			{
				cout << "Ai provocat " << 10 * jucator.getPutere()+arma->getPutereAtac() << " daune dragonului!" << endl;
			}
			else
			{
				cout << "Ai provocat " << 10 * jucator.getPutere() << " daune dragonului!" << endl;
			}
			jucator.setHp(jucator.getHp() - (dragon.getDaune() * dragon.getDificultate()));
			cout << "Dragonul ti-a provocat " << dragon.getDaune() * dragon.getDificultate() << " daune!" << endl;
			if (dragon.getHp() <= 0)
			{
				cout << "Ai castigat lupta!";
				TransferStatusuri(jucator, dragon);
				Arma arma;
				TransferStatusuri(jucator, arma);
				jucator.addArma(arma);
				jucator.upStagiu();
				jucator.salvareFisier();
			}
			this_thread::sleep_for(chrono::seconds(1));
		}break;
		case '2':
			EchipeazaArma(jucator, arma, numeFisier);
			break;
		case '3':
			cout << "Ai fugit!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			break;

		default:
			break;
		}

	} while (alegere != 3 && dragon.getHp() > 0&&jucator.getHp()>0);
	if (jucator.getHp() < 0)
	{
		cout << "Ai murit!";
		exit(0);
	}

	alegere = 0;
}

void GamePlay::ViziteazaMagazin(Jucator& jucator, Oras& oras,string numeFisierOrase)
{
	Oras oras2(numeFisierOrase, jucator.getStagiu());
	oras = oras2;
	char alegere;
	do {
		system("cls");
		oras.Info();
		oras.printObiecte();
		cout << "\n1.Cumpara\n2.Vinde\n3.Fura\n0.Pleaca\nAlege:";
		alegere = _getch();
		switch (alegere)
		{
		case '1':
		{
			system("cls");
			oras.printObiecte();
			cout << "\nAlege ce item vrei sa cumperi: ";
			char input = _getch();
			int obiectales = input - '0';
			obiectales = obiectales - 1;
			if (obiectales >= oras.getDimInventar() || obiectales < 0)
			{
				cout << "\nObiect Inexistent!";
				break;
			}
			Obiect* temporar = oras.getObiect(obiectales);
			if (jucator.getBani() < (temporar->getBani() - jucator.getInteligenta()))
			{
				cout<<"Nu ai suficienti bani!"<<endl;
				this_thread::sleep_for(chrono::seconds(1));
				break;
			}
			if (Arma* armaselectata = dynamic_cast<Arma*>(temporar))
			{
				cout <<"\nAi cumparat:\n";
				armaselectata->Info();
				jucator.addArma(armaselectata);
				jucator.setBani(jucator.getBani() - (armaselectata->getBani() - jucator.getInteligenta()));
				jucator.salvareFisier();

			}
			else
			{
				ObiectSpecial* specialselectat = dynamic_cast<ObiectSpecial*>(temporar);
				cout << "\nAi cumparat:\n ";
				specialselectat->Info();
				jucator.addObiectSpecial(specialselectat);
				jucator.setBani(jucator.getBani() - (specialselectat->getBani() - jucator.getInteligenta()));
				jucator.salvareFisier();
			}
			
			this_thread::sleep_for(chrono::seconds(1));
			break;
		}
		case '2':
		{
			system("cls");
			if (jucator.getDimInventar() == 0)
			{
				cout << "Nu ai nimic in Inventar!";
				this_thread::sleep_for(chrono::seconds(1));
				break;
			}

			jucator.printObiecte();
			cout << "\nCe vrei sa vinzi: ";
			char index = _getch();
			int ales = index - '0';
			ales -= 1;
			if (ales >= 0 && ales < jucator.getDimInventar())
			{
				cout << "Ai vandut:";
				jucator.getObiect(ales)->Info();
				jucator.setBani(jucator.getBani() + jucator.getObiect(ales)->getBani());
				jucator.removeObiect(ales);
				jucator.salvareFisier();
				this_thread::sleep_for(chrono::seconds(1));
				break;
			}
			

			break;
		}
		case '3':
		{
			system("cls");
			oras.printObiecte();
			cout << "Ce obiect vrei sa furi: ";
			char input = _getch();
			int obiectales = input - '0';
			obiectales = obiectales - 1;
			if (obiectales >= oras.getDimInventar() || obiectales < 0)
			{
				cout << "\nObiect Inexistent!";
				break;
			}
			int i = rand() % 20;
			if ( i != 5)
			{
				cout << "Ai esuat! Platesti amenda de 10 banuti si o lovitura zdravana!";
				jucator.setHp(jucator.getHp() - 5);
				jucator.setBani(jucator.getBani() - 10);
				this_thread::sleep_for(chrono::seconds(2));
			}
			else
			{
				Obiect* temporar = oras.getObiect(obiectales);
				if (Arma* armaselectata = dynamic_cast<Arma*>(temporar))
				{
					cout << "\nAi furat:\n";
					armaselectata->Info();
					jucator.addArma(armaselectata);
					TransferStatusuri(jucator, temporar);
					jucator.salvareFisier();

				}
				else
				{
					ObiectSpecial* specialselectat = dynamic_cast<ObiectSpecial*>(temporar);
					cout << "\nAi furat:\n ";
					specialselectat->Info();
					jucator.addObiectSpecial(specialselectat);
					TransferStatusuri(jucator, temporar);
					jucator.salvareFisier();
				}
				this_thread::sleep_for(chrono::seconds(2));
			}

			break;
		}
		default:

			break;
		}

	} while (alegere != '0');
}

//metoda pentru degradare item
void GamePlay::DegradareItem(Jucator& jucator, Arma*& arma)
{
	arma->setHp(arma->getHp() - 1);
	if (arma->getHp() == 0)
	{
		int i = 0;
		for (Obiect* obiect : jucator.getObiecteCopie())
		{
			if (Arma* armainventar =dynamic_cast<Arma*>(obiect))
			{
				if (arma == armainventar)
				{
					jucator.removeObiect(i);
					arma = nullptr;
					jucator.salvareFisier();
					break;
				}
			}
			i++;
		}
		
	}
	
}

//metode pentru transfer de statusuri
void GamePlay::TransferStatusuri(Jucator& jucator, Dragon& dragon)
{
	jucator.setBani(jucator.getBani() + dragon.getBani());
	jucator.setScor(jucator.getScor() + dragon.getScor());
	jucator.setXP(jucator.getXP() + dragon.getXP());
}
void GamePlay::TransferStatusuri(Jucator& jucator, Obiect& arma)
{
	jucator.setScor(jucator.getScor() + arma.getScor());
	jucator.setXP(jucator.getXP() + arma.getXP());
}
void GamePlay::TransferStatusuri(Jucator& jucator, Obiect* special)
{
	jucator.setScor(jucator.getScor() + special->getScor());
	jucator.setXP(jucator.getXP() + special->getXP());
}

//obtinearea unui nr aleator pentru metoda Exploreaza
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
	else if(randomnr < 94)
	{
		return 4;
	}
	else
	{
		return 5;
	}
}