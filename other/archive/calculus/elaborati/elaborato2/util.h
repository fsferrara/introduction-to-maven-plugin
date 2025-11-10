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
#include <stdlib.h>




float *spcle(int n);
	/*
	Legge dallo standard input il triangolo inferiore di una matrice simmetrica
	memorizzando per colonna nella forma "packed storage".
	*/
	
float *svele(int n);
	/*
	Legge un vettore di n elementi dallo standard input.
	*/
	
void svest(float *x, int n);
	/*
	Stampa sullo standard output il vettore x di n elementi.
	*/
	
	
#endif

