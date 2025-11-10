#include "../faio/faio.h"
#include <stdio.h>


double ddot_(int *, double *, int *,double *, int *);


int main(int argc, char *argv[]) {


	double *x,*y,z;
	int n=5, inc=1;

	x = dvleggi(x, n);
	y = dvleggi(y, n);
	
	printf("STAMPO X\n");
	dvstampa(x,n);
	printf("STAMPO X\n");
	dvstampa(x,n);

	z = ddot_(&n, x, &inc, y, &inc);

	printf("risultato: %g con n=%d e inc=%d\n", z, n, inc);

	free(x);
	free(y);
	
	return 0;
}
