#ifndef ARMA_H
#define ARMA_H
#include "Obiect.h"
#include "Core.h"
class Arma : public Obiect
{
public:
	Arma();
	Arma(string _Tip, string _Nume, int _PutereAtac, int _HP, int _Bani, int _XP, int _Scor);
	Arma(string& numefisier);
	virtual ~Arma();
	void Info();
	void setPutereAtac(int putere);
	int getPutereAtac()const override;

private:
	int PutereAtac;
};

#endif // ARMA_H

