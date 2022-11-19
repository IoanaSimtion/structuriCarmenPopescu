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
	cout << suma.numarator << ' ' << suma.numitor;
}