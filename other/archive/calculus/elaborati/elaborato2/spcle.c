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



float *spcle(int n) {

	float *ap; // Matrice che verra' restituita in output
	int dim = ( (n*(n+1))/2 ); // Dimensione della matrice in formato packed storage
	int i;

	ap = (float *) malloc(dim * sizeof(float)); // Alloco la memoria
	if (ap == NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}

	
	fprintf(stdout, "Inserisci gli elementi del triangolo inferiore della matrice per colonne,\n");
	fprintf(stdout, "oppure del triangolo superiore per righe...\n");

	for (i=0 ; i<dim ; i++) { // Leggo gli elementi
		fprintf(stdout, "%2d>> ", i+1);
		fscanf(stdin, "%f", &ap[i]);
	}

	return ap; // Ritorno l'indirizzo della matrice al chiamante
}

