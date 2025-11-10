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



void svest(float *x, int n) {

	int i;
	
	
	fprintf(stdout, "Stampa del vettore delle soluzioni:\n");
	for (i=0 ; i<n ; i++) // Stampo la matrice
		fprintf(stdout, " [%2d]-> %f ", i, x[i]);
	fprintf(stdout, "\n");

}

