#ifndef OBIECTSPECIAL_H
#define OBIECTSPECIAL_H
#include "Obiect.h"

class ObiectSpecial : public Obiect
{
public:
	ObiectSpecial();
	ObiectSpecial(string _Tip, string _Nume,int _HP, int _Bani, int _XP, int _Scor);
	virtual ~ObiectSpecial();
	void Info();
	void Utilizare(string tip);

};

#endif // OBIECTSPECIAL_H