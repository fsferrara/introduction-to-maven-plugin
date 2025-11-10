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
 * File:          adtlist.h
 *
 * P.N.:
 *
 * Product:       "Linked List" abstract data type
 *
 * Creation date: 3 august 2006
 *
 * Description:   Header file for the abstract data type
 *
 *
 ***************************************************************************/

 
#ifndef _ADTLIST_H_
#define _ADTLIST_H_


/*@********************************************
* INCLUDE SECTION
**********************************************/

#include <stdlib.h>


/*@********************************************
* DEFINE SECTION
**********************************************/

//#define _ADTLIST_DEBUG_

/*@********************************************
* MACRO SECTION
**********************************************/

/*@********************************************
* STATICS DATA STRUCTURE
**********************************************/

typedef struct nodo nodo_t;

struct nodo {
 void *pointer; //Puntatore all'elemento
 nodo_t *next;
};

typedef struct adtlist {
 nodo_t *list;
 int count;
} adtlist_t;


/*@********************************************
* GLOBAL DECLARATION SECTION
**********************************************/
typedef int(*compare_t)(void *, void *); //Tipo di puntatore a funzione
int adtlist_compare(void *a, void *b);
static compare_t compare = adtlist_compare; //Dichiarazione del puntatore a funzione


/*@********************************************
* EXTERN DECLARATION SECTION
**********************************************/

/*@********************************************
* FUNCTION PROTOTYPE
**********************************************/



/*
* Function:     adtlist_new
*
* Description:  inizializza la struttura dati adtlist_t
*
* Input:        *list - puntatore alla struttura appena creata
*
* Output:       *list - struttura aggiornata
*
* Return Value: int - vale 0 se non ci sono errori
*/
int adtlist_new(adtlist_t *list);



/*
* Function:     adtlist_delete
*
* Description:  elimina la memoria allocata dalla struttura dati adtlist_t.
*               E' importante notare che la funzione prova a deallocare la memoria
*               degli elementi della lista, quindi se gli elementi contengono a
*               loro volta altri puntatori, è bene provvedere a dealloca con un altra
*               funzione questa memoria
*
* Input:        *list - puntatore alla struttura della lista
*
* Output:       *list - struttura aggiornata
*
* Return Value: int - vale 0 se non ci sono errori
*/
int adtlist_delete(adtlist_t *list);



/*
* Function:     adtlist_numelem
*
* Description:  restituisce il numero di elementi contenuti nella lista
*
* Input:        *list - puntatore alla struttura della lista
*
* Output:       none
*
* Return Value: int - vale -1 se ci sono errori, altrimenti restituisce il numero degli
*                     elementi presenti nella lista
*/
int adtlist_numelem(adtlist_t *list);



/*
* Function:     adtlist_get
*
* Description:  restituisce il puntatore dell'elemento che occupa la posizione position nella lista
*
* Input:        *list - puntatore alla struttura della lista
*               position - intero che descrive la posizione dell'elemento all'interno della lista.
*                          Importante: gli elementi della lista sono numerati a partire da zero
*
* Output:       none
*
* Return Value: void* - vale NULL in caso di errore, altrimenti restituisce il puntatore all'elemento
*/
void *adtlist_get(adtlist_t *list, int position);



/*
* Function:     adtlist_push
*
* Description:  inserisce l'elemento pointer sulla testa della lista (posizione 0)
*
* Input:        *list - puntatore alla struttura della lista
*               *pointer - puntatore che punta all'elemento da inserire in lista
*
* Output:       *list - struttura aggiornata
*
* Return Value: int - vale 0 se non ci sono errori
*/
int adtlist_push(adtlist_t *list, void *pointer);



/*
* Function:     adtlist_pop
*
* Description:  rimuove l'elemento sulla testa della lista (posizione 0) e lo restiusce in output
*
* Input:        *list - puntatore alla struttura della lista
*
* Output:       *list - struttura aggiornata
*
* Return Value: void * - vale NULL in caso di errore, altrimenti restituisce il puntatore all'elemento
*/
void *adtlist_pop(adtlist_t *list);



/*
* Function:     adtlist_totail
*
* Description:  inserisce l'elemento pointer sulla coda della lista (ultima posizione)
*
* Input:        *list - puntatore alla struttura della lista
*               *pointer - puntatore che punta all'elemento da inserire in lista
*
* Output:       *list - struttura aggiornata
*
* Return Value: int - vale 0 se non ci sono errori
*
*/
int adtlist_totail(adtlist_t *list, void *pointer);



/*
* Function:     adtlist_fromtail
*
* Description:  rimuove l'elemento dalla coda della lista (ultima posizione) e lo restiusce in output
*
* Input:        *list - puntatore alla struttura della lista
*
* Output:       *list - struttura aggiornata
*
* Return Value: void * - vale NULL in caso di errore, altrimenti restituisce il puntatore all'elemento
*/
void *adtlist_fromtail(adtlist_t *list);



/*
* Function:     adtlist_totail
*
* Description:  inserisce un elemento nella lista in modo ordinato utilizzando una funzione di comparazione
*               definita dall'utente.
*
* Input:        *list - puntatore alla struttura della lista
*               *pointer - puntatore che punta all'elemento da inserire in lista
*               compare_t - funzione di comparazione definita dall'utente. Se vale NULL di default
*                           e' usata la comparazione tra interi in ordine crescente (si assume che il
*                           puntatore dell'elemento sia un puntatore al tipo int).
*
* Output:       *list - struttura aggiornata
*
* Return Value: int - vale 0 se non ci sono errori
*
*/
int adtlist_insert(adtlist_t *list, void *pointer, compare_t func);



/*
* Function:     adtlist_del
*
* Description:  cancella l'elemento pointer dalla lista, ma non dealloca la memoria per l'elemento stesso.
*               Il programmatore deve provvedere a deallocare la memoria manualmente!!!
*
* Input:        *list - puntatore alla struttura della lista
*               *pointer - puntatore che punta all'elemento da cancellare dalla lista. Questa procedura
*                          non dealloca la memoria puntata da *pointer, ma si limita a cancellare
*                          l'elemento dalla lista.
*
* Output:       *list - struttura aggiornata
*
* Return Value: int - vale 0 se non ci sono errori
*
*/
int adtlist_del(adtlist_t *list, void *pointer);



#endif
