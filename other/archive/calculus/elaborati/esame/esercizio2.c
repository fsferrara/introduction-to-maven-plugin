#include <stdio.h>
#include "util.h"


// Dichiarazione della routine di lapack usata
void sgesv(int *n, int *nrhs, float *a, int *lda, int *ipiv, float *b, int *ldb, int *info);


int main(int argc, char *argv[]) {

	int n;
	int b;
	int i;
	int nrhs=1;
	int *ipiv=NULL;
	int info;
	float *mat=NULL;
	float *vet=NULL;

        printf("inserisci il numero di blocchi (numero pari): ");
	scanf("%d", &b);

	printf("inserisci la dimensione dei blocchi: ");
	scanf("%d", &n);
	
	ipiv = iipgt(n);
	
	printf("inserisci il vettore per il prodotto: ");
	vet = svele(vet, n*b);

	for (i=0 ; i<b ; i++) {
	
		printf("inserisci per righe il blocco %d della matrice", i+1);
                mat = smale(mat, n, n);
	
		sgesv_( &n, &nrhs, mat, &n, ipiv, vet+(i*n), &n, &info);

		if (info > 0)
			printf("La matrice e' singolare!\n");
		else
			if (info < 0)
				printf("La funzione e' stata chiamata con parametri errati\n");
	}
	
	printf("RISULATO: ");
	svest(vet, n*b);
	
	free(mat);
	free(vet);
	free(ipiv);

	return 0;
}

