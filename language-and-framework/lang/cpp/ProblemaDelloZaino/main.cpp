//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include <iostream.h>

#include "Zaino.h"
#include "ZainoSolver.h"


//---------------------------------------------------------------------------

#pragma argsused

int main(int argc, char* argv[])
{
	int w; // Capacita' zaino
	cout << "Capacita' massima dello zaino (W): ";
	cin >> w;

	int n; // Numero di oggetti
	cout << "Numero degli oggetti (n): ";
	cin >> n;

	
	// Definizione dei pesi e dei profitti
	int *profitto = new int [n];
	int *peso = new int [n];

	for (int i=0; i < n; i++) {
		cout << "oggetto(" << i+1 <<")" << endl;
		cout << "\tw(" << i+1 <<"):";
		cin >> peso[i];
		cout << "\tp(" << i+1 <<"):";
		cin >> profitto[i];
	}


	/*
	int profitto[] = {6, 10, 12};
	int peso[] = {1, 2, 3};
	*/



	ZainoSolver zs(5);

	for (int i = 0; i < n; i++) {
		zs.addObj(peso[i],profitto[i]);
	}

	delete [] peso;
	delete [] profitto;

	cout << "############ RISOLVO CON PD1-ZAINO-0/1 ############" << endl;
	Zaino *z1 = zs.solvePD1();
	z1->dump("Soluzione con PD1-ZAINO-0/1");
	delete z1;

	cout << "############ RISOLVO CON PD2-ZAINO-0/1 ############" << endl;
	Zaino *z2 = zs.solvePD2();
	z2->dump("Soluzione con PD2-ZAINO-0/1");
	delete z2;

	return 0;
}
//---------------------------------------------------------------------------
