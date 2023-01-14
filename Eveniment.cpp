#include"Eveniment.h"
#include"Locatie.h"
#include<iostream>
using namespace std;

Eveniment::Eveniment():durataEveniment(2)
{
	this->categorieEveniment = nullptr;
	this->ziEveniment = "";
	this->oraEveniment = "";
	this->anEveniment = "";
	this->lunaEveniment = "";
	this->locatieEveniment = Locatie();
}
Eveniment::Eveniment(const char* categorieEveniment, string ziEveniment, string oraEveniment, string anEveniment, string lunaEveniment,int durataEveniment,Locatie locatieEveniment):durataEveniment(durataEveniment)
{
	this->categorieEveniment = new char[strlen(categorieEveniment) + 1];
	strcpy_s(this->categorieEveniment, strlen(categorieEveniment) + 1, categorieEveniment);
	this->ziEveniment = ziEveniment;
	this->oraEveniment = oraEveniment;
	this->anEveniment = anEveniment;
	this->lunaEveniment = lunaEveniment;
	this->locatieEveniment = locatieEveniment;
}
Eveniment::Eveniment(const Eveniment& e):durataEveniment(e.durataEveniment)
{
	this->categorieEveniment = new char[strlen(e.categorieEveniment) + 1];
	strcpy_s(this->categorieEveniment, strlen(e.categorieEveniment) + 1, e.categorieEveniment);
	this->ziEveniment = e.ziEveniment;
	this->oraEveniment = e.oraEveniment;
	this->anEveniment = e.anEveniment;
	this->lunaEveniment = e.lunaEveniment;
	this->locatieEveniment = e.locatieEveniment;
}
Eveniment::~Eveniment()
{
	if (this->categorieEveniment != nullptr)
	{
		delete[] this->categorieEveniment;
		this->categorieEveniment = nullptr;
	}
}
Eveniment& Eveniment::operator=(const Eveniment& e)
{    
	if (this != &e)
	{
		if (this->categorieEveniment != nullptr)
		{
			delete[] this->categorieEveniment;
			this->categorieEveniment = nullptr;
		}
		this->categorieEveniment = new char[strlen(e.categorieEveniment) + 1];
		strcpy_s(this->categorieEveniment, strlen(e.categorieEveniment) + 1, e.categorieEveniment);
		this->ziEveniment = e.ziEveniment;
		this->oraEveniment = e.oraEveniment;
		this->anEveniment = e.anEveniment;
		this->lunaEveniment = e.lunaEveniment;
		this->locatieEveniment = e.locatieEveniment;
	}
	return *this;
}

string Eveniment::getZiEveniment()
{
	return ziEveniment;
}
void Eveniment::setZiEveniment(string ziEveniment)
{
	this->ziEveniment = ziEveniment;
}
string Eveniment::getOraEveniment()
{
	return oraEveniment;
}
void Eveniment::setOraEveniment(string oraEveniment)
{
	this->oraEveniment = oraEveniment;
}
string Eveniment::getAnEveniment()
{
	return anEveniment;
}
void Eveniment::setAnEveniment(string anEveniment)
{
	this->anEveniment = anEveniment;
}
Locatie Eveniment::getLocatieEveniment()
{
	return locatieEveniment;
}
void Eveniment::setLocatieEveniment(Locatie locatieEveniment)
{
	this->locatieEveniment = locatieEveniment;
}

int Eveniment::nrEvenimente2022 = 20;
int Eveniment::getNrEvenimente()
{
	return nrEvenimente2022;
}

void Eveniment::setNrEvenimente2022(int nr)
{
	Eveniment::nrEvenimente2022 = nr;
}

ostream& operator<<(ostream& out, const Eveniment& e)
{
	out << "Categoria evenimentului este : " << e.categorieEveniment << endl;
	out << "Ziua evenimentului este : " <<e.ziEveniment << endl;
	out << "Ora evenimentului este : " << e.oraEveniment << endl;
	out << "Anul evenimentului este : " << e.anEveniment << endl;
	out << "Luna evenimentului este : " << e.lunaEveniment << endl;
	out << "Durata evenimentului este : " << e.durataEveniment << endl;
	out << "Structura locatiei evenimentului este : "<<endl << e.locatieEveniment << endl;
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Sa se introduca categoria evenimentului : ";
	string buffer;
	in >> buffer;
	if (e.categorieEveniment != nullptr)
	{
		delete[] e.categorieEveniment;
	}
	e.categorieEveniment = new char[buffer.length() + 1];
	strcpy_s(e.categorieEveniment, buffer.length() + 1, buffer.c_str());
	cout << "Sa se introduca ziua evenimentului : ";
	in >> e.ziEveniment;
	cout << "Sa se introduca ora evenimentului : ";
	in >> e.oraEveniment;
	cout << "Sa se introduca anul evenimentului : ";
	in >> e.anEveniment;
	cout << "Sa se introduca luna evenimentului : ";
	in >> e.lunaEveniment;
	
	cout << "Introduceti structura locatiei evenimentului : ";
	in >> e.locatieEveniment;
	return in;
}

void Eveniment::NrPersoanePrezenteEveniment(int nrPersoane)
{
	if (nrPersoane > 200)
	{
		cout << "Evenimentul este  mare" << endl;
	}
	else
	{
		cout << "Evenimentul este  mic" << endl;
	}	
}

string Eveniment::locatieInfo(string oras, string strada)
{
	string locatie_info;
	locatie_info = oras + " " + strada;
	return locatie_info;

}

string Eveniment::data_eveniment()
{
	string data;
	data = ziEveniment + "-" + lunaEveniment + "-" + anEveniment;
	return data;
}
Eveniment::  operator string()
{
	return lunaEveniment;
}
int Eveniment::operator()()
{
	if (categorieEveniment != nullptr)
	{
		return strlen(categorieEveniment);
	}
	else
	{
		return 0;
	}
}

string EvenimentCaritabil::getCauza()
{
	return cauza;
}


double EvenimentCaritabil::getSumaDonata()
{
	return sumaDonata;
}

ostream& operator<<(ostream& out, const EvenimentCaritabil& ec)
{  
	
	out << (Eveniment)ec;
	out << "Cauza: " << ec.cauza << endl;
	out << "Suma donata: " << ec.sumaDonata << endl;
	return out;
}