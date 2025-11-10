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



float *smale(float *a, int n, int m) {

	int i,j;
	
	
	a = (float *) calloc(n*m, sizeof(float)); //alloco la memoria
	if (a==NULL) { //se c'e' stato un errore durante l'allocazione della memoria
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL; //termino la procedura restituendo un indicatore di errore
	}



	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<m ; j++) {
			fprintf(stdout, "%2d,%2d>> ", i+1, j+1);
			fscanf(stdin, "%f", &a[(j*(n))+i]);
		}
	}

	return a; //ritorno il puntatore alla matrice creata
}
