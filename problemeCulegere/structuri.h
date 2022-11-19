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