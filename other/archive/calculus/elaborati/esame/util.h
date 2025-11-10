/**********************************************************************************
*                                                                                 *
*                      LABORATORIO DI CALCOLO SCIENTIFICO                         *
*                               A.A. 2004/2005                                    *
*                                                                                 *
*                          Ferrara Francesco Saverio                              *
*                              Matricola: 566/811                                 *
*                          fsterrar@studenti.unina.it                             *
*                                                                                 *
**********************************************************************************/




#ifndef UTIL
#define UTIL



#include <stdio.h>



double *dmale(double *a, int n, int m) {

	int i,j;
	
	
	a = (double *) calloc(n*m, sizeof(double));
	if (a==NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}
	

	fprintf(stdout, "Inserisci gli elementi della matrice...\n");

	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<m ; j++) {
			fprintf(stdout, "%2d,%2d, %p>> ", i+1, j+1, &a[(j*(n))+i]);
			fscanf(stdin, "%lf", &a[(j*(n))+i]);
		}
	}

	return a;
}

float *smigt(int n) {
	
	int i,j;
	float *a;

	a = (float *) malloc(n * n * sizeof(float));
	if (a == NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}

	
	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<n ; j++) {
			if (i == j)
				a[(n*i)+j] = 1;
			else
				a[(n*i)+j] = 0;
		}
	}

	return a;
}

double *dmigt(int n) {
	
	int i,j;
	double *a;

	a = (double *) malloc(n * n * sizeof(double));
	if (a == NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}

	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<n ; j++) {
			if (i == j)
				a[(n*i)+j] = 1;
			else
				a[(n*i)+j] = 0;
		}
	}

	return a;
}
			
int *iipgt(int n) {

	int *ipiv;
	int i;
	
	ipiv = (int *) malloc(n*sizeof(int));
	if (ipiv != NULL) {
		for (i=0 ; i<n ; i++) {
			ipiv[i] = i+1;
		}
	}

	return ipiv;
}


void iipst(int *ipiv, int n) {
	
	int i;

	fprintf(stdout, "Stampa del vettore degli scambi (IPIV)...\n");

	for(i=0 ; i<n ; i++) {
		fprintf(stdout, " [%2d]-> %2d ",i, ipiv[i]);
	}
	fprintf(stdout, "\n");
}


void dmast(double *a, int n, int m) {

	int i,j;
	
	
	fprintf(stdout, "Stampa della matrice...\n");

	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<m ; j++)
			fprintf(stdout, "  [%2d,%2d] %lf", i+1, j+1, a[(j*(n))+i]);
		fprintf(stdout, "\n");
	}
}


double *dmtle(char uplo, double *a, int n) {

	int i,j;
	
	
	a = (double *) calloc(n*n, sizeof(double));
	if (a==NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}
	

	fprintf(stdout, "Inserisci gli elementi della matrice...\n");

	if (uplo == 'u') {
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<n ; j++) {
				fprintf(stdout, "%2d,%2d, %p>> ", i+1, j+1, &a[(j*(n))+i]);
				if (i<=j)
					fscanf(stdin, "%lf", &a[(j*(n))+i]);
				else {
					fprintf(stdout, "0.00\n");
					a[(j*(n))+i]=0;
				}
			}
		}
	}
	else {
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<n ; j++) {
				fprintf(stdout, "%2d,%2d, %p>> ", i+1, j+1, &a[(j*(n))+i]);
				if (i>=j)
					fscanf(stdin, "%lf", &a[(j*(n))+i]);
				else {
					fprintf(stdout, "0.00\n");
					a[(j*(n))+i]=0;
				}
			}
		}
	}

	return a;
}


void dmtst(double *a, int n) {

	int i,j;
	

	fprintf(stdout, "Stampa della matrice...\n");

	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<n ; j++)
			fprintf(stdout, "  [%2d,%2d] %lf", i+1, j+1, a[(j*(n))+i]);
		fprintf(stdout, "\n");
	}
}


double *dvele(double *x, int n) {

	int i;
	
	
	x = (double *) calloc(n, sizeof(double));
	if (x==NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}
	

	fprintf(stdout, "Inserisci il vettore...\n");
	for (i=0 ; i<n ; i++) {
		fprintf(stdout, "%2d>> ", i+1);
		fscanf(stdin, "%lf", &x[i]);
	}

	return x;
}


void dvest(double *x, int n) {

	int i;
	
	
	fprintf(stdout, "Stampa del vettore:\n");
	for (i=0 ; i<n ; i++)
		fprintf(stdout, " [%2d]-> %lf ", i, x[i]);
	fprintf(stdout, "\n");

}

