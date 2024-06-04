#include "Oras.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Oras::Oras():Core("",0,0,0,0),ID(0),nrIteme(0)
{

}

Oras::Oras(int _ID,string _Nume, int _nrIteme):Core(_Nume,0,0,0,0),ID(_ID),nrIteme(_nrIteme)
{

}

Oras::Oras(string& numefisier,int stagiu)
{
	ifstream file(numefisier);
	string liniefisier;

	while (getline(file, liniefisier))
	{
		istringstream iss(liniefisier);
		string data;
		vector <string> Date;
		while (iss >> data)
		{
			Date.push_back(data);
		}
		if (esteNumar(Date[0]))
		{
			if (stoi(Date[0]) == stagiu)
			{
				ID = stoi(Date[0]);
				Nume = Date[1];
				nrIteme = stoi(Date[2]);
				for (int i = 0;i < nrIteme;i++)
				{
					getline(file, liniefisier);
					Date.clear();
					istringstream iss(liniefisier);
					while (iss >> data)
					{
						Date.push_back(data);
					}
					if (Date[0] == "arma")
					{
						Arma* arma = new Arma();
						arma->setTip(Date[0]);
						arma->setNume(Date[1]);
						arma->setPutereAtac(stoi(Date[2]));
						arma->setHp(stoi(Date[3]));
						arma->setBani(stoi(Date[4]));
						arma->setXP(stoi(Date[5]));
						arma->setScor(stoi(Date[6]));
						obiecte.push_back(arma);
					}
					else
					{
						ObiectSpecial* special = new ObiectSpecial();
						special->setTip(Date[0]);
						special->setNume(Date[1]);
						special->setHp(stoi(Date[2]));
						special->setBani(stoi(Date[3]));
						special->setXP(stoi(Date[4]));
						special->setScor(stoi(Date[5]));
						obiecte.push_back(special);
					}
				}
			}
		}
	}
}

Oras::~Oras()
{
	
}

void Oras::salvareFisier(const std::vector<Oras>& orase)
{
	ofstream file("Orase.txt");
	if (!file.is_open())
	{
		std::cerr << "Fisierul nu s-a deschis!" << "Orase.txt" << std::endl;
		return;
	}

	for (const auto& oras : orase)
	{
		file << oras.ID << " " << oras.Nume << " " << oras.nrIteme << "\n";
		for (const Obiect* obiect : oras.obiecte)
		{
			file << obiect->getTip() << " " << obiect->getNume() << " ";
			if (obiect->getTip() == "arma")
			{
				const Arma* arma = dynamic_cast<const Arma*>(obiect);
				if (arma != nullptr)
				{
					file << arma->getPutereAtac() << " ";
				}
			}
			file << obiect->getHp() << " " << obiect->getBani() << " "
				<< obiect->getXP() << " " << obiect->getScor() << "\n";
		}
	}
}

void Oras::addArma(Arma* arma)
{
	if (obiecte.empty())
	{
		obiecte = vector<Obiect*>();
	}
	obiecte.push_back(arma);
}
void Oras::addArma(const Arma& arma)
{
	Arma* armaPtr = new Arma(arma);
	addArma(armaPtr);
}
void Oras::addObiectSpecial(ObiectSpecial* special)
{
	if (obiecte.empty())
	{
		obiecte = vector<Obiect*>();
	}
	obiecte.push_back(special);
}
void Oras::addObiectSpecial(const ObiectSpecial& special)
{
	ObiectSpecial* specialPtr = new ObiectSpecial(special);
	addObiectSpecial(specialPtr);
}

int Oras::getDimInventar()
{
		return obiecte.size();
}

Obiect* Oras::getObiect(int index)
{
	if (index >= 0 && index < obiecte.size())
	{
		return obiecte[index];
	}
}


void Oras::Info()
{
	cout << "Oras: " << Nume << " ID: " << ID << endl;
}

void Oras::printObiecte()
{
	int i = 1;
	for (Obiect* obiect : obiecte)
	{
		cout <<i<<")";
		obiect->Info();
		cout << "\n";
		i = i + 1;
	}
}

bool Oras::esteNumar(const string& str)
{
	istringstream ss(str);
	int num;
	ss >> num;
	return !ss.fail() && ss.eof();
}