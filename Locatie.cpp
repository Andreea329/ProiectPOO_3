
#include"Locatie.h"

#include<iostream>
using namespace std;

Locatie::Locatie()
{
	this->nrRanduri = 0;
	this->LocuriRand = nullptr;
}

Locatie::Locatie(int nrRanduri, int* LocuriRand)
{
	this->nrRanduri = nrRanduri;
	this->LocuriRand = new int[nrRanduri];
	for (int i = 0; i < nrRanduri; i++)
	{
		this->LocuriRand[i] = LocuriRand[i];
	}

	int** matrLoc = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++)
	{
		matrLoc[i] = new int[LocuriRand[i]];   //o construieste
	}

	for (int i = 0; i < nrRanduri; i++)
	{
		for (int j = 0; j < LocuriRand[i]; j++)
		{                                               //o initializeaza
			matrLoc[i][j] = 0;
		}
	}

	

	
}

void Locatie::ocupare_loc(Locatie& l, int rand, int loc)
{
	int** matrice = new int* [l.getNrRanduri()];
	for (int i = 0; i < l.getNrRanduri(); i++)
	{
		matrice[i] = new int[l.getLocuriRand()[i]];   //o construieste
	}
	
	for (int i = 0; i < l.getNrRanduri(); i++)
	{
		for (int j = 0; j < l.getLocuriRand()[i]; j++)
		{                                               //o initializeaza
			matrice[i][j] = 0;
		}
	}
	//o ocupa
	
	matrice[rand-1][loc-1] = 1;
	
	//o afiseaza ocupata

	for (int i = 0; i < l.getNrRanduri(); i++)
	{
		for (int j = 0; j < l.getLocuriRand()[i]; j++)
		{
			cout << matrice[i][j] << " ";
		}
		cout << endl;
	}
	
}

int Locatie::getNrRanduri()
{
	return this->nrRanduri;
}

int* Locatie::getLocuriRand()
{
	int* copie = new int[this->nrRanduri];
	for (int i = 0; i < this->nrRanduri; i++)
	{
		copie[i] = this->LocuriRand[i];
	}
	return copie;
}



ostream& operator<<(ostream& out, const Locatie& l)
{
	out << "Numarul de randuri este: " << l.nrRanduri << endl;
	out << "Numarul de locuri pe rand este: " << endl;
	for (int i = 0; i < l.nrRanduri; i++)
	{
		out << l.LocuriRand[i] << " ";
	}
	
	cout << endl;

	//afiseaza matricea de locuri

	int** matrLoc = new int* [l.nrRanduri];
	for (int i = 0; i < l.nrRanduri; i++)
	{
		matrLoc[i] = new int[l.LocuriRand[i]];
	}

	for (int i = 0; i < l.nrRanduri; i++)
	{
		for (int j = 0; j < l.LocuriRand[i]; j++)
		{
			matrLoc[i][j] = 0;
		}
	}
	
	
	for (int i = 0; i < l.nrRanduri; i++)
	{
		for (int j = 0; j < l.LocuriRand[i]; j++)
		{
			out << matrLoc[i][j] << " ";
		}
		out << endl;
	}
	
	out << endl;
	return out;
}


istream& operator>>(istream& in, Locatie& l)
{
	cout << "Numarul de randuri este: ";
	in >> l.nrRanduri;
	cout << "Numarul de locuri pe rand este: ";
	l.LocuriRand = new int[l.nrRanduri];
	for (int i = 0; i < l.nrRanduri; i++)
	{
		in >> l.LocuriRand[i];
	}
	return in;
}

Locatie::Locatie(const Locatie& l)
{
	this->nrRanduri = l.nrRanduri;
	this->LocuriRand = new int[l.nrRanduri];
	for (int i = 0; i < l.nrRanduri; i++)
	{
		this->LocuriRand[i] = l.LocuriRand[i];
	}
}

Locatie::~Locatie()
{
	if (this->LocuriRand != nullptr)
	{
		delete[] this->LocuriRand;
		this->LocuriRand = nullptr;
	}
}

Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l)
	{
		this->nrRanduri = l.nrRanduri;
		if (this->LocuriRand != nullptr)
		{
			delete[] this->LocuriRand;
			this->LocuriRand = nullptr;
		}
		this->LocuriRand = new int[l.nrRanduri];
		for (int i = 0; i < l.nrRanduri; i++)
		{
			this->LocuriRand[i] = l.LocuriRand[i];
		}
	}
	return *this;
}

bool Locatie::operator!()
{
	return this->nrRanduri > 0;
}

int& Locatie::operator[](int index)
{
	if (index >= 0 && index < nrRanduri)
	{
		return LocuriRand[index];
	}
	throw exception("index invalid");
}