#include <stdio.h>
#include "../include/faio.h"

float sasum_(int *n, float *x, int *incx);
int isamax_(int *n, float *x, int *incx);

int main(int argc, char *argv[]) {

	int lda=2;
	int ldb=9;
	int i, inc=1;
	float *mat;
	int res;
	float vet[ldb];
	
	
	mat = smleggi(mat,lda,ldb,'r');
	smstampa(mat,lda,ldb);
	
	for (i=0 ; i<ldb ; i++) {
		vet[i] = sasum_(&lda, mat+(i*lda), &inc);
	}
	
	for (i=0 ; i<ldb ; i++)
		printf("La somma della colonna %d e' %f\n", i+1, vet[i]);
	
	res = isamax_(&ldb, vet, &inc);
	
	printf("\nChiamando la funzione isamax() con il vettore di %d elementi, la norma infinito e' %d - %f\n", ldb, res, vet[res-1]);
	
	free(mat);
	
	return 0;
}
