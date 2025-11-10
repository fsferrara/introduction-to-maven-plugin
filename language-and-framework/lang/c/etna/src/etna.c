/***************************************************************************
 *   Copyright (C) 2006 by Francesco Saverio Ferrara                       *
 *   saverix83@tiscali.it                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/***************************************************************************
 *
 * File:          name
 *
 * P.N.:          no number assigned
 *
 * Product:       etna (easy text network application)
 *
 * Creation date: 3 august 2006
 *
 * Description:   Enter a description here
 *
 ***************************************************************************/

#include "etna.h"


static void handler_term(int signo) { //in caso di SIGINT

	int ret_value = EXIT_SUCCESS;
	threadinfo_t *threadinfo;



	if (main_tid == pthread_self()) {

		pthread_mutex_lock(&m_lista);

		while ((threadinfo = (threadinfo_t *) adtlist_pop(&list)) != NULL) {
			if (threadinfo->connessione != -1)
				chiudi_connessione(threadinfo->connessione);
			free(threadinfo);
		}
		
		// Chiudo il socket e non resto piu' in ascolto sulla porta
		arresta_server(id_socket);
		
		if (adtlist_delete(&list) != 0) {
			printf("[ERRORE] impossibile cancellare la lista\n");
			exit(EXIT_FAILURE);
		}
		
		pthread_mutex_unlock(&m_lista);
		exit(EXIT_SUCCESS);
	}
	
	kill(main_pid, SIGINT);
}

static threadinfo_t *alloca_threadinfo() {

	//Modificare questa variabile se si vogliono informazioni di debug
	int debug = 0;
	
	threadinfo_t *temp;
	
	temp = (threadinfo_t *) malloc(sizeof(threadinfo_t));
	if (temp != NULL) {
		temp->connessione = 0;
		temp->debug = debug;
	}
	
	return temp;
}

void *servi_client(void *threadinfo) {
	threadinfo_t *arg = (threadinfo_t *) threadinfo;
	char *banner="ETNA\n";

	if (trasmetti(arg->connessione, &banner, strlen(banner)) != 0)
		printf("ERRORE SOCKET\n");
	
	elaborazione(arg);
	
	pthread_mutex_lock(&m_lista);
	
	if (arg->connessione != -1)
		chiudi_connessione(arg->connessione);
	
	if (adtlist_del(&list, threadinfo) != 0)
		raise(SIGINT);
	
	pthread_mutex_unlock(&m_lista);
}

int main(int argc, char *argv[]) {

	threadinfo_t *threadinfo;
	int portnum = PORTNUM;
	

	// Ricordo informazioni riguardanti il thread principale
	main_pid = getpid();
	main_tid = pthread_self();
	
	pthread_mutex_init(&m_lista, NULL);

	//definisco l funzione da eseguire er SIGINT
	if (signal(SIGINT,handler_term) == SIG_ERR) {
		perror("signal");
		exit(EXIT_FAILURE);
	}
	
	if (adtlist_new(&list) != 0) {
		printf("[ERRORE] impossibile creare la lista\n");
		exit(EXIT_FAILURE);
	}
	
	// Imposto il server in ascolto
	id_socket = avvia_server(MAX_CODA, portnum); 
	
	while(1) {
		threadinfo = alloca_threadinfo();
		if (threadinfo == NULL) {
			printf("[ERRORE] impossibile allocare memoria\n");
			raise(SIGINT);
			exit(EXIT_FAILURE);
		}

		// Accetto una connessione da parte di un client
		threadinfo->connessione = accetta_connessione(id_socket);

		// Accedo alla lista in maniera esclusiva
		pthread_mutex_lock(&m_lista);

		if (adtlist_push(&list, (void *) threadinfo) != 0) {
			printf("[ERRORE] adtlist_push\n");
			raise(SIGINT);
			exit(EXIT_FAILURE);
		}

		// Creo un thread per servire il client
		pthread_create(&(threadinfo->tid),
				 NULL,
				 (void *(*)()) servi_client,
				 (void *) threadinfo);

		pthread_mutex_unlock(&m_lista); //rilascio la lista

		pthread_detach(threadinfo->tid); //stacco il thread e non lo aspetto

	}
	
	//Il flusso del programma non dovrebbe arrivare in questo punto!
	raise(SIGINT);
	exit(EXIT_FAILURE);
	
	return EXIT_FAILURE;
}
