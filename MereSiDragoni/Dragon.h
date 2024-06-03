#ifndef DRAGON_H
#define DRAGON_H

#include <iostream>
#include "Core.h"

using namespace std;

class Dragon : public Core
{
public:
	Dragon();
	Dragon(string _Nume, int _HP, int _Bani, int _XP, int _Scor,int _ID,int _Dificultate,int _Daune);
	Dragon(string& numefiser,int stagiu);
	Dragon& operator=(const Dragon& dragon);
	virtual ~Dragon();
	void Info();
	int getDificultate();
	int getDaune();

private:
	int ID, Dificultate, Daune;
};

#endif // DRAGON_H

