#include <stdio.h>
#include "../util/util.h"


// Dichiarazione della routine di lapack usata
void sgetrf(int *m, int *n, float *a, int *lda, int *ipiv, int *info);
void sgetri(int *n, float *a, int *lda, int *ipiv, float *work, int *lwork, int *info);


int main(int argc, char *argv[]) {

	int n=3;
	int *ipiv;
	int info;
	int lwork = n;
	float *mat;
	float *work;
	int i;


	mat = smale(mat, n, n);

	ipiv = (int *) calloc(n, sizeof(int));
	work = (float *) calloc(lwork, sizeof(float));
	
	for (i=0 ; i<n ; i++) {
		ipiv[i]=i+1;
	}

	sgetrf_(&n, &n, mat, &n, ipiv, &info);

	if (info > 0)
		printf("FATTORIZZAZIONE: La matrice e' singolare!\n");
	else
		if (info < 0)
			printf("FATTORIZZAZIONE: La funzione e' stata chiamata con parametri errati\n");
		else
			printf("FATTORIZZAZIONE: Funzione terminata correttamente!\n");

	smast(mat, n, n);
	
	sgetri_(&n, mat, &n, ipiv, work, &lwork, &info);

	if (info > 0)
		printf("INVERSA: La matrice e' singolare!\n");
	else
		if (info < 0)
			printf("INVERSA: La funzione e' stata chiamata con parametri errati\n");
		else
			printf("INVERSA: Funzione terminata correttamente!\n");

	smast(mat, n, n);

	return 0;
}

