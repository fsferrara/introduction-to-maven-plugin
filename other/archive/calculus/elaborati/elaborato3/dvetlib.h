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




#ifndef DVETLIB
#define DVETLIB




#include <stdio.h>



double *dveal(int n);
	/*
	Alloca un vettore di n elementi double e restituisce il puntatore
	all'area di memoria allocata.
	Ritorna NULL in caso di errore.
	*/


void dvest(double *x, int n);
	/*
	Stampa il vettore "x" di "n" elementi sullo standard output.
	*/



#endif
