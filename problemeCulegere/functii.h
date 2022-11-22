using namespace std;
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
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
	f.numitor = f1.numitor;
}

//todo functie ce determina cmmmdc

int cmmdc(int a, int b) {
	int r = 0;
	do {
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}

//todo functie ce simplifica o fractie

void simplificare(Fractie& f) {
	int divizor = cmmdc(f.numarator, f.numitor);
	f.numarator /= divizor;
	f.numitor /= divizor;
}

//todo functie ce citeste n nr complexe

void citireNrComplexe(NumarComplex nr[], int& n) {
	ifstream f("numereComplexe.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> nr[i].Re >> nr[i].Im;
	}
}

//todo functie ce returneaza modului unui numar complex

float modul(NumarComplex numar) {
	float suma = pow(numar.Re, 2) + pow(numar.Im, 2);
	return sqrt(suma);
}

//todo functie ce ordoneaza numerele in functie de modul

void ordonareCresc(NumarComplex nr[], int n) {
	bool flag = 0;
	do {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (modul(nr[i]) > modul(nr[i + 1])) {
				NumarComplex aux = nr[i];
				nr[i] = nr[i + 1];
				nr[i + 1] = aux;
				flag = 0;
			}
		}
	} while (flag == 0);
}

//todo functie ce citeste datele participantilor

void citireDateConcurs(Concurs c[], int& n) {
	ifstream f("concurs.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> c[i].nume >> c[i].liceu >> c[i].nota;
	}
}

//todo functie ce determina nota maxima

int notaMax(Concurs c[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (c[i].nota > max) {
			max = c[i].nota;
		}
	}
	return max;
}

//todo functie ce afiseaza numele elevilor cu nota maxima

void afisareEleviNotaMax(Concurs c[], int n) {
	for (int i = 0; i < n; i++) {
		if (c[i].nota == notaMax(c, n)) {
			cout << c[i].nume << endl;
		}
	}
}

//todo functie ce returneaza media generala a elevilor

float medieGenerala(Concurs c[], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += c[i].nota;
	}
	float medie = suma / n;
	return medie;
}


//todo functie ce citeste datele despre n studenti

void citireDateStudenti(Student s[], int& n) {
	ifstream f("studenti.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> s[i].cod;
		f >> s[i].grupa;
		f >> s[i].nume;
		f >> s[i].sex;
		f >> s[i].numar_examene;
		for (int j = 0; j < s[i].numar_examene; j++) {
			f >> s[i].note[j];
		}
	}
}

//todo functie ce returneaza nr de examene nepromovate

int exameneNepromovate(Student s) {
	int ct = 0;
	for (int i = 0; i < s.numar_examene; i++) {
		if (s.note[i] < 5) {
			ct++;
		}
	}
	return ct;
}

//todo functie ce afiseaza studentii care au examene nepromovate, respectiv nr de examene nepromovate 

void afisareStudenti(Student s[], int n) {
	for (int i = 0; i < n; i++) {
		if (exameneNepromovate(s[i]) > 0) {
			cout << s[i].nume << ' ' << exameneNepromovate(s[i]) << endl;
		}
	}
}

//todo functie ce citeste datele elevilor unei scoli

void citireDateElevi(Scoala s[], int& n) {
	ifstream f("elevi.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> s[i].nume;
		f >> s[i].clasa;
		f >> s[i].numar_note;
		for (int j = 0; j < s[i].numar_note; j++) {
			f >> s[i].note[j];
		}
	}
}


//todo functie ce returneaza media unui elev

float medieElev(Scoala s) {
	float suma = 0;
	for (int i = 0; i < s.numar_note; i++) {
		suma += s.note[i];
	}
	return suma / s.numar_note;
}

//todo functie ce ordoneaza elevii descrescator dupa medie

void ordonareElevi(Scoala s[], int n) {
	bool flag = 0;
	do {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (medieElev(s[i]) < medieElev(s[i + 1])) {
				Scoala aux;
				aux = s[i];
				s[i] = s[i + 1];
				s[i + 1] = aux;
				flag = 0;
			}
		}
	} while (flag == 0);
}

