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



void smast(float *a, int n, int m) {

	int i,j;



	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<m ; j++)
			fprintf(stdout, "  [%2d,%2d] %11f", i+1, j+1, a[(j*(n))+i]);
		fprintf(stdout, "\n");
	}
}
