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



void smast(float *a, int n, int m);
	/*
	Stampa standard output una matrice di n righe e m colonne.
	*/

float *smale(float *a, int n, int m);
	/*
	Legge dallo standard input una matrice di n righe e m colonne.
	*/

float *smtle(char uplo, float *a, int n);
	/*
	Legge dallo standard input una matrice triangolare di n righe
	e m colonne.
	
	Se uplo e' uguale a 'u'
	   verrà letta una matrice triangolare superiore
	Se uplo e' uguale a 'l'
	   verrà letta una matrice triangolare inferiore
	*/



#endif
