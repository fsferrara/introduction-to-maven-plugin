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



#ifndef FAIO
#define FAIO



#include <stdio.h>



float *svleggi(float *x, int n);
	/*
	Doc
	*/

double *dvleggi(double *x, int n);
	/*
	Doc
	*/

void svstampa(float *x, int n);
	/*
	Doc
	*/

void dvstampa(double *x, int n);
	/*
	Doc
	*/

float *smleggi(float *a, int lda, int ldb, char modo);
	/*
	Doc
	*/
	
void smstampa(float *a, int lda, int ldb);
	/*
	Doc
	*/
	
double *dmleggi(double *a, int lda, int ldb, char modo);
	/*
	Doc
	*/
	
void dmstampa(double *a, int lda, int ldb);
	/*
	Doc
	*/



#endif
