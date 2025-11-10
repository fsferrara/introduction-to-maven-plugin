#include <stdio.h>
#include "../include/faio.h"

float sasum_(int *n, float *x, int *incx);
float isamax_(int *n, float *x, int *incx);

void sgemv_(char *trans, int *ldb, int *n, float *alpha, float *mat, int *lda, float *vet, int *incx, float *beta, float *y, int *incy);

int main(int argc, char *argv[]) {

	int lda=2;
	int ldb=2;
	int n=2;
	float *mat;
	float *vet;
	float *y;
	
	char trans = 'n';
	float alpha = 1;
	float beta = 1;
	int incx=1;
	int incy=1;
	
	
	y=(float *) calloc(ldb, sizeof(float));
	
	mat = smleggi(mat,lda,ldb,'r');
	vet = svleggi(vet, n);
	svstampa(vet, n);
	smstampa(mat,lda,ldb);

	sgemv_(&trans, &ldb, &n, &alpha, mat, &lda, vet, &incx, &beta, y, &incy);
	
	svstampa(y, lda);

	free(vet);
	free(mat);
	free(y);
	
	return 0;
}
