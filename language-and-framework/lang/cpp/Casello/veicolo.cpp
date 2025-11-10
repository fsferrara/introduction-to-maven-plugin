#include "veicolo.h"
#include <iostream>

using namespace std;


Veicolo::Veicolo(const char* T, const char* M) {
	Targa = new char[strlen(T) + 1];
	strcpy(Targa, T);
	Modello = new char[strlen(M) + 1];
	strcpy(Modello, M);
}

void Veicolo::inserisci_dati() {
	char buffer[size];
	cout << "\n Inserisci la targa: ";
	cin.getline(buffer, size - 1);
	delete[] Targa;
	Targa = new char[size];
	strcpy(Targa, buffer);
	cout << "\n Inserisci il modello: ";
	cin.getline(buffer, size - 1);
	delete[] Modello;
	Modello = new char[size];
	strcpy(Modello, buffer);
}

void Veicolo::stampa_dati() {
	cout << "\n Targa: " << Targa;
	cout << "\n Modello: " << Modello;
}

MezzoLeggero::MezzoLeggero(const char* T, const char* M, const int C) :
	Veicolo(T, M) {
	Cilindrata = C;
}

void MezzoLeggero::inserisci_dati() {
	cin.ignore();
	Veicolo::inserisci_dati();
	cout << "\n cilindrata :";
	cin >> Cilindrata;
}

void MezzoLeggero::stampa_dati() {
	Veicolo::stampa_dati();
	cout << "\n cilindrata :" << Cilindrata;
}

void MezzoLeggero::calcola_pedaggio() {
	float pedaggio = (Cilindrata / 100) * 2;
	cout << "\n Il pedaggio per questo veicolo e': " << pedaggio << " euro \n";
}

MezzoPesante::MezzoPesante(const char* T, const char* M, const int NA,
		const int P) :
	Veicolo(T, M) {
	num_assi = NA;
	peso = P;
}

void MezzoPesante::inserisci_dati() {
	Veicolo::inserisci_dati();
	cout << "\n Inserisci il numero di assi: ";
	cin >> num_assi;
	cout << "\n Inserisci il peso: ";
	cin >> peso;
}

void MezzoPesante::stampa_dati() {
	Veicolo::stampa_dati();
	cout << "\n Numero assi: " << num_assi;
	cout << "\n Peso : " << peso;
}

void MezzoPesante::calcola_pedaggio() {
	int pedaggio;
	if (num_assi <= 3) {
		pedaggio = 5;
		cout << "\n Il pedaggio per questo veicolo e': " << pedaggio << " euro";
	}
	if ((num_assi > 3) && (peso < 7)) {
		pedaggio = 10;
		cout << "\n Il pedaggio per questo veicolo è: " << pedaggio << " euro";
	}
	if ((num_assi > 5) || (peso > 7)) {
		pedaggio = 10;
		cout << "\n Il pedaggio per questo veicolo è: " << pedaggio << " euro";
	}
}

