#ifndef ORAS_H
#define ORAS_H
#include "Obiect.h"
#include <vector>
#include "Arma.h"
#include "ObiectSpecial.h"
#include "Jucator.h"

class Oras : public Core
{
public:
	Oras();
	Oras(string& numefisier,int stagiu);
	Oras(int _ID, string _Nume, int _nrIteme);
	~Oras();
	void Info();
	static void salvareFisier(const std::vector<Oras>& orase);
	void addArma(Arma* arma);
	void addArma(const Arma& arma);
	void addObiectSpecial(ObiectSpecial* special);
	void addObiectSpecial(const ObiectSpecial& special);
	void printObiecte();
	bool esteNumar(const string& str);

	int getDimInventar();
	Obiect* getObiect(int index);
private:
	int ID;
	int nrIteme;
	std::vector<Obiect*> obiecte;
	std::vector<Obiect*>::const_iterator obiecte_begin() const;
	std::vector<Obiect*>::const_iterator obiecte_end() const;
};

#endif // !ORAS_H