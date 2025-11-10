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




#include "dvetlib.h"



void dvest(double *x, int n) {

	int i;
	
	
	fprintf(stdout, "Stampa del vettore:\n");
	for (i=0 ; i<n ; i++)
		fprintf(stdout, " [%2d]-> %lf ", i, x[i]);
	fprintf(stdout, "\n");

}
