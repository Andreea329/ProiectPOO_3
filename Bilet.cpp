#include"Bilet.h"
#include"Eveniment.h"
#include"Locatie.h"
#include<iostream>
using namespace std;

Bilet::Bilet() :idBilet(0)
{    
	this->categorieBilet = "";
	this->pretBilet = 0;
	this->evenimentBilet = Eveniment();
}
Bilet::Bilet(int idBilet, string categorieBilet, float pretBilet, Eveniment evenimentBilet) :idBilet(idBilet)
{
	this->categorieBilet = categorieBilet;
	this->pretBilet = pretBilet;
	this->evenimentBilet = evenimentBilet;
}

int Bilet::getIdBilet()
{
	return idBilet;
}

string Bilet::getCategorieBilet()
{
	return categorieBilet;
}

float Bilet::getPretBilet()
{
	return pretBilet;
}

Eveniment Bilet::getEvenimentBilet()
{
	return evenimentBilet;
}

ostream& operator<<(ostream& out, const Bilet& b)
{
	out << "Id-up biletului este : " << b.idBilet << endl;
	out << "Categoria biletului este : " << b.categorieBilet << endl;
	out << "Pretul biletului este: " << b.pretBilet << endl;
	out << "Evenimentul biletului este : "<<endl << b.evenimentBilet << endl;
	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Introduceti id-ul biletului: ";
	in >> b.idBilet;
	cout << "Introduceti categoria biletului: ";
	in >> b.categorieBilet;
	cout << "Introduceti pretul biletului: ";
	in >> b.pretBilet;
	cout << "Introduceti evenimentul biletului: ";
	in >> b.evenimentBilet;
	return in;
}

Bilet Bilet::operator+(int adaousPret)
{
	Bilet copie = *this;
	copie.pretBilet += adaousPret;
	return copie;
}

Bilet Bilet::operator++()
{
	this->pretBilet++;
	return *this;
}

float Bilet::discount(int disc)
{
	if (disc > 0 && pretBilet > 150)
	{
		return pretBilet = pretBilet - ((pretBilet * disc) / 100);
	}
	else
	{
		return pretBilet;
	}
}
float Bilet::pret_max_bilet(float pMax)
{
	int max;
	if (pretBilet > pMax)
	{
		max = pretBilet;
	}
	else
	{
		max = pMax;
	}
	return max;
}