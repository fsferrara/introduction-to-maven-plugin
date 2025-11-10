#include <stdio.h>
#include "../include/faio.h"


void sgemm(char *transa, char *transb, int *m, int *n, int *k, float *alpha, float *a, int *lda, float *b, int *ldb, float *beta, float *c, int *ldc);

void strmm(char *side, char *uplo, char *transa, char *diag, int *m, int *n, float *alpha, float *a, int *lda, float *b, int *ldb);

void saxpy(int *n, float *alpha, float *x, int *incx, float *y, int *incy);

void scopy(int *n, float *x, int *incx, float *y, int *incy);

int main(int argc, char *argv[]) {

	int k=2; //suddivisione in blocchi della matrice
	int d=3; //dimensione di ogni sottomatrice
	float *a[2*k]; //quattro sottomatrici
	float *t; //matrice temporanea
	float *c[2*k]; //quattro sottomatrici per il risultato
	int i;

	char trans='n';
	float alpha=1;
	float beta=0;
	int inc = 1;
	int m=d*d; //dimensione di ogni vettore rappresentante una matrice
	char side;
	char uplo;
	char diag='n';

	
//	ALLOCAZIONE DELLA MEMORIA
	t = (float *) calloc(d*d, sizeof(float));

	for (i=0 ; i<2*k ; i++) {
		c[i] = (float *) calloc(d*d, sizeof(float));
	}
	
//	PRELEVO DATI DALL'INPUT
	for (i=0 ; i<2*k ; i++) {
		printf("Inserisci la sottomatrice A%d...\n", i+1);
		a[i] = smleggi(a[i],d,d,'r');
	}

//	VERIFICA DEI DATI MESSI IN INPUT
	for (i=0 ; i<2*k ; i++) {
		printf("Stampa della sottomatrice A%d:\n", i+1);
		smstampa(a[i],d,d);
	}

//	PRIMO BLOCCO
	sgemm_(&trans, &trans, &d, &d, &d, &alpha, a[0], &d, a[0], &d, &beta, c[0], &d);
	scopy_(&m, a[2], &inc, t, &inc);
	side='l';
	uplo='l';
	strmm_(&side, &uplo, &trans, &diag, &d, &d, &alpha, a[1], &d, t, &d);
	saxpy_(&m, &alpha, t, &inc, c[0], &inc);

//	SECONDO BLOCCO
	scopy_(&m, a[0], &inc, t, &inc);
	side='r';
	uplo='l';
	strmm_(&side, &uplo, &trans, &diag, &d, &d, &alpha, a[1], &d, t, &d);
	scopy_(&m, a[3], &inc, c[1], &inc);
	side='l';
	strmm_(&side, &uplo, &trans, &diag, &d, &d, &alpha, a[1], &d, c[1], &d);
	saxpy_(&m, &alpha, t, &inc, c[1], &inc);

//	TERZO BLOCCO
	scopy_(&m, a[0], &inc, t, &inc);
	side='l';
	uplo='u';
	strmm_(&side, &uplo, &trans, &diag, &d, &d, &alpha, a[2], &d, t, &d);
	scopy_(&m, a[3], &inc, c[2], &inc);
	side='r';
	strmm_(&side, &uplo, &trans, &diag, &d, &d, &alpha, a[2], &d, c[2], &d);
	saxpy_(&m, &alpha, t, &inc, c[2], &inc);

//	QUARTO BLOCCO
	scopy_(&m, a[1], &inc, t, &inc);
	side='l';
	uplo='u';
	strmm_(&side, &uplo, &trans, &diag, &d, &d, &alpha, a[2], &d, t, &d);
	sgemm_(&trans, &trans, &d, &d, &d, &alpha, a[3], &d, a[3], &d, &beta, c[3], &d);
	saxpy_(&m, &alpha, t, &inc, c[3], &inc);
	
//	STAMPA DEL RISULTATO
	for (i=0 ; i<2*k ; i++) {
		printf("Stampa della sottomatrice C%d:\n", i+1);
		smstampa(c[i],d,d);
	}

//	LIBERO LA MEMORIA
	for (i=0 ; i<2*k ; i++) {
		free(a[i]);
		free(c[i]);
	}
	free(t);
	
	return 0;
}
