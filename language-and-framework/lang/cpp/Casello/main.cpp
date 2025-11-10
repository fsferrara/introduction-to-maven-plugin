#include <cstdlib>
#include <iostream>
#include "veicolo.h"
#include "casello.h"

using namespace std;

void presenta_menu(int&);
void inserimento(Veicolo *, Casello &);

int main(int argc, char *argv[]) {
	Casello c;
	Veicolo * V;
	int scelta;
	int esci = 0;
	bool b;
	do {
		presenta_menu(scelta);
		switch (scelta) {
			case 1: {
				inserimento(V, c);
				break;
			}
			case 2: {
				if (b = c.EstraiVeicolo())
					cout << "\n Estrazione riuscita";
				else
					cout << "\ coda vuota";
				break;
			}
			case 3: {
				if (b = c.StampaCoda())
					cout << "\n Stampa riuscita";
				else
					cout << "\n coda vuota";
				break;
			}
			case 4: {
				esci = 1;
				break;
			}
		}
	} while (!esci);

	cout << "\ GRAZIE E ARRIVEDERCI \n\n";
	return EXIT_SUCCESS;
}

void presenta_menu(int& scelta) {
	do {
		cout << "\n ***Programma che simula la coda ad un casello***";
		cout << "\n 1) Inserisci veicolo. ";
		cout << "\n 2) Estrai veicolo. ";
		cout << "\n 3) Stampa coda. ";
		cout << "\n 4) Fine";
		cout << "\n  Fai una scelta->";
		cin >> scelta;
	} while ((scelta < 1) || (scelta > 4));

}

void inserimento(Veicolo * V, Casello & c) {
	int opz;
	bool a;
	do {
		cout << "\n ***Inserimento veicolo";
		cout << "\n Scrivi 1 per mezzo leggero,2 per mezzo pesante";
		cout << "\n Scegli:";
		cin >> opz;
	} while ((opz < 1) || (opz > 2));
	switch (opz) {
	case 1: {
		V = new MezzoLeggero;
		cin.ignore();
		V->inserisci_dati();
		if (a = c.InserisciVeicolo(V))
			cout << "\n inserimento riuscito";
		else
			cout << "\n coda piena";
		break;
	}
	case 2: {
		V = new MezzoPesante;
		cin.ignore();
		V->inserisci_dati();
		if (a = c.InserisciVeicolo(V))
			cout << "\n inserimento riuscito";
		else
			cout << "\n coda piena";
		break;
	}
	}

}
