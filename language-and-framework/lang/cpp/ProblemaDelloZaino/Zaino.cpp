//---------------------------------------------------------------------------


#pragma hdrstop

#include "Zaino.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


// COSTRUTTORE
Zaino::Zaino(int maxLenght) {
	m = maxLenght;
	n=0;

	#ifdef ZainoDebug
		cout << "Zaino::Zaino(int maxLenght)" << endl;
	#endif

	// Creo un vettore di puntatori ad oggetti, stimando max W oggetti
	oggetti = new Oggetto* [m];
}

// DISTRUTTORE
Zaino::~Zaino() {
	#ifdef ZainoDebug
		cout << "Zaino::~Zaino()" << endl;
	#endif

	delete [] oggetti;
}


void Zaino::addObj(Oggetto *oggetto) {
	oggetti[n] = oggetto;
	n++;
}

int Zaino::getObjPeso(int posizione) {
	return oggetti[posizione]->getPeso();
}

int Zaino::getObjProfitto(int posizione) {
	return oggetti[posizione]->getProfitto();
}


// DEBUG
void Zaino::dump(char *msg) {
	cout << endl << "*** Class Zaino: " << msg << endl;
	for (int i=0; i < n; i++) {
		oggetti[i]->dump("OGGETTO DELLA SOLUZIONE");
	}
	cout << "******" << endl << endl;
}
