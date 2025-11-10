/**********************************************************************************
*                                                                                 *
*                      LABORATORIO DI CALCOLO SCIENTIFICO                         *
*                               A.A. 2004/2005                                    *
*                                                                                 *
*                          Ferrara Francesco Saverio                              *
*                              Matricola: 566/811                                 *
*                          fsterrar@studenti.unina.it                             *
*                                                                                 *
**********************************************************************************/


#include "util.h"



float *svele(int n) {

	int i;
	float *x; // Vettore che verra' restituito in output
	
	
	x = (float *) calloc(n, sizeof(float)); // Alloco la memoria
	if (x==NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}
	

	fprintf(stdout, "Inserisci il vettore dei termini noti...\n");
	for (i=0 ; i<n ; i++) { // Leggo gli elementi
		fprintf(stdout, "%2d>> ", i+1);
		fscanf(stdin, "%f", &x[i]);
	}

	return x; // Ritorno il vettore alla procedura chiamante
}

