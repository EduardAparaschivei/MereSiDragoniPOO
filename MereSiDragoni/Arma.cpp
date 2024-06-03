#include "Arma.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Arma::Arma() : Obiect("", "", 0, 0, 0, 0), PutereAtac(0)
{

}

Arma::Arma(string _Tip, string _Nume,int _PutereAtac,int _HP,int _Bani,int _XP,int _Scor)
	: Obiect(_Tip,_Nume,_HP,_Bani,_XP,_Scor),PutereAtac(_PutereAtac)
{

}

Arma::Arma(string& numefisier)
{
	ifstream file(numefisier);
	string linieFiser;
	getline(file, linieFiser);
	istringstream iss(linieFiser);
	string data;
	vector <string> Date;
	while (iss >> data)
	{
		Date.push_back(data);
	}
	try {
		PutereAtac = stoi(Date[2]);
		HP = stoi(Date[3]);
		Bani = stoi(Date[4]);
		XP = stoi(Date[5]);
		Scor = stoi(Date[6]);
	}
	catch (exception& e)
	{
		cout << "Eroare convertire!" << endl;
		return;
	}
	Tip = Date[0];
	Nume = Date[1];
}

Arma::~Arma()
{

}

void Arma::Info()
{
	Obiect::Info();
	cout << "Putere atac: " << PutereAtac << endl;
}

void Arma::setPutereAtac(int putere)
{
	PutereAtac = putere;
}
int Arma::getPutereAtac()const
{
	return PutereAtac;
}