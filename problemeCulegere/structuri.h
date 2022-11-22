using namespace std;
#include <iostream>
#pragma once

struct Cartiere {
	char denumire_cartier[20];
	int voturi;
};

struct Candidat {
	Cartiere oras[20];
	int total_voturi;
};


struct Data {
	int zi, luna, an;
};


struct Fractie {
	int numarator;
	int numitor;
};



struct NumarComplex {
	int Re;
	int Im;
};


struct Concurs {
	char nume[20], liceu[20];
	int nota;
};




struct Student {
	int cod, grupa;
	char nume[20], sex[20];
	int numar_examene;
	int note[10];
 };



struct Scoala {
	char nume[20];
	int clasa, numar_note;
	int note[10];
};



struct Descompunere {
	int valoare;
	int factor_prim;
	int exponent;
};


struct Vector {
	int x;
	int y;
};



struct Zodie {
	char zodie[20];
	int zi_st;
	char lunaStart[20];
	int zi_sf;
	char lunaSfarsit[20];
};