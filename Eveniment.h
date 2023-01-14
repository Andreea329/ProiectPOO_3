#pragma once
#include"Locatie.h"
#include<iostream>
using namespace std;

class Eveniment
{ 
    char* categorieEveniment;
    string ziEveniment;
    string oraEveniment;
    string anEveniment;
    string lunaEveniment;
	const int durataEveniment;
	Locatie locatieEveniment;
    static int nrEvenimente2022;
    
public:
    Eveniment();
	Eveniment(const char* categorieEveniment, string ziEveniment, string oraEveniment, string anEveniment, string lunaEveniment,int durataEveniment, Locatie locatieEveniment);
	Eveniment(const Eveniment& e);
	~Eveniment();
	Eveniment& operator=(const Eveniment& e);
	string getZiEveniment();
	void setZiEveniment(string ziEveniment);
	string getOraEveniment();
	void setOraEveniment(string oraEveniment);
	string getAnEveniment();
	Locatie getLocatieEveniment();
	void setLocatieEveniment(Locatie locatieEveniment);
	void setAnEveniment(string anEveniment);
    int getNrEvenimente();
    static void setNrEvenimente2022(int nr);
	friend ostream& operator<<(ostream&, const Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	static void NrPersoanePrezenteEveniment(int nrPersoane);
	string locatieInfo(string oras, string strada);
	string data_eveniment();
	explicit operator string();
	int operator()();
	
	
    
};

class EvenimentCaritabil: public Eveniment
{
	string cauza;
	double sumaDonata;
public:
	EvenimentCaritabil() :Eveniment()
	{
		this->cauza = " ";
		this->sumaDonata = 0;
	}
	EvenimentCaritabil(const char* categorieEveniment, string ziEveniment, string oraEveniment, string anEveniment, string lunaEveniment,int durataEveniment,Locatie locatieEveniment, string cauza, double sumaDonata) :Eveniment(categorieEveniment, ziEveniment, oraEveniment, anEveniment, lunaEveniment,durataEveniment,locatieEveniment)
	{
		this->cauza = cauza;
		this->sumaDonata = sumaDonata;
	}
	
	string getCauza();
	
	double getSumaDonata();
	
	friend ostream& operator<<(ostream&, const EvenimentCaritabil&);
	
};

 
