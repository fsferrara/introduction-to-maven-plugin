#include <stdio.h>
#include "../util/util.h"


// Dichiarazione della routine di lapack usata
void sgesv(int *n, int *nrhs, float *a, int *lda, int *ipiv, float *b, int *ldb, int *info);


int main(int argc, char *argv[]) {

	int n=4;
	int nrhs=1;
	int lda=n;
	int ldb=n;
	int ipiv[lda];
	int info;
	float *mat;
	float *vet;

	mat = smale(mat, n, lda);
	vet = smale(vet, ldb, nrhs);

	sgesv_( &n, &nrhs, mat, &lda, ipiv, vet, &ldb, &info);

	if (info > 0)
		printf("La matrice e' singolare!\n");
	else
		if (info < 0)
			printf("La funzione e' stata chiamata con parametri errati\n");
		else
			printf("Funzione terminata correttamente!\n");

	smast(vet, ldb, nrhs);
	iipst(ipiv,n);	
	free(mat);
	free(vet);

	return 0;
}

