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




#include "dvetlib.h"



double *dveal(int n) {
	
	double *x;


	x = (double *) calloc(n, sizeof(double)); // Alloca lo spazio di memoria
	
	if (x==NULL) // Se c'e' stato un errore
		fprintf(stderr, "Errore nell'allocazione della memoria\n");
	
	return x;
}
