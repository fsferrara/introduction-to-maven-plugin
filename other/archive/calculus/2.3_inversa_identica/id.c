#include <stdio.h>
#include "../util/util.h"


// Dichiarazione della routine di lapack usata
void sgesv(int *n, int *nrhs, float *a, int *lda, int *ipiv, float *b, int *ldb, int *info);


int main(int argc, char *argv[]) {

	int n=3;
	int *ipiv;
	int info;
	float *mat;
	float *id;


	mat = smale(mat, n, n);

	ipiv = iipgt(n);
	id = smigt(n);
	
	sgesv_(&n, &n, mat, &n, ipiv, id, &n, &info);

	if (info > 0)
		printf("La matrice e' singolare!\n");
	else
		if (info < 0)
			printf("La funzione e' stata chiamata con parametri errati\n");
		else
			printf("Funzione terminata correttamente!\n");

	smast(id, n, n);
	
	free(ipiv);
	free(id);
	
	return 0;
}

