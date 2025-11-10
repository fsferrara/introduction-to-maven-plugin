//---------------------------------------------------------------------------


#pragma hdrstop

#include "ZainoSolver.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)



// COSTRUTTORE
ZainoSolver::ZainoSolver(int maxCapacity) {
	n = 0;
	Wmax = maxCapacity;

	#ifdef ZainoSolverDebug
		cout << "ZainoSolver::ZainoSolver(int maxCapacity)" << endl;
	#endif

	// Creo un vettore di puntatori ad oggetti, stimando max W oggetti
	oggetti = new Oggetto* [Wmax];
}

// DISTRUTTORE
ZainoSolver::~ZainoSolver() {

	#ifdef ZainoSolverDebug
		cout << "ZainoSolver::~ZainoSolver()" << endl;
	#endif

	for (int i = 0; i < n; i++) {
		delete oggetti[i];
	}
	delete [] oggetti;
}


void ZainoSolver::addObj(int peso, int profitto) {
	oggetti[n] = new Oggetto(n+1, peso, profitto);
	n++;
}

Zaino *ZainoSolver::solvePD1() {
	Matrix f(n+1,Wmax+1);

	int w;

    // CONDIZIONI INIZIALI
	for (w = 0; w < oggetti[0]->getPeso(); w++) {
		f[0][w] = 0;
		f[1][w] = 0;
	}
	for (w = oggetti[0]->getPeso(); w <= Wmax; w++) {
		f[0][w] = 0;
		f[1][w] = oggetti[0]->getProfitto();
	}

	// RIEMPIMENTO DELLA MATRICE
	for (int m = 2; m <= n; m++) {
		for (w=0; w<oggetti[m-1]->getPeso(); w++) {
			f[m][w] = f[m-1][w];
		}
		for (w=oggetti[m-1]->getPeso(); w<=Wmax; w++) {
			if (f[m-1][w] > f[m-1][w-oggetti[m-1]->getPeso()] + oggetti[m-1]->getProfitto()) {
				f[m][w] = f[m-1][w];
			}
			else {
				f[m][w] = f[m-1][w-oggetti[m-1]->getPeso()]+oggetti[m-1]->getProfitto();
			}
		}
	}

	f.dump("fine riempimento");

	// COSTRUZIONE DELLA SOLUZIONE
	Zaino *z;
	z = new Zaino(Wmax);
	w = Wmax;
	for (int m = n; m>0; m--) {
		if (f[m][w] != f[m-1][w]) {
			w -= oggetti[m-1]->getPeso();
			z->addObj(oggetti[m-1]);
		}
	}

	return z;
}

Zaino *ZainoSolver::solvePD2() {

	int pmax = 0;
	for (int i = 0; i < n; i++) {
		pmax += oggetti[i]->getProfitto();
	}

    Matrix f(n+1,pmax+1);

	// CONDIZIONI INIZIALI
	for (int m = 0; m <= n; m++) {
		f[m][0] = 0;
	}
	for (int p = 1; p<=pmax; p++) {
		f[0][p] = 100 /*INT_MAX/2*/;
	}

	// RIEMPIMENTO DELLA MATRICE

	int tmpPeso;

	for (int m = 1; m<=n; m++) {
		for (int p = 1; p<oggetti[m-1]->getProfitto(); p++) {
			f[m][p] = f[m-1][p];
		}
		for (int p = oggetti[m-1]->getProfitto(); p <= pmax; p++) {
			tmpPeso = f[m-1][p-oggetti[m-1]->getProfitto()] + oggetti[m-1]->getPeso();
			if (tmpPeso < f[m-1][p]) {
				f[m][p] = tmpPeso;
			}
			else {
            	f[m][p] = f[m-1][p];
            }
		}

	}


	f.dump("fine riempimento");

	// COSTRUZIONE DELLA SOLUZIONE
	int p=0;
	for (int i = pmax; i>=0; i--) {
		if (f[n][i]<=Wmax) {
			p = i;
			break;
		}
	}

	Zaino *z;
	z = new Zaino(Wmax);

	for (int m = n; m >0 ; m--) {
		if (f[m][p] != f[m-1][p]) {
			p -= oggetti[m-1]->getProfitto();
			z->addObj(oggetti[m-1]);
		}
	}

	return z;

}

