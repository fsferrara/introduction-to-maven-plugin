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

#ifndef _ETNA_H_
#define _ETNA_H_


//Standard include
#include <stdio.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

//Personal include
#include "adtlist.h"
#include "config.h"


typedef struct threadinfo {
	int connessione; //numero connessione
	pthread_t tid; //tid identificativo del thread
	int debug; //informazioni di debug
} threadinfo_t;

#include "elaborazione.h"
#include "trasmissione.h"
#include "wrapper.h"

//Global definition
static int verbose = 0;
static adtlist_t list;
static int main_pid;
static int id_socket;
static pthread_t main_tid; //tid del thread principale
static pthread_mutex_t m_lista; //mutex per accedere alla lista

#endif
