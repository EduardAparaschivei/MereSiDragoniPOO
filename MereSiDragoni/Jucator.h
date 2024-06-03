#ifndef JUCATOR_H
#define JUCATOR_H
#include <iostream>
#include <string>
#include <vector>
#include "Core.h"
#include "Obiect.h"
#include "Arma.h"
#include "ObiectSpecial.h"


using namespace std;

class Jucator : public Core
{
public:
	Jucator();
	Jucator(std::string _Nume,int _HP,int _Bani,int _XP,int _Scor,int _Putere,int _Inteligenta,int _Agilitate,int _Stagiu);
	Jucator(string& numefisier);
	Jucator& operator=(const Jucator& jucator);
	virtual ~Jucator();
	void Info();
	void addArma(Arma* arma);
	void addArma(const Arma& arma);
	void addObiectSpecial(ObiectSpecial* special);
	void addObiectSpecial(const ObiectSpecial& special);
	void printObiecte();
	void salvareFisier();
	//getteri
	int getStagiu();
	//setteri
	void upPutere();
	void upInteligenta();
	void upAgilitate();
	void upStagiu();
	int getPutere();
	int getInteligenta();
	int getAgilitate();
	int getDimInventar();


private:
	int Putere, Inteligenta, Agilitate,Nivel,Stagiu;
	std::vector<Obiect*> *obiecte;

};

#endif // JUCATOR_H

