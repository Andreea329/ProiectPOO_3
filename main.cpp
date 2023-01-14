#include "Locatie.h"
#include"Eveniment.h"
#include "Bilet.h"
#include<iostream>
using namespace std;

int main()
{

	Locatie l(4, new int[4] {6, 9, 12, 15});
	cout << l;
	l.ocupare_loc(l, 2, 3);
	cout << endl;
	l.ocupare_loc(l, 1, 2);
	cout << endl;
	
	Locatie lCopie = l;
	//cout << lCopie;
	//lCopie.ocupare_loc(lCopie, 1, 4);
	
	//Locatie l2;
	//cin >> l2;
	cout << l[0]<<endl; //apelarea operatorului index
	
	Eveniment e("Concert", "12", "12:00", "2022", "12",2, l);
	Eveniment ev;
	ev.setZiEveniment("15");
	cout << ev.getZiEveniment() << endl;
	
	cout << e;
	//Eveniment e2;
	//cin >> e2;
	
	Eveniment e3("Piesa de teatru", "15", "19:40", "2022", "3", 3, l);
	cout << e3;
	

	
	//Eveniment::setNrEvenimente2022(120);
	//cout << ev.getNrEvenimente();
   //Eveniment::NrPersoanePrezenteEveniment(100);

	
	//cout << e.locatieInfo("Bucuresti", "Stirbei Voda");
	//cout << e.data_eveniment()<<endl;
	
	//cout << (string)e<<endl;
	//cout << e.operator()()<<endl;

	EvenimentCaritabil ec((const char*)"balet", "10", "20:00", "2022", "5",3, l, "adapost animale", 10000);
	
	cout << ec<<endl;

	Bilet b(1, "VIP", 300, e3);
	cout << b<<endl;
	//cout << b + 50;
	//cout << ++b;
	//cout << b.discount(10);
	//cout << b.pret_max_bilet(100);
}

//din calsa eveniment derivez tipul de eveniment
//voi deriva clasa eveniment in eveniment caritabil si am in plus campul sumaPreconizataDonatie