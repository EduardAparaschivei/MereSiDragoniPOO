#include "ObiectSpecial.h"
#include <iostream>
#include <cstring>

using namespace std;

ObiectSpecial::ObiectSpecial() : Obiect("", "", 0, 0, 0, 0)
{

}

ObiectSpecial::ObiectSpecial(string _Tip, string _Nume,int _HP, int _Bani, int _XP, int _Scor)
	: Obiect(_Tip, _Nume, _HP, _Bani, _XP, _Scor)
{

}

ObiectSpecial::~ObiectSpecial()
{
	
}

void ObiectSpecial::Info()
{
	Obiect::Info();
}

void ObiectSpecial::Utilizare(string tip)
{
	if (tip == "bomba")
	{
		cout << "S-a arauncat bomba." << endl;
	}
	else
	{
		cout << "Nimic special." << endl;
	}
}