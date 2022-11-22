#include "functii.h"
#include "structuri.h"
#pragma once


//80:

void sol1() {
	Candidat c[4];
	totalVoturi(c);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			cout << c[i].oras[j].voturi << endl;
		}
		cout << c[i].total_voturi << endl;
	}
}


//82: sa se stabileasca varsta in ani

void sol2() {
	Data nastere, astazi;
	citireDate(nastere, astazi);
	//cout << astazi.zi << ' ' << astazi.luna << ' ' << astazi.an << endl;
	//cout << nastere.zi << ' ' << nastere.luna << ' ' << nastere.an << endl;
	cout << varsta(nastere,astazi);
}


//83: forma ireductibila a p+q (fractii)

void sol3() {
	Fractie p, q, suma;
	citireFractii(p, q);
	//cout << p.numarator << ' ' << p.numitor << endl;
	//cout << q.numarator << ' ' << q.numitor << endl;
	adunareFractii(suma, p, q);
	simplificare(suma);
	cout << suma.numarator << ' ' << suma.numitor;
}


//84: sa se afiseze ordonat crescator sirul modulelor celor n nr complexe

void sol4() {
	NumarComplex nr[100];
	int n;
	citireNrComplexe(nr, n);
	/*for (int i = 0; i < n; i++) {
		cout << nr[i].Re << ' ' << nr[i].Im << endl;
	}*/
	//cout << modul(nr[0]);
	ordonareCresc(nr, n);
	for (int i = 0; i < n; i++) {
		cout << modul(nr[i]) << endl;
	}
}


//85: sa se afiseze numele elevilor cu cea mai mare nota si media generala a concurentilor

void sol5() {
	Concurs c[20];
	int n;
	citireDateConcurs(c, n);
	//cout << notaMax(c, n);
	afisareEleviNotaMax(c, n);
	cout << medieGenerala(c, n);
}


//89: sa se afiseze studentii care au examene nepromovate, respectiv nr de examene nepromovate 

void sol6() {
	Student s[20];
	int n;
	citireDateStudenti(s, n);
	afisareStudenti(s, n);
}


//90: sa se ordoneze elevii descrescator dupa medii,
//apoi sa se stabileasca clasa cu cei mai multi elevi care au toate notele cel putin 7

void sol7() {
	Scoala s[20];
	int n;
	citireDateElevi(s, n);
	//cout << medieElev(s[3]);
	ordonareElevi(s, n);
	for (int i = 0; i < n; i++) {
		cout << s[i].nume << ' ' << medieElev(s[i]) << endl;
	}
	//cout << celPutin7(s[1]);
	cout << clasa(s, n);
}


//91: sa se descompuna un nr in factori primi

void sol8() {
	Descompunere numar;
	numar.valoare = 1960;
	descFactoriPrimi(numar);
}


//93:
//a) sa se ordoneze descresc vectorul in functie ce campul x (in caz de egalitate, in functie ce y)
//b) sa se ordoneze cresc componentele lui a care au campul x impar (celelalte ramas nemodificate)
//c) sa se calculeze suma campurilor x si produsul campurilor y pare


void sol9() {
	Vector a[100];
	int n;
	citireVector(a, n);
	cout << "a)" << endl;
	ordonareDescrescX(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i].x << ' ' << a[i].y << endl;
	}
	cout << endl << "b)" << endl;
	ordonareCrescX(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i].x << ' ' << a[i].y << endl;
	}
	cout << endl << "c) ";
	cout << sumaCampuri(a, n) << ' ' << produsCampuri(a, n) << endl;
}


//94: sa se returneze zodia corespunzatoare zilei si lunii introduse

void sol10() {
	Zodie zodii[12];
	citireZodii(zodii);
	
	char data[100];


	cout << "Introduceti ziua si luna" << endl;

	cin.getline(data, 100);

	cout << "Sunteti zodia ";
	zodie(zodii, data);

	//cout << data << endl;
	/*for (int i = 0; i < 12; i++) {
		cout << zodii[i].zodie << " " << zodii[i].zi_sf << endl;
	}*/

}