#pragma once
#include "Eveniment.h"
#include<iostream>
using namespace std;

class Bilet
{
	int idBilet;
	string categorieBilet;
	float pretBilet;
	Eveniment evenimentBilet;
	
public:
	Bilet();
	Bilet(int idBilet, string categorieBilet, float pretBilet, Eveniment evenimentBilet);
	int getIdBilet();
	string getCategorieBilet();
	float getPretBilet();
	Eveniment getEvenimentBilet();
	friend ostream& operator<<(ostream&, const Bilet&);
	friend istream& operator>>(istream&, Bilet&);
	Bilet operator+(int adaousPret);
	Bilet operator++();
    float discount(int disc);
	float pret_max_bilet(float pMax);
};