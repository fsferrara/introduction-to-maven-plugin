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




#include <stdio.h>
#include <stdlib.h>



//Routin di BLAS usate:
void strmm(char *side, char *uplo, char *transa, char *diag, int *m, int *n, float *alpha, float *a, int *lda, float *b, int *ldb);



void smast(float *a, int n, int m) {

	int i,j;



	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<m ; j++)
			fprintf(stdout, "  [%2d,%2d] %11f", i+1, j+1, a[(j*(n))+i]);
		fprintf(stdout, "\n");
	}
}


float *smtle(char uplo, float *a, int n) {

	int i,j;
	
	
	a = (float *) calloc(n*n, sizeof(float));
	if (a==NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}



	if (uplo == 'u') {
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
	else {
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

	return a;
}


int main() {

	float *TI;
	float *TS;
	float det, alpha, beta;
	int i, dim;
	char uplo, trans, side, diag;



	//INIZIO Fase in inpute dei dati
	printf("Inserire la dimensione delle matrici: ");
	scanf("%d", &dim);

	printf("Inserire per righe la matrice TI (Triangolare inferiore):\n");
	TI = smtle('l', TI, dim);
	printf("Inserire per righe la matrice TS (Triangolare superiore):\n");
	TS = smtle('u', TS,  dim);
	//FINE Fase di input dei dati



	//Calcolo del determinante
	det = 1;
	for (i=0 ; i<dim*dim ; i++) {
		det *= *(TI+i);
		i += dim;
	}
	for (i=0 ; i<dim*dim ; i++) {
		det *= *(TS+i);
		i += dim;
	}



	//Calcolo del prodotto della matrice
	alpha = 1;
	beta = 0;
	trans = 'n';
	diag = 'n';
	side='l';
	uplo='l';
	strmm_(&side, &uplo, &trans, &diag, &dim, &dim, &alpha, TI, &dim, TS, &dim);



	//Stampa dei risultati a video
	printf("[]================[ Stampa della matrice prodotto ]================[]\n");
	smast(TS,dim,dim);
	
	printf("DETERMINANTE --> %f\n", det);



	//Libero la memoria precedentemente allocata
	free(TI);
	free(TS);


	return EXIT_SUCCESS;
}
