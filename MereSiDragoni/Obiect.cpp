#include "Obiect.h"
#include <iostream>
#include <cstring>

using namespace std;

Obiect::Obiect():Core("",0,0,0,0),Tip("")
{
	
}

Obiect::Obiect(string _Tip,std::string _Nume, int _HP, int _Bani, int _XP, int _Scor)
	:Core(_Nume, _HP, _Bani, _XP, _Scor),Tip(_Tip)
{
	
}

Obiect::~Obiect()
{

}

bool operator == (const Obiect& obiect1, const Obiect& obiect2)
{
	bool egalitate = true;
	if (obiect1.getNume() != obiect2.getNume())
	{
		egalitate = false;
	}
	if (obiect1.getBani() != obiect2.getBani())
	{
		egalitate = false;
	}
	if (obiect1.getScor() != obiect2.getScor())
	{
		egalitate = false;
	}
	if (obiect1.getXP() != obiect2.getXP())
	{
		egalitate = false;
	}
	return egalitate;
}

void Obiect::Info()
{
	
	cout << "Tip: " << Tip << " Nume:" << Nume << " Pret:" << Bani << " Conditie: " <<
		HP << " XP: " << XP << " Scor: " << Scor;
}

string Obiect::getTip() const
{
	return Tip;
}

void Obiect::setTip(string& tip)
{
	Tip = tip;
}

int Obiect::getPutereAtac() const
{
	return 0;
}