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



float *smtle(char uplo, float *a, int n) {

	int i,j;
	
	
	a = (float *) calloc(n*n, sizeof(float)); //alloco la memoria
	if (a==NULL) { //se c'e' stato un errore durante l'allocazione della memoria
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL; //termino la procedura restituendo un indicatore di errore
	}



	if (uplo == 'u') { //se devo leggere una matrice triangolare superiore
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<n ; j++) {
				fprintf(stdout, "%2d,%2d>> ", i+1, j+1);
				if (i<=j)
					fscanf(stdin, "%f", &a[(j*(n))+i]);
				else {
					fprintf(stdout, "0.00\n");
					a[(j*(n))+i]=0;
				}
			}
		}
	}
	else { //leggo una matrice triangolare inferiore
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<n ; j++) {
				fprintf(stdout, "%2d,%2d>> ", i+1, j+1);
				if (i>=j)
					fscanf(stdin, "%f", &a[(j*(n))+i]);
				else {
					fprintf(stdout, "0.00\n");
					a[(j*(n))+i]=0;
				}
			}
		}
	}

	return a; //ritorno il puntatore alla matrice creata
}
