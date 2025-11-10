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




#include <stdio.h>
#include <stdlib.h>
#include "util.h"


#define NUM_BLOCCHI 3


//Routin di BLAS usate:
void sgemm(char *transa, char *transb, int *m, int *n, int *k, float *alpha, float *a, int *lda, float *b, int *ldb, float *beta, float *c, int *ldc);

void strmm(char *side, char *uplo, char *transa, char *diag, int *m, int *n, float *alpha, float *a, int *lda, float *b, int *ldb);

void scopy(int *n, float *x, int *incx, float *y, int *incy);



//Funzione che calcola il determinante di quattro blocchi di matrici trangolari
float calcolo_determinante(float *a, float *b, float *c, float *d, int dim) {
	float det=1;
	int i;

	/*
	Questa funzione puo' essere scritta utilizzando un unico ciclo, in
	questo modo:
	
		for (i=0 ; i<dim*dim ; i++) {
			det *= *(a+i);
			det *= *(b+i);
			det *= *(c+i);
			det *= *(d+i);
			i += dim;
		}
	
	Anche se questo ciclo e' molto elegante, si e' preferito dividerlo in
	quattro cicli per sfruttare al massimo la localita' dei dati.
	*/

	for (i=0 ; i<dim*dim ; i++) {  //Calcolo del primo blocco
		det *= *(a+i);
		i += dim;
	}
	
	for (i=0 ; i<dim*dim ; i++) {  //Calcolo del secondo blocco
		det *= *(b+i);
		i += dim;
	}
	
	for (i=0 ; i<dim*dim ; i++) {  //Calcolo del terzo blocco
		det *= *(c+i);
		i += dim;
	}
	
	for (i=0 ; i<dim*dim ; i++) {  //Calcolo del quarto blocco
		det *= *(d+i);
		i += dim;
	}
	
	return det;
}


//Stampa di un help
void help() {
	printf("###################################################################################\n");
	printf("#                      LABORATORIO DI CALCOLO SCIENTIFICO                         #\n");
	printf("#                               A.A. 2004/2005                                    #\n");
	printf("#                                                                                 #\n");
	printf("#                      Ferrara Francesco Saverio - 566/811                        #\n");
	printf("#                          fsterrar@studenti.unina.it                             #\n");
	printf("###################################################################################\n\n");
	printf("Questo programma date due matrici triangolari del tipo:\n\n");
	printf("              /       |       \\              /       |       \\\n");
	printf("              |  TI0  |   0   |              |  TS0  |  TS1  |\n");
	printf("        TI =  |_______|_______| ;      TS =  |_______|_______|\n");
	printf("              |       |       |              |       |       |\n");
	printf("              |  TI1  |  TI2  |              |   0   |  TS2  |\n");
	printf("              \\       |       /              \\       |       /\n\n");
	printf("esegue il loro prodotto ottenendo una matrice del tipo:\n\n");
	printf("                           /       |       \\\n");
	printf("                           |  RE0  |  RE1  |\n");
	printf("                     RE =  |_______|_______|\n");
	printf("                           |       |       |\n");
	printf("                           |  RE2  |  RE3  |\n");
	printf("                           \\       |       /\n\n");
	printf("di quest'ultima verra' calcolato il determinante.\n");
	printf("Per un corretto funzionamento inserire riga per riga tutti i sottoblocchi\n");
	printf("cosi' come vi vengono chiesti dal programma. Chiamare il programma senza argomenti.\n");
	printf("Per maggiorni informazioni leggere la documentazione allegata.\n");
}


