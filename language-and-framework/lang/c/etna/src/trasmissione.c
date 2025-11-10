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

#include "trasmissione.h"
 
/*@******************************************************
*   FUNZIONI PER IL SERVER
********************************************************/
 
int avvia_server(int max_connessioni, int portnum) {
	struct sockaddr_in sock_address; //contiene la coppia <ip, numero_porta>
	int id_socket; //identificatore del socket creato
	
	
	
	bzero(&sock_address, sizeof(struct sockaddr_in));

	sock_address.sin_family = AF_INET; //setto il tipo di indirizzo
	sock_address.sin_port = htons((u_short) portnum); //setto la porta
	
	id_socket = socket(AF_INET, SOCK_STREAM, 0); //creo il socket
	if (id_socket < 0) { //c'e' un errore
		fprintf(stdout,"avvia_server(): impossibile creare il socket\n");
		exit(EXIT_FAILURE);
	}
	
	//con bind lego il socket creato all'indirizzo
	if (bind(id_socket,(struct sockaddr *) &sock_address, sizeof(struct sockaddr_in)) < 0) { //c'e' un errore
		close(id_socket); //chiudo il socke creato
		fprintf(stdout,"avvia_server(): impossibile dare l'indirizzo al socket creato\n");
		exit(EXIT_FAILURE);
	}
	
	listen(id_socket, max_connessioni); //impongo di avere al massimo max_connessioni in coda
	
	return id_socket; //ritorno l'id del socket creato
 }

 int accetta_connessione(int id_socket) {
	 struct sockaddr_in i_sock_address;
	 int id_connessione; //dopo aver stabilito una connessione
	 int dimensione; //servira' per la chiamata accept.
	
	
	
	 dimensione = sizeof(struct sockaddr_in); //calcolo la dimensione della struttura
	 getsockname(id_socket, (struct sockaddr *) &i_sock_address, &dimensione); //risolvo il nome del socket
	 id_connessione = accept(id_socket, (struct sockaddr *) &i_sock_address, &dimensione); //accetto una connessione
	 if (id_connessione < 0) { //c'e' stato un errore
		 close(id_socket); //chiudo il socket
		 fprintf(stdout,"accetta_connessione(): impossibile accettare una connessione\n");
		 exit(EXIT_FAILURE);
	 }
	
	 return id_connessione; //ritorno l'id della connessione stabilita con il client
 }

 int chiudi_connessione(int id_connessione) {
	 if (close(id_connessione) == -1) //c'e' stato un errore
		 return 1;
	 return 0;
 }

 void arresta_server(int id_socket) {
	 if (close(id_socket) == -1) //c'e' stato un errore
		 perror("arresta_server()"), exit(EXIT_FAILURE);
 }
 
/*@******************************************************
 *   FUNZIONI PER IL CLIENT
********************************************************/
 
 int connetti_client(char *ip, int portnum) {
	 struct sockaddr_in sock_address; //contiene la coppia <ip, numero_porta>
	 int id_connessione; //identificatore del socket creato
	
	
	 bzero(&sock_address, sizeof(struct sockaddr_in)); //azzero la struttura creata
	
	 if (inet_pton(AF_INET, ip, &sock_address.sin_addr) <= 0) { //converto l'ip
		 fprintf(stdout,"connetti(): ip inserito non valido\n"); //probabile errore di input da parte dell'utente
		 exit(EXIT_FAILURE);
	 }
	
	 sock_address.sin_family = AF_INET; //setto il tipo di indirizzo
	 sock_address.sin_port = htons((u_short) portnum); //setto la porta a cui connettersi
	
	 id_connessione = socket(AF_INET, SOCK_STREAM, 0); //creo il socket
	 if (id_connessione < 0) { //c'e' un errore
		 fprintf(stdout,"connetti(): impossibile creare il socket\n");
		 exit(EXIT_FAILURE);
	 }
	
	 if (connect(id_connessione, (struct sockaddr *) &sock_address, sizeof(struct sockaddr_in)) < 0) {
		 close(id_connessione); //chiudo la connessione perche' c'e' stato un errore
		 perror("connetti(): impossibile connettersi");
		 exit(EXIT_FAILURE);
	 }
	
	 return id_connessione; //ritorno l'id della connessione stabilita
 }

 void chiudi_connessione_client(int id_connessione) {
	 if (close(id_connessione) == -1) //chiudo la connessione
		 perror("chiudi_connessione()"), exit(EXIT_FAILURE);
 }

 
/*@******************************************************
 *   FUNZIONI IN COMUNE
********************************************************/
 
 int ricevi(int id_connessione, void *buffer, int dimensione) {
	 int count=0;
	 int byte_letti=0;

	 while(count < dimensione) { //finche' tutti i byte non vengono elaborati
		 if((byte_letti=read(id_connessione, buffer, dimensione - count)) > 0) {
			 count += byte_letti; //conto i byte processati
			 buffer += byte_letti; //aggiorno la posizione del buffer
		 }
		 else
			 return 1;
	 }
	
	 return 0;
 }

 int trasmetti(int id_connessione, void *buffer, int dimensione)
 {
	 int count=0;
	 int byte_scritti=0;
	
	 while(count < dimensione) {  //finche' tutti i byte non vengono elaborati
		 if((byte_scritti=write(id_connessione, buffer, dimensione - count)) > 0) {
			 count += byte_scritti; //conto i byte processati
			 buffer += byte_scritti; //aggiorno la posizione del buffer
		 }
		 else
			 return 1;
	 }
	
	 return 0;
 }

