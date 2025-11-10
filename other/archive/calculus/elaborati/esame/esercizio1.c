#include <stdio.h>
#include "util.h"


void sgemv(char *trans, int *m, int *n, float *alpha, float *a, int *lda, float *x, int *incx, float *beta, float *y, int *incy);

int main(int argc, char *argv[]) {

	int b;
	int n;
	int i;
	float alpha = 1;
	float beta = 0;
	int inc = 1;
	char trans = 'n';
	float *x=NULL;
	float *a=NULL;
	float *res=NULL;

	
	printf("inserisci il numero di blocchi (numero pari): ");
	scanf("%d", &b);

	printf("inserisci la dimensione dei blocchi: ");
	scanf("%d", &n);

	res = (float *) malloc(sizeof(float) * b*n);
	
	printf("inserisci il vettore per il prodotto: ");
	x = svele(x, n*b);

	for (i=0 ; i<b ; i=i+2) {
		printf("inserisci per righe il blocco %d della matrice", i+1);
		a = smale(a, n, n);
	
		trans = 'n';
		sgemv_(&trans, &n, &n, &alpha, a, &n, x+(i*n), &inc, &beta, res+(i*n), &inc);
		
		trans = 't';
		sgemv_(&trans, &n, &n, &alpha, a, &n, x+((i+1)*n), &inc, &beta, res+((i+1)*n), &inc);


				
	}
	
	printf("RISULATO: ");
	svest(res, n*b);


	free(x);
	free(a);
	free(res);
}

