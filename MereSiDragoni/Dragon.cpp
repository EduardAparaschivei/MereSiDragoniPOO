#include "Dragon.h"
#include <cstring>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

Dragon::Dragon() : Core("", 0, 0, 0, 0), ID(0), Dificultate(0), Daune(0)
{

}

Dragon::Dragon(string Nume,int HP,int Bani,int XP,int Scor,int _ID,int _Dificultate,int _Daune)
	:Core(Nume,HP,Bani,XP,Scor),ID(_ID),Dificultate(_Dificultate),Daune(_Daune)
{

}

Dragon::Dragon(string& numefisier,int stagiu)
{
	ifstream file(numefisier);
	if (file.is_open())
	{
		string linieFisier;
		for (int i = 0;i < stagiu;i++)
		{
			getline(file, linieFisier);
		}
		
			istringstream iss(linieFisier);
			string data;
			vector <string> Date;
			while (iss >> data)
			{
				Date.push_back(data);
			}
			try
			{
				ID = stoi(Date[0]);
				HP = stoi(Date[2]);
				Bani = stoi(Date[3]);
				XP = stoi(Date[4]);
				Scor = stoi(Date[5]);
				Dificultate = stoi(Date[6]);
				Daune = stoi(Date[7]);
			}
			catch (exception& e)
			{
				cout << "Eroare convertire!" << endl;
				return;
			}
			Nume = Date[1];
		
	}
	else
	{

		cout << "Nu s-a putut deshide fisier!" << endl;
	}
}

Dragon& Dragon::operator=(const Dragon& dragon)
{
	if (this != &dragon)
	{
		Nume = dragon.Nume;HP = dragon.HP;Bani = dragon.Bani;
		XP = dragon.Bani;Scor = dragon.Scor;ID = dragon.ID;
		Dificultate = dragon.Dificultate;Daune = dragon.Daune;
	}
	return *this;
}

Dragon::~Dragon()
{

}

void Dragon::Info()
{
	Core::Info();
	cout << "ID: " << ID << " Dificultate: " << Dificultate << " Daune: " << Daune << endl;
}

int Dragon::getDificultate()
{
	return Dificultate;
}
int Dragon::getDaune()
{
	return Daune;
}
