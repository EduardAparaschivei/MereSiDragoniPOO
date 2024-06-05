#ifndef  GAMEPLAY_H
#define GAMEPLAY_H
#include "Jucator.h"
#include "Dragon.h"
#include "Oras.h"

class GamePlay
{
public:
	GamePlay();
	void MeniuPrincipal(Jucator& jucator, Arma*& arma, string numeFisier, string numeFisier2,Oras& oras, string numeFisierOrase);
	void Exploreaza(Jucator& jucator, Arma*& arma, string numeFisier, string numeFisier2,Oras& oras, string numeFisierOrase);
	void StagiuNeutru(Jucator& jucator, Arma*& arma, string numeFisier, string numeFisier2,Oras &oras, string numeFisierOrase);
	void Lupta(Jucator& jucator, Arma*& arma, string numeFisier, string numeFisier2);

	void EchipeazaArma(Jucator& jucator, Arma*& arma, string numeFisier);

	void DegradareItem(Jucator& jucator, Arma*& arma);
	void PreiaJucator(Jucator& jucator, string numeFisier);

	void TransferStatusuri(Jucator& jucator, Dragon& dragon);
	void TransferStatusuri(Jucator& jucator, Obiect& arma);
	void TransferStatusuri(Jucator& jucator, Obiect* special);

	void ViziteazaMagazin(Jucator& jucator, Oras& oras, string numeFisierOrase);

	void CreazaJucator(Jucator& jucator);

	void LevelUP(Jucator& jucator);

	friend void setPuncte(Jucator& jucator, Obiect& obiect);
	
	void VictoryScreen(Jucator& jucator);

private:
	int obtineeveniment();
	void EndScrenn();
	
	bool VerificareNumar(const string& numar);
	int sTOint(const string& str);
	int numarPtInv();
};

#endif // GAMEPLAY_H