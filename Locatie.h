#pragma once

#include<iostream>
using namespace std;

class Locatie
{   
	int nrRanduri;
	int *LocuriRand;
	
		
public:
	Locatie();
	Locatie(int nrRanduri, int* LocuriRand);
	int  getNrRanduri();
	int* getLocuriRand();
	void ocupare_loc(Locatie& l,int rand, int loc);
	
	Locatie(const Locatie& l);
	~Locatie();
	Locatie& operator=(const Locatie& l);

	bool operator!();
	int& operator[](int index);
	

	friend ostream& operator<<(ostream&  , const Locatie&);
	friend istream& operator>>(istream& , Locatie& );
};
	


