#include "Core.h"
#include <iostream>
#include <cstring>

using namespace std;

Core::Core():Nume(""),HP(0),Bani(0),XP(0),Scor(0)
{
	//ctor
	
}

Core::Core(std::string _Nume, int _HP,int _Bani,int _XP,int _Scor) 
	:Nume(_Nume),HP(_HP),Bani(_Bani),XP(_XP),Scor(_Scor)
{
	
}

Core::~Core()
{
	//dtor
}

void Core::Info()
{
	cout << "Nume: " << Nume << " HP: " << HP << " Bani: " << Bani << " XP: " << XP << " Scor: " << Scor<<" ";
}

string Core::getNume()const
{
	return Nume;
}
int Core::getHp()const
{
	return HP;
}
int Core::getBani()const
{
	return Bani;
}
int Core::getXP()const
{
	return XP;
}
int Core::getScor()const
{
	return Scor;
}

void Core::setNume(string nume)
{
	Nume = nume;
}
void Core::setHp(int hp)
{
	HP = hp;
}
void Core::setBani(int bani)
{
	Bani = bani;
}
void Core::setXP(int xp)
{
	XP = xp;
}
void Core::setScor(int scor)
{
	Scor = scor;
}