#include <iostream>
#include <stdio.h>
#include "Core.h"
#include "Jucator.h"
#include "Obiect.h"
#include "Dragon.h"
#include "Arma.h"
#include "ObiectSpecial.h"
#include "Oras.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include "GamePlay.h"

using namespace std;

string numeFisier = "Jucator.txt";
string numeFisierDragoni = "Dragoni.txt";
string numeFisierOras = "Orase.txt";
Jucator jucator;
Oras oras;
Arma* arma = nullptr;
Dragon dragon;
GamePlay Joc;

int main()
{
	

	//jucator.addArma(arma1);
	//jucator.addArma(arma2
	Joc.MeniuPrincipal(jucator,arma,numeFisier,numeFisierDragoni,oras,numeFisierOras);			
	return 0;

}

