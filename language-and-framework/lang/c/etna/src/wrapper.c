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

#include "wrapper.h"
 
static void fatal_error(threadinfo_t *arg) {
	if (arg->debug)
		fprintf(stdout, "Errore di rete! Verificare il cavo e/o il programma client\n");
	
	pthread_mutex_lock(&m_lista);
	
	chiudi_connessione(arg->connessione); //chiudo la connessione
	arg->connessione = -1;
	
	pthread_mutex_unlock(&m_lista);
	
	pthread_exit(NULL);
}
 
void netscan(threadinfo_t *arg, char *buffer, int maxlen) {
	
	int count = 0;
	
	if (maxlen == 0) {
		buffer[0] = '\0';
	}
	else {
		do {
			if (ricevi(arg->connessione, &(buffer[count]), 1) != 0) {
				fatal_error(arg);
			}
			count++;
		} while (((count-1)<maxlen) && (buffer[count-1] != '\n'));
		
		buffer[count]='\0';
	}
}

void netprint(threadinfo_t *arg, char *buffer, int len) {

	if (trasmetti(arg->connessione, buffer, len) != 0) {
		fatal_error(arg);
	}
}
