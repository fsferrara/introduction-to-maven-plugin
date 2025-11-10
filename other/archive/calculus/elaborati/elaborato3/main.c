#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <sys/time.h>
#include "dvetlib.h"

#include <fftw3.h> // Utilizzato da fftw3

#define MIN_PROVE 12
#define MAX_CASUALE 100


void dffti_(int *n, double *wsave);
void dfftf_(int *n, double *x, double *wsave);




void stampa_tempo(struct timeval *start, struct timeval *stop) {


	double secondi, microsecondi;
	
	
	secondi = stop->tv_sec - start->tv_sec; // Differenza tra i secondi
	microsecondi = abs(stop->tv_usec - start->tv_usec); // Differenza tra i microsecondi

	// Aggiunge i microsecondi ai secondi
	secondi += ( microsecondi / 1000000. );
	
	fprintf(stdout, "%lf secondi", secondi);
}


void help() {
	fprintf(stdout, "###################################################################################\n");
	fprintf(stdout, "#                      LABORATORIO DI CALCOLO SCIENTIFICO                         #\n");
	fprintf(stdout, "#                               A.A. 2004/2005                                    #\n");
	fprintf(stdout, "#                                                                                 #\n");
	fprintf(stdout, "#                      Ferrara Francesco Saverio - 566/811                        #\n");
	fprintf(stdout, "#                          fsterrar@studenti.unina.it                             #\n");
	fprintf(stdout, "###################################################################################\n\n");
	fprintf(stdout, "Sia M il numero di prove da effettuare, questo programma calcola la DFT del vettore\n");
	fprintf(stdout, "x di dimensione n con n=2^k (per k=1,...,M).\n");
	fprintf(stdout, "Per calcolare la DFT del vettore generato con numeri casuali, viene impiegata prima\n");
	fprintf(stdout, "la libreria FFTW3 e poi la libreria DFFTPACK. Alla fine viene stampato il tempo\n");
	fprintf(stdout, "impiegato da ognuna per confrontarle.\n\n");
	fprintf(stdout, "Opzioni accettate dal programma:\n");
	fprintf(stdout, "\t -h o --help\t:\tVisualizza questa guida\n");
	fprintf(stdout, "\t -v o --verbose\t:\tVisualizza le DFT dei vettori\n\n");
}



int main(int argc, char *argv[]) {

	int n; // Dimensione del vettore
	int m; // Numero di prove
	int k; // Potenze di due
	int i;
	int errore = 1; // Utile al passaggio dei parametri
	int verbose = 0; // Se settata ad 1 il programma stampera' tutte le informazioni sulle DFT
	struct timeval start, stop; // Questa struttura ha due campi: secondi e microsecondi
	struct timezone tz; // Utilizzato da gettimeofday()
	double tmp; // Variabile temporanea usata per memorizzare gli stessi elementi casuali
	
	double *x, *wsave; // Utilizzati con dfftpack
	
	fftw_plan p; // Utilizzato con fftw3


	
	if (argc > 1) { //Se sono stati passati argomenti
		if (argc == 2) {
			if ((strncmp(argv[1],"--help",7)==0) || (strncmp(argv[1],"-h",3)==0)) {
				help(); //Stampo a video una mini-guida all'uso del programma
				return EXIT_SUCCESS; //Esco con un valore di successo
			}
			if ((strncmp(argv[1],"--verbose",10)==0) || (strncmp(argv[1],"-v",3)==0)) {
				errore = 0; // Evito l'uscita dal programma
				verbose = 1; // Setto la variabile in modo da stampare a video le informazioni sulle DFT
			}
		}
		if (errore) {
			fprintf(stderr, "Errore nel passaggio dei parametri\nUsa: %s --help\nper avere maggiori informazioni\n", argv[0]);      
			return EXIT_FAILURE; //Ritorno alla shell un indicatore di errore                                        
		}
	}
	
	
	// Leggo da input il numero di prove che bisogna effettuare
	do {
		fprintf(stdout, "Inserisci il numero di prove: ");
		scanf("%d", &m);
		getchar();
	} while(m < MIN_PROVE);


	// Calcola la dimensione del vettore piu' lungo
	n = pow(2, m);


	// Allocazione della memoria per i vettori
	x = dveal(n);
	if (x == NULL) { // Se c'e' stato un errore durante l'allocazione della memoria
		fprintf(stderr, "Errore durante l'allocazione della memoria\n");
		return EXIT_FAILURE;
	}
	
	wsave = dveal(2*n+15);
	if (wsave == NULL) { // Se c'e' stato un errore durante l'allocazione della memoria
		fprintf(stderr, "Errore durante l'allocazione della memoria\n");
		return EXIT_FAILURE;
	}

	
	
	
	for  (k=1 ; k <= m ; k++) {
		
		n = pow(2, k); // Calcolo la dimensione del k-esimo vettore
		if (verbose) // Se e' stata immessa l'opzione "-v"
			fprintf(stdout, "---> Calcolo la DFT del vettore %d di lunghezza %d.\n", k, n);
		
		for (i=0 ; i<n ; i++) // Generazione di elementi casuali
			x[i] = rand() % MAX_CASUALE;
		
		if (verbose) { // Se e' stata immessa l'opzione "-v"
			fprintf(stdout, "Genero il vettore con numeri casuali -> ");
			dvest(x, n);
		}
		
		
		
		// Calcolo della DFT del vettore con fftw3
		if ( gettimeofday(&start, &tz) != 0 ) {
			perror("getimeoftime()");
			return EXIT_FAILURE;
		}

		p = fftw_plan_r2r_1d(n, x, wsave, FFTW_R2HC, FFTW_ESTIMATE);
		fftw_execute(p);
		fftw_destroy_plan(p);
		
		if ( gettimeofday(&stop, &tz) != 0 ) {
			perror("gettimofday()");
			return EXIT_FAILURE;
		}
		
		fprintf(stdout, "Tempo:    FFTW3 vettore %2d -> ",k);
		stampa_tempo(&start, &stop);
		fprintf(stdout, "\n");

		if (verbose) { // Se e' stata immessa l'opzione "-v"
			fprintf(stdout, "DFT con FFTW3 -> ");
			dvest(wsave, n);
		}



		
		// Calcolo della DFT del vettore con dfftpack	
		if ( gettimeofday(&start, &tz) != 0 ) {
			perror("getimeoftime()");
			return EXIT_FAILURE;
		}
		
		dffti_(&n, wsave);
		dfftf_(&n, x, wsave);

		if ( gettimeofday(&stop, &tz) != 0 ) {
			perror("gettimofday()");
			return EXIT_FAILURE;
		}
		
		fprintf(stdout, "Tempo: DFFTPACK vettore %2d -> ",k);
		stampa_tempo(&start, &stop);
		fprintf(stdout, "\n");
		
		if (verbose) { // Se e' stata immessa l'opzione "-v"
			fprintf(stdout, "DFT con DFFTPACK -> ");
			dvest(x, n);
		}
		
	
		fprintf(stdout, "\nPremi INVIO per continuare\n");
		getchar();
	}

	
	
	// Libero la memoria usata per i vettori
	free(x);
	free(wsave);


	fprintf(stdout, "Programma terminato... arrivederci!\n");
	
	
	return EXIT_SUCCESS;
}

