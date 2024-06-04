#include "Jucator.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Jucator::Jucator() :Core("", 100, 0, 0, 0), Putere(0), Inteligenta(0), Agilitate(0), Stagiu(1)
{
	
}

Jucator::Jucator(std::string _Nume,int _HP,int _Bani,int _XP,int _Scor,int _Putere, int _Inteligenta, int _Agilitate,int _Stagiu)
	:Core(_Nume, _HP, _Bani, _XP, _Scor),
	Putere(_Putere), Inteligenta(_Inteligenta), Agilitate(_Agilitate),Stagiu(_Stagiu)
{

}

Jucator::Jucator(string& numefisier) : obiecte(new vector<Obiect*>())
{
	ifstream file(numefisier);
	if (file.is_open())
	{
		string linieFisier;
		if (getline(file, linieFisier))
		{
			istringstream iss(linieFisier);
			string data;
			vector <string> Date;
			while (iss >> data)
			{
				Date.push_back(data);
			}
			if (Date.size() != 9)
			{
				cout << "Format invalid!" << endl;
				return;
			}

			try {
				HP = stoi(Date[1]);
				Bani = stoi(Date[2]);
				XP = stoi(Date[3]);
				Scor = stoi(Date[4]);
				Putere = stoi(Date[5]);
				Inteligenta = stoi(Date[6]);
				Agilitate = stoi(Date[7]);
				Stagiu = stoi(Date[8]);
			}
			catch (exception& e)
			{
				cout << "Eroare convertire!" << endl;
				return;
			}
			Nume = Date[0];
			while (getline(file,linieFisier))
			{
				Date.clear();
				istringstream iss(linieFisier);
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
					obiecte->push_back(arma);
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
					obiecte->push_back(special);
				}
				

			}
		}
		else
		{
			cout << "Fisier Gol!" << endl;
		}
		file.close();
	}
	else
	{
		cout << "Nu s-a putut deschide fisierul" << endl;;
	}
}

Jucator& Jucator::operator=(const Jucator& jucator)
{
	if (this != &jucator)
	{
		Nume = jucator.Nume;HP = jucator.HP;Bani = jucator.Bani;
		XP = jucator.Bani;Scor = jucator.Scor;Putere = jucator.Putere;
		Inteligenta = jucator.Inteligenta;Agilitate = jucator.Agilitate;
		Stagiu = jucator.Stagiu;
		
		if (obiecte != nullptr)
		{
			obiecte->clear();
			delete obiecte;
		}
		obiecte = new vector<Obiect*>(*jucator.obiecte);
	}
	return *this;
}

Jucator::~Jucator()
{

}

void Jucator::Info()
{
	Core::Info();
	cout<<"Inteligenta: " << Inteligenta << " Putere: " << Putere << " Agilitate: " << Agilitate << " Stagiu: " << Stagiu << endl;
}

void Jucator::addArma(Arma* arma)
{
	if (obiecte == nullptr)
	{
		obiecte = new vector<Obiect*>();
	}
	obiecte->push_back(arma);
}
void Jucator::addArma(const Arma& arma)
{
	Arma* armaPtr = new Arma(arma);
	addArma(armaPtr);
}

void Jucator::addObiectSpecial(ObiectSpecial* special)
{
	if (obiecte == nullptr)
	{
		obiecte = new vector<Obiect*>();
	}
	obiecte->push_back(special);
}
void Jucator::addObiectSpecial(const ObiectSpecial& special)
{
	ObiectSpecial* specialPtr = new ObiectSpecial(special);
	addObiectSpecial(specialPtr);
}

void Jucator::printObiecte()
{
	int i = 1;
	for (Obiect* obiect : *obiecte)
	{
		cout<<i<<")"<< "Tip:" << obiect->getTip() << " Nume:" << obiect->getNume() << " Utilizari:" << obiect->getHp()<<" Pret:"<<obiect->getBani();
		if (obiect->getTip() == "arma")
		{
			cout << " Daune:" << obiect->getPutereAtac();
		}
		cout << "\n";
		i++;
	}
}

Obiect* Jucator::getObiect(int index)
{
	if (index >= 0 && index < obiecte->size())
	{
		return (*obiecte)[index];
	}
	return nullptr;
}

vector<Obiect*> Jucator::getObiecteCopie()const
{
	return *obiecte;
}

void Jucator::removeObiect(int index)
{
	if (index >= 0 && index < obiecte->size())
	{
		delete(*obiecte)[index];
		obiecte->erase(obiecte->begin() + (index));
	}
}

void Jucator::salvareFisier()
{
	ofstream file("Jucator.txt");
	if (file.is_open())
	{
		//Salvare calitati jucator
		file << Nume << " " << HP << " " << Bani << " " << XP << " " << Scor << " "
			<< Putere << " " << Inteligenta << " " << Agilitate << " " << Stagiu << "\n";
			//Salvare inventar jucator
			if (obiecte != nullptr && !obiecte->empty())
			{
				for (const Obiect* obiect : *obiecte)
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
		
		file.close();
	}
	else
	{
		cout << "Nu s-a putut deschide fisierul."<<endl;
	}
}

#pragma region Getteri/Setteri

void Jucator::upPutere()
{
	Putere++;
}
int Jucator::getPutere()
{
	return Putere;
}
void Jucator::setPutere()
{
	Putere = 0;
}
void Jucator::upInteligenta()
{
	Inteligenta++;
}
int Jucator::getInteligenta()
{
	return Inteligenta;
}
void Jucator::setInteligenta()
{
	Inteligenta = 0;
}
void Jucator::upAgilitate()
{
	Agilitate++;
}
int Jucator::getAgilitate()
{
	return Agilitate;
}
void Jucator::setAgilitate()
{
	Agilitate = 0;
}
int Jucator::getStagiu()
{
	return Stagiu;
}
void Jucator::upStagiu()
{
	Stagiu++;
}
int Jucator::getDimInventar()
{
	if (obiecte != nullptr)
	{
		return obiecte->size();
	}
	else
	{
		return 0;
	}
}

void Jucator::setStagiu(int newstage)
{
	Stagiu = newstage;
}

void Jucator::setLevel()
{
	Nivel = 1;
}

#pragma endregion