//todo functie ce verifica daca un elev are toate notele cel putin 7

bool celPutin7(Scoala s) {
	for (int i = 0; i < s.numar_note; i++) {
		if (s.note[i] < 7) {
			return false;
		}
	}
	return true;
}

//todo functie ce returneaza nr de elevi ai unei clase care au toate notele cel putin 7

int numarEleviClasa(Scoala s[], int n, int clasa) {
	int ct = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].clasa == clasa) {
			if (celPutin7(s[i])) {
				ct++;
			}
		}
	}
	return ct;
}

//todo functie ce reutrneaza clasa cu cei mai multi elevi care au toate notele cel putin 7\

int clasa(Scoala s[], int n) {
	int cls = 0, max = 0;
	for (int i = 0; i < n; i++) {
		if (numarEleviClasa(s, n, s[i].clasa)>max) {
			max = numarEleviClasa(s, n, s[i].clasa);
			cls = s[i].clasa;
		}
	}
	return cls;
}

//todo functie ce descompune un numar in factori primi

void descFactoriPrimi(Descompunere& n) {
	n.factor_prim = 2;
	do {
		n.exponent = 0;
		
		while (n.valoare % n.factor_prim == 0) {
			n.valoare /= n.factor_prim;
			n.exponent++;
		}
		if (n.exponent) {
			cout << '(' << n.factor_prim << ',' << n.exponent << ") ";
		}
		n.factor_prim++;
	} while (n.valoare > 1);
}

//todo functie ce citeste elementele vectorului

void citireVector(Vector a[], int& n) {
	ifstream f("vector.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> a[i].x;
		f >> a[i].y;
	}
}

//todo functie ce ordoneaza descrescator vectorul in functie de campul x

void ordonareDescrescX(Vector a[], int n) {
	bool flag = 0;
	do {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i].x < a[i + 1].x) {
				Vector aux;
				aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				flag = 0;
			}
			else {
				if (a[i].x == a[i + 1].x) {
					if (a[i].y < a[i + 1].y) {
						Vector aux;
						aux = a[i];
						a[i] = a[i + 1];
						a[i + 1] = aux;
						flag = 0;
					}
				}
			}
		}
	} while (flag == 0);
}


//todo functie ce ordoneaza crescator componentele care au campul x impar

void ordonareCrescX(Vector a[], int n) {
	bool flag = 0;
	do {
		flag = 1;
		for (int i = 0; i < n; i++) {
			if (a[i].x % 2 == 1) {
				int j = i + 1;
				while (a[j].x % 2 == 0) {
					j++;
				}
				if (a[i].y > a[j].y) {
					Vector aux;
					aux = a[i];
					a[i] = a[j];
					a[j] = aux;
					flag = 0;
				}
			}
		}

	} while (flag == 0);
}

//todo functie ce returneaza suma campurilor x

int sumaCampuri(Vector a[], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += a[i].x;
	}
	return suma;
}

//tood functie ce returneaza produsul campurilor pare y

int produsCampuri(Vector a[], int n) {
	int produs = 1;
	for (int i = 0; i < n; i++) {
		if (a[i].y % 2 == 0) {
			produs *= a[i].y;
		}
	}
	return produs;
}

//todo functie ce citeste zodiile

void citireZodii(Zodie z[]) {
	ifstream f("zodii.txt");
	for (int i = 0; i < 12; i++) {
		f >> z[i].zodie;
		f >> z[i].zi_st;
		f >> z[i].lunaStart;
		f >> z[i].zi_sf;
		f >> z[i].lunaSfarsit;
	}
}

//todo functie ce returneaza zodia coresp datei introduse

void zodie(Zodie z[], char data[]) {
	/*int i = 0;
	char luna[20];
	char* p = strtok(data, " ");
	while (p != NULL) {
		strcpy(luna, p);
		p = strtok(NULL, " ");
	}
	while (strcmp(z[i].lunaSfarsit,luna) != 0) {
		i++;
	}
	if (atoi(data) > z[i].zi_sf) {
		cout << z[i + 1].zodie;
	}
	else {
		cout << z[i].zodie;
	}*/
}