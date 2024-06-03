#ifndef  GAMEPLAY_H
#define GAMEPLAY_H
#include "Jucator.h"

class GamePlay
{
public:
	GamePlay();
	void CreazaJucator(Jucator& jucator);
	void Exploreaza();

private:
	int obtineeveniment();

};

#endif // GAMEPLAY_H