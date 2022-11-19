using namespace std;
#include <iostream>
#include <fstream>
#include "structuri.h"
#pragma once


//todo functie ce determina voturile totale ale candidatilor

void totalVoturi(Candidat c[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			c[i].total_voturi = c[i].total_voturi + c[i].oras[j].voturi;
		}
	}
}

//todo functie care citeste 2 date

void citireDate(Data& nastere, Data& azi) {
	ifstream f("date.txt");
	f >> nastere.zi >> nastere.luna >> nastere.an;
	f >> azi.zi >> azi.luna >> azi.an;
}

//todo functie ce returneaza varsta unei persoane

int varsta(Data nastere, Data azi) {
	int ani = 0;
	if (azi.luna < nastere.luna) {
		ani = azi.an - nastere.an - 1;
	}
	else {
		if (azi.luna == nastere.luna && azi.zi < nastere.zi) {
			ani = azi.an - nastere.an - 1;
		}
		else {
			ani = azi.an - nastere.an;
		}
	}	
	return ani;
}

//todo functie ce citeste 2 fractii

void citireFractii(Fractie& f1, Fractie& f2) {
	ifstream f("fractii.txt");
	f >> f1.numarator >> f1.numitor;
	f >> f2.numarator >> f2.numitor;
}

//todo functie ce aduna 2 fractii

void adunareFractii(Fractie& f, Fractie f1, Fractie f2) {
	if (f1.numitor != f2.numitor) {
		f1.numarator *= f2.numitor;
		f2.numarator *= f1.numitor;
		int aux = f1.numitor;
		f1.numitor *= f2.numitor;
		f2.numitor *= aux;
	}
	f.numarator = f1.numarator + f2.numarator;
	f.numitor = f1.numitor + f2.numitor;
}