int main(int argc, char *argv[]) {

	float *TI[NUM_BLOCCHI];
	float *TS[NUM_BLOCCHI];
	float det, alpha;
	int i, dim, len;
	char uplo, trans, side, diag;



	//Controllo degli argomenti passati da riga di comando
	if (argc > 1) { //Se sono stati passati argomenti
		if ((argc == 2) && ((strncmp(argv[1],"--help",7)==0) || (strncmp(argv[1],"-h",3)==0))) {
			help(); //Stampo a video una mini-guida all'uso del programma
			return EXIT_SUCCESS; //Esco con un valore di successo
		}
		printf("Errore nel passaggio dei parametri\nUsa: %s --help\nper avere maggiori informazioni\n", argv[0]);
		return EXIT_FAILURE; //Ritorno alla shell un indicatore di errore
	}


	//INIZIO Fase in inpute dei dati
	printf("Inserire la dimensione di un qualsiasi blocco: ");
	scanf("%d", &dim);

	printf("Inserire per righe il blocco trinagolare inferiore TI0:\n");
	TI[0] = smtle('l',  TI[0], dim);  //Blocco di tipo triangolare inferiore
	printf("Inserire per righe il blocco TI1:\n");
	TI[1] = smale(TI[1],  dim, dim);  //Blocco di tipo generico
	printf("Inserire per righe il blocco trinagolare inferiore TI2:\n");
	TI[2] = smtle('l',  TI[2], dim);  //Blocco di tipo triangolare inferiore
	printf("Inserire per righe il blocco trinagolare superiore TS0:\n"); 
	TS[0] = smtle('u',  TS[0], dim);  //Blocco di tipo triangolare superiore
	printf("Inserire per righe il blocco TS1:\n");
	TS[1] = smale(TS[1],  dim, dim);  //Blocco di tipo generico
	printf("Inserire per righe il blocco trinagolare superiore TS2:\n");
	TS[2] = smtle('u',  TS[2], dim);  //Blocco di tipo triangolare superiore
	//FINE Fase di input dei dati



	//Calcolo del determinante
	det = calcolo_determinante(TI[0], TI[2], TS[0], TS[2], dim);



	//Calcolo del prodotto della matrice
	alpha = 1; //inizializzo lo scalare alpha
	i=1; //fattore di incremento usato nelle routin saxpy() e scopy()
	trans = 'n'; //considero le matrici non trasposte
	diag = 'n'; //non so se la diagonale di qualche blocco e' unitaria oppure no
	len = dim*dim; //numero di elementi per ogni blocco (usato nelle routin saxpy() e scopy())

	//blocco R3 --> lo registro in TS[2]
	// R3 <- TI[1] * TS[1] + TI[2] * TS[2]
	side='l';
	uplo='l';
	strmm_(&side, &uplo, &trans, &diag, &dim, &dim, &alpha, TI[2], &dim, TS[2], &dim);
	sgemm_(&trans, &trans, &dim, &dim, &dim, &alpha, TI[1], &dim, TS[1], &dim, &alpha, TS[2], &dim);

	//blocco R2 --> lo registro in TI[2]
	// R2 <- TI[1] * TS[0]
	scopy_(&len, TI[1], &i, TI[2], &i);
	side='r';
	uplo='u';
	strmm_(&side, &uplo, &trans, &diag, &dim, &dim, &alpha, TS[0], &dim, TI[2], &dim);

	//blocco R0 --> lo registro in TS[0]
	// R0 <- TI[0] * TS[0] 
	side='l';
	uplo='l';
	strmm_(&side, &uplo, &trans, &diag, &dim, &dim, &alpha, TI[0], &dim, TS[0], &dim);

	//blocco R1 --> lo registro in TS[1]
	// R1 <- TI[0] * TS[1]
	strmm_(&side, &uplo, &trans, &diag, &dim, &dim, &alpha, TI[0], &dim, TS[1], &dim);



	//Stampa dei risultati a video
	printf("[]================[ Stampa del Blocco R0 ]================[]\n");
	smast(TS[0],dim,dim);
	
	printf("[]================[ Stampa del Blocco R1 ]================[]\n");
	smast(TS[1],dim,dim);
	
	printf("[]================[ Stampa del Blocco R2 ]================[]\n");
	smast(TI[2],dim,dim);
	
	printf("[]================[ Stampa del Blocco R3 ]================[]\n");
	smast(TS[2],dim,dim);
	
	printf("DETERMINANTE --> %f\n", det);



	//Libero la memoria precedentemente allocata
	for (i=0 ; i<NUM_BLOCCHI ; i++) {
		free(TI[i]); //libero i blocchi di TI
		free(TS[i]); //libero i blocchi di TS
	}


	return EXIT_SUCCESS; //Ritorno un indicatore di successo
}
