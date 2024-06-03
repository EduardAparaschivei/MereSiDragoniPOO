#ifndef OBIECT_H
#define OBIECT_H
#include <iostream>
#include <string>
#include "Core.h"

using namespace std;

class Obiect : public Core
{
public:
	Obiect();
	Obiect(string _Tip,std::string _Nume,int _HP,int _Bani,int _XP,int _Scor);
	virtual ~Obiect();
	void Info();
	string getTip() const;
	void setTip(string& tip);
	virtual int getPutereAtac()const;

protected:
	string Tip;
	
};

#endif // OBIECT_H

