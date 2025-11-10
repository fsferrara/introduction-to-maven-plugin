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



#ifndef _TRASMISSIONE_H_
#define _TRASMISSIONE_H_

/*@******************************************************
*   FUNZIONI PER IL SERVER
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>

#define MAXBUFFER 1024
#define DEFAULT_PORT "127.0.0.1"


int avvia_server(int max_connessioni, int portnum);
/*
Avvia il server aprendo la porta PORTNUM, ma non ancora si mette
in ascolto dei client.
*/

int accetta_connessione(int id_socket);
/*
Ascolta se c'e' un client che vuole connettersi, stabilisce la
connessione, e ritorna id.
*/

int chiudi_connessione(int id_connessione);
/*
Chiude una connessione con il server e restituisce 0.
In caso di errore restituisce 1
*/

void arresta_server(int id_socket);
/*
Chiude il socket principale del server
*/

/*@******************************************************
*   FUNZIONI PER IL CLIENT
********************************************************/

int connetti_client(char *ip, int portnum);
/*
Dato un ip in input la funzione stabilisce una connessione con la macchina
individuata dall'ip alla porta PORTNUM. Alla fine viene ritornato l'id
della connessione
*/

void chiudi_connessione_client(int id_connessione);
/*
Dato un id di una connessione, la funzione provvedera' a chiudere la connessione
*/

/*@******************************************************
*   FUNZIONI IN COMUNE
********************************************************/

int ricevi(int id_connessione, void *buffer_r, int dimensione);
/*
legge dalla socket una struct contatto
*/

int trasmetti(int id_connessione, void *buffer_r, int dimensione);
/*
scrive sulla socket una struct contatto
*/

#endif

