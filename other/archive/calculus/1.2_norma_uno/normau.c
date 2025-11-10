#include <stdio.h>
#include "../include/faio.h"

float sasum_(int *n, float *x, int *incx);
int isamax_(int *n, float *x, int *incx);

int main(int argc, char *argv[]) {

	int lda=8;
	int ldb=3;
	int i, inc=lda;
	float *mat;
	int res;
	float vet[lda];
	
	
	mat = smleggi(mat,lda,ldb,'r');
	smstampa(mat,lda,ldb);
	
	for (i=0 ; i<lda ; i++) {
		vet[i] = sasum_(&ldb, mat+i, &inc);
	}
	
	for (i=0 ; i<lda ; i++)
		printf("La somma della riga %d e' %f\n", i+1, vet[i]);
	
	inc = 1;
	res = isamax_(&lda, vet, &inc);
	
	printf("\nChiamando la funzione isamax() con il vettore di %d elementi, la norma uno e' %d - %f\n", lda, res, vet[res-1]);
	
	free(mat);
	
	return 0;
}
