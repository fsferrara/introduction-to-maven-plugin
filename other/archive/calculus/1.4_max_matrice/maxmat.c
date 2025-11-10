#include <stdio.h>
#include "../include/faio.h"

float sasum_(int *n, float *x, int *incx);
int isamax_(int *n, float *x, int *incx);

int main(int argc, char *argv[]) {

	int lda=2;
	int ldb=3;
	int n=lda*ldb;
	int inc=1;
	float *mat;
	int res;
	


	mat = smleggi(mat,lda,ldb,'r');
	smstampa(mat,lda,ldb);
	
	res = isamax_(&n, mat, &inc);
	
	printf("\nChiamando la funzione isamax() con il vettore di %d elementi, il massimo elemento e' %f\n", n, mat[res-1]);
	
	free(mat);
	
	return 0;
}
