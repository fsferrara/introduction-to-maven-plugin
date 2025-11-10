//---------------------------------------------------------------------------

#ifndef ZainoSolverH
#define ZainoSolverH

#undef ZainoSolverDebug


#include <iostream.h>
#include <limits.h>

#include "Matrix.h"
#include "Zaino.h"

class ZainoSolver {

private:

	int n; // number of objects
	int Wmax; // max capacity
	Oggetto **oggetti;



public:

	// COSTRUTTORE
	ZainoSolver(int maxCapacity);

	// DISTRUTTORE
	~ZainoSolver();


	// Metodi pubblici
	void addObj(int peso, int profitto);
	Zaino *solvePD1();
	Zaino *solvePD2();

};

//---------------------------------------------------------------------------
#endif
