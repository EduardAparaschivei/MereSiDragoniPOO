#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <string>
using namespace std;
//Baza tuturor claselor


class Core
{
public:
	Core();
	Core(std::string _Nume, int _HP , int _Bani , int _XP , int _Scor);
	virtual ~Core();
	void Info();
	string getNume()const;
	int getHp()const;
	int getBani()const;
	int getXP()const;
	int getScor()const;
	void setNume(string nume);
	void setHp(int hp);
	void setBani(int bani);
	void setXP(int xp);
	void setScor(int scor);

protected:
	//Fiecare clasa va folosi aceste date intr-un fel sau altul
	std::string Nume;
	int HP, Bani, XP, Scor;

};

#endif // CORE_H

