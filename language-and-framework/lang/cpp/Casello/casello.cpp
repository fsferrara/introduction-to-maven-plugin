#include "casello.h"

#include <iostream>

void Casello::push(Veicolo * V) {
	Record * p;
	p = new Record;
	p->T = V;
	lista = p;
	p->next = lista;
	prevlista = lista;
	nelem++;
}

bool Casello::InserisciVeicolo(Veicolo * V) {

	if (nelem > max)
		return false;
	else {
		if (lista == 0) {
			push(V);
			return true;
		} else {

			Record * p;
			p = new Record;
			p->T = V;

			prevlista->next = p;
			prevlista = p;
			p->next = lista;

			nelem++;
		}

	}
	return true;
}
bool Casello::EstraiVeicolo() {
	if (nelem == 0)
		return false;
	else {
		Record * temp = lista; //Elemento da cancellare
		Veicolo * E = lista->T; //Veicolo da cancellare
		lista = lista->next;
		prevlista->next = lista;
		temp->T->calcola_pedaggio();
		delete E;
		delete temp;
		nelem--;

		if (nelem == 0) {
			lista = 0;
			prevlista = 0;
		}
	}
	return true;

}
bool Casello::StampaCoda() {
	if (nelem == 0)
		return false;
	else {
		Record * p = lista;
		do {
			cout << "\n";
			p->T->stampa_dati();
			p = p->next;
		} while (p != lista);
	}
	return true;
}
