#include <stdio.h>
#include "../include/faio.h"

float sasum_(int *n, float *x, int *incx);
float isamax_(int *n, float *x, int *incx);

void strsv_(char* uplo, char *trans, char *diag, int *n, float *mat, int *lda, float *vet, int *incx);

int main(int argc, char *argv[]) {

	int lda=2;
	int ldb=2;
	int n=2;
	float *mat;
	float *vet;
	
	char diag='n';
	char uplo='u';
	char trans = 'n';
	int incx=1;
	
	
	
	mat = smleggi(mat,lda,ldb,'r');
	vet = svleggi(vet, n);
	svstampa(vet, n);
	smstampa(mat,lda,ldb);

	strsv_(&uplo, &trans, &diag, &n, mat, &lda, vet, &incx);
	
	svstampa(vet, n);
	free(vet);
	free(mat);
	
	return 0;
}
