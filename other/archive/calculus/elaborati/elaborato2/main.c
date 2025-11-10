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
#include <errno.h>
#include "util.h"



// Dichiarazione della routine di lapack usata
void sspsv(char *uplo, int *n, int *nrhs, float *ap, int *ipiv, float *b, int *ldb, int *info);



//Stampa di un help
void help() {
	fprintf(stdout, "###################################################################################\n");
	fprintf(stdout, "#                      LABORATORIO DI CALCOLO SCIENTIFICO                         #\n");
	fprintf(stdout, "#                               A.A. 2004/2005                                    #\n");
	fprintf(stdout, "#                                                                                 #\n");
	fprintf(stdout, "#                      Ferrara Francesco Saverio - 566/811                        #\n");
	fprintf(stdout, "#                          fsterrar@studenti.unina.it                             #\n");
	fprintf(stdout, "###################################################################################\n\n");
	fprintf(stdout, "Software per la risoluzione di un sistema Ax=b, con A matrice quadrata di ordine n,\n");
	fprintf(stdout, "simmetrica, e x e b vettori di dimensione n.\n\n");
	fprintf(stdout, "Per la simmetria della matrice A, essa puo' essere memorizzata nella forma packed\n");
	fprintf(stdout, "storage, quindi nell'input dei dati non e' necessario inserire tutti gli elementi,\n");
	fprintf(stdout, "ma basta inserire gli elementi del triangolo inferiore della matrice per colonne,\n");
	fprintf(stdout, "oppure del triangolo superiore per righe.\n\n");
	fprintf(stdout, "Chiamare il programma senza argomenti.\n");
	fprintf(stdout, "Per maggiorni informazioni leggere la documentazione allegata.\n");
}


int main(int argc, char *argv[]) {

	int n; // Dimensione della matrice A
	int nrhs = 1; // Abbiamo un unico vettore che rappresenta la soluzione
	int *ipiv; // Tiene traccia degli scambi sulla matrice durante le operazioni svolte da sspsv_()
	int info; // Contiene il valore di terminazione di sspsv_()
	float *ap; // Matrice triangolare di n elementi memorizzata nel formato packed storage
	float *b; // Vettore contenente i termini noti
	char uplo = 'l'; // Memorizziamo la matrice ap utilizzando solo il suo triangolo inferiore

	

	/* (inizio) CONTROLLO DEGLI ARGOMENTI IN INPUT (inizio) */

	if (argc > 1) { //Se sono stati passati argomenti
		if ((argc == 2) && ((strncmp(argv[1],"--help",7)==0) || (strncmp(argv[1],"-h",3)==0))) {
			help(); //Stampo a video una mini-guida all'uso del programma
			return EXIT_SUCCESS; //Esco con un valore di successo
		}
		fprintf(stderr, "Errore nel passaggio dei parametri\nUsa: %s --help\nper avere maggiori informazioni\n", argv[0]);
		return EXIT_FAILURE; //Ritorno alla shell un indicatore di errore
	}
	
	/* (fine) CONTROLLO DEGLI ARGOMENTI IN INPUT (fine) */



	/* (inizio) INSERIMENTO DATI INPUT (inizio) */

	fprintf(stdout, "Inserisci la dimensione della matrice A: ");
	fscanf(stdin, "%d", &n); // Numero di righe della matrice

	ap = spcle(n); // Legge dallo standard input la matrice
	if (ap == NULL) {
		perror("malloc");
		return EXIT_FAILURE;
	}

	b = svele(n); // Legge dallo standard input il vettore dei termini noti
	if (b == NULL) {
		perror("malloc()");
		return EXIT_FAILURE;
	}
	
	/* Il vettore ipiv e' un parametro di output per la funzione sspsv_() */	
	ipiv = (int *) calloc(n, sizeof(int)); // Alloca spazio per il vettore ipiv
	if (ipiv == NULL) {
		perror("calloc()");
		return EXIT_FAILURE;
	}



	/* (fine) INSERIMENTO DATI INPUT (fine) */



	sspsv_(&uplo, &n, &nrhs, ap, ipiv, b, &n, &info); // Chiamo la funzione di lapack
	
	if (info > 0) { // Non e' possibile calcolare la soluzione
	        fprintf(stderr, "La matrice e' singolare in quanto l'elemento %d della diagonle e' esattamente zero.\n", info);
		return EXIT_FAILURE;
	}
	else
	        if (info < 0) { // Errore nel passaggio dei parametri alla funzione
			fprintf(stderr, "La funzione sspsv() del pacchetto lapack e' stata chiamata con parametri errati.\n");
			return EXIT_FAILURE;
		}
		else // La funzione e' terminata correttamente
			fprintf(stdout, "Fine della computazione!\n");



	/* (inizio) STAMPA DATI OUTPUT (inizio) */

	svest(b, n); // Stampo sullo standard output il vettore "vet"

	/* (fine) STAMPA DATI OUTPUT (fine) */



	// Libero la memoria HEAP utilizzata durante l'eleborazione
	free(ap);
	free(b);
	free(ipiv);



	return EXIT_SUCCESS; // Ritorno un indicaore di successo
}

