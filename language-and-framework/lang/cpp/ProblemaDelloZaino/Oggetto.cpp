//---------------------------------------------------------------------------


#pragma hdrstop

#include "Oggetto.h"



//---------------------------------------------------------------------------

#pragma package(smart_init)

// COSTRUTTORE
Oggetto::Oggetto(int iid, int ppeso, int pprofitto) {
	id = iid;
	peso = ppeso;
	profitto = pprofitto;

	#ifdef OggettoDebug
		cout << "Oggetto::Oggetto(int iid, int ppeso, int pprofitto)" << endl;
	#endif
}


// DISTRUTTORE
Oggetto::~Oggetto() {
	#ifdef OggettoDebug
		cout << "Oggetto::~Oggetto()" << endl;
	#endif
}

// DEBUG
void Oggetto::dump(char *msg) {
	cout << "* oggetto(" << id << "):";
	cout << " w(" << id << ")=" << peso;
	cout << " p(" << id << ")=" << profitto;
	cout << endl;
}

