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

void Obiect::Info()
{
	Core::Info();
	cout << "Tip: " << Tip << endl;
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