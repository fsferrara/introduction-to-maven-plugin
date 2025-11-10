#ifndef CASELLO_H
#define CASELLO_H

#include "veicolo.h"
#include <iostream>

using namespace std;

struct Record;

struct Record {
	Veicolo * T;
	Record * next;
};

class Casello {

private:
	Record * lista;
	Record * prevlista;
	static const int max = 5;
	int nelem;
	void push(Veicolo * V);
public:
	Casello() {
		lista = 0;
		prevlista = 0;
		nelem = 0;
	};

	bool InserisciVeicolo(Veicolo * V);
	bool EstraiVeicolo();
	bool StampaCoda();
};
#endif