float *smble(int n, int q, int p) {

	int lda = p+q+1;
	int i, j;
	int tq = q;
	int tp = 1;
	float *ab;
	
	
	ab = (float *) malloc((lda*n) *sizeof(float));
	
	for (i=0 ; i<q ; i++) {
		for (j=0 ; j<lda ; j++) {
			if (j < tq)
				ab[(i*lda)+j] = 0;
			else {
				printf("[%2d][%p]", (i*lda)+j, &ab[(i*lda)+j]);
				scanf("%f", &ab[(i*lda)+j]);
			} 
		}
		tq--;
	}

	while (i < n-p) {
		for (j=0 ; j<lda ; j++) {
			printf("[%2d][%p]", (i*lda)+j, &ab[(i*lda)+j]);
			scanf("%f", &ab[(i*lda)+j]);
		}
		i++;
	}
	
	while (i < n) {
		for (j=0 ; j<lda ; j++) {
			if (j >= lda-tp)
				ab[(i*lda)+j] = 0;
			else {
				printf("[%2d][%p]", (i*lda)+j, &ab[(i*lda)+j]);
				scanf("%f", &ab[(i*lda)+j]);
			} 
		}
		tp++;
		i++;
	}
	
	return ab;
}

float *smale(float *a, int n, int m) {

	int i,j;
	
	if (a == NULL) {	
		a = (float *) calloc(n*m, sizeof(float));
		if (a==NULL) {
			fprintf(stderr, "Errore nell'allocazione della memoria\n");
			return NULL;
		}
	}

	fprintf(stdout, "Inserisci gli elementi della matrice...\n");
	
	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<m ; j++) {
			fprintf(stdout, "%2d,%2d, %p>> ", i+1, j+1, &a[(j*(n))+i]);
			fscanf(stdin, "%f", &a[(j*(n))+i]);
		}
	}

	return a;
}


float *spcle(int n) {

	float *ap;
	int dim = ( (n*(n+1))/2 );
	int i;

	ap = (float *) malloc(dim * sizeof(float));
	if (ap == NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}

	
	fprintf(stdout, "Inserisci gli elementi del triangolo inferiore della matrice per colonne,\n");
	fprintf(stdout, "oppure del triangolo superiore per righe...\n");

	for (i=0 ; i<dim ; i++) {
		fprintf(stdout, "%p>> ", &ap[i]);
		fscanf(stdin, "%f", &ap[i]);
	}

	return ap;
}


void smast(float *a, int n, int m) {

	int i,j;
	
	
	fprintf(stdout, "Stampa della matrice...\n");

	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<m ; j++)
			fprintf(stdout, "  [%2d,%2d] %f", i+1, j+1, a[(j*(n))+i]);
		fprintf(stdout, "\n");
	}
}

void smats(float *a, int n, int m) {

	int i,j;

	fprintf(stdout, "Stampa della matrice...\n");

	for (i=0 ; i<m ; i++) {
		for (j=0 ; j<n ; j++)
			fprintf(stdout, "  [%2d,%2d] %f", i+1, j+1, a[(i*(n))+j]);
		fprintf(stdout, "\n");
	}
}

float *smtle(char uplo, float *a, int n) {

	int i,j;
	
	
	a = (float *) calloc(n*n, sizeof(float));
	if (a==NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}
	

	fprintf(stdout, "Inserisci gli elementi della matrice...\n");

	if (uplo == 'u') {
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<n ; j++) {
				fprintf(stdout, "%2d,%2d, %p>> ", i+1, j+1, &a[(j*(n))+i]);
				if (i<=j)
					fscanf(stdin, "%f", &a[(j*(n))+i]);
				else {
					fprintf(stdout, "0.00\n");
					a[(j*(n))+i]=0;
				}
			}
		}
	}
	else {
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<n ; j++) {
				fprintf(stdout, "%2d,%2d, %p>> ", i+1, j+1, &a[(j*(n))+i]);
				if (i>=j)
					fscanf(stdin, "%f", &a[(j*(n))+i]);
				else {
					fprintf(stdout, "0.00\n");
					a[(j*(n))+i]=0;
				}
			}
		}
	}

	return a;
}


void smtst(float *a, int n) {

	int i,j;
	
	
	fprintf(stdout, "Stampa della matrice...\n");

	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<n ; j++)
			fprintf(stdout, "  [%2d,%2d] %f", i+1, j+1, a[(j*(n))+i]);
		fprintf(stdout, "\n");
	}
}


float *svele(float *x, int n) {

	int i;
	
	
	x = (float *) calloc(n, sizeof(float));
	if (x==NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
		return NULL;
	}
	

	fprintf(stdout, "Inserisci il vettore...\n");
	for (i=0 ; i<n ; i++) {
		fprintf(stdout, "%2d>> ", i+1);
		fscanf(stdin, "%f", &x[i]);
	}

	return x;
}


void svest(float *x, int n) {

	int i;
	
	
	fprintf(stdout, "Stampa del vettore:\n");
	for (i=0 ; i<n ; i++)
		fprintf(stdout, " [%2d]-> %f ", i, x[i]);
	fprintf(stdout, "\n");

}



#endif
