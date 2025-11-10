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
 * File:          adtlist.c
 *
 * P.N.:
 *
 * Product:       "Linked List" abstract data type
 *
 * Creation date: 3 august 2006
 *
 * Description:   Implementazione delle funzioni definite nel file adtlist.h
 *
 *
 ***************************************************************************/



/*@********************************************
* INCLUDE SECTION
**********************************************/
#include <stdio.h>
#include <stdlib.h>

#include "adtlist.h"


/*@********************************************
* FUNCTION IMPLEMENTATION
**********************************************/


int adtlist_new(adtlist_t *list) {

 if (list == NULL)
  return 1; //Nessuna memoria allocata per la lista.
  
 list->list = NULL;
 list->count = 0;
 
 return 0; //Nessun errore
}


static nodo_t *delete_list(nodo_t *nodo) {

 if (nodo != NULL) {
  nodo->next = delete_list(nodo->next);
  
  if (nodo->pointer != NULL)
   free(nodo->pointer);
  
  free(nodo);
 }
 
 return NULL;
}


int adtlist_delete(adtlist_t *list) {

 if (list == NULL)
  return 1; //Nothing to do?!?
 
 //Dealloca tutta la memoria della lista
 list->list = delete_list(list->list);
 list->count = 0;
 
 return 0; //Nessun errore
}


int adtlist_numelem(adtlist_t *list) {

 if (list == NULL)
  return -1;

 return list->count;
}


void *adtlist_get(adtlist_t *list, int position) {
 
 void *ret_value = NULL;
 nodo_t *temp;
 int i;

 if (list == NULL)
  return NULL;
  
 if ((position >= 0) && (position < list->count)) {
  
  temp = list->list;
  for (i=0 ; i<position ; i++) {
   temp = temp->next;
  }
  ret_value = temp->pointer;
 }
  
 return ret_value;
}


static nodo_t *alloca_nodo() {
 nodo_t *temp;
 
 temp = (nodo_t *) malloc(sizeof(nodo_t));
 
 if (temp != NULL) {
  temp->next = NULL;
  temp->pointer = NULL;
 }
 
 return temp;
}


int adtlist_push(adtlist_t *list, void *pointer) {
 
 nodo_t *temp;
 
 if (list == NULL)
  return 1;
 
 temp = list->list;
 list->list = alloca_nodo();
 if (list->list == NULL) {
  list->list = temp;
  return 2;
 }
 
 list->list->next = temp;
 list->list->pointer = pointer;
 list->count++;

 return 0; //Nessun errore
}


void *adtlist_pop(adtlist_t *list) {
 
 nodo_t *temp;
 void *ret_value = NULL;
 
 if (list == NULL)
  return NULL; //Mi prendi in giro?
 
 if (list->count == 0) {
  return NULL; //Nessun elemento nella lista
 }
  
 if (list->list == NULL) {
  return NULL; //Lista spezzata?
 }
 
 ret_value = list->list->pointer; //Salvo il puntatore da restituire
 temp = list->list; //Puntatore da deallocare
 list->list = list->list->next; //Cancello la testa della lista
 free(temp); //Libero la memoria
 list->count--; //Decremento il numero degli elementi
 
 return ret_value; //Nessun errore
}


int adtlist_totail(adtlist_t *list, void *pointer) {
 
 nodo_t *temp;
 nodo_t *new;
 
 if (list == NULL)
  return 1;
 
 //Alloco spazio per il nuovo nodo
 new = alloca_nodo();
 if (new == NULL)
  return 2; //Impossibile allocare la memoria
 new->pointer = pointer;
 new->next = NULL;
 
 if (list->list == NULL) { //Se la lista è vuota
  list->list = new;
 }
 else {
  temp = list->list;
  while (temp->next != NULL) {
   temp = temp->next;
  }
  temp->next = new;
 }
 
 list->count++;

 return 0; //Nessun errore
}


void *adtlist_fromtail(adtlist_t *list) {
 
 nodo_t *temp = NULL;
 nodo_t *prev = NULL;
 void *ret_value = NULL;
 
 if (list == NULL)
  return NULL; //Mi prendi in giro?
 
 if (list->count == 0) {
  return NULL; //Nessun elemento nella lista
 }
  
 if (list->list == NULL) {
  return NULL; //Lista spezzata?
 }
 
 temp = list->list;
 while (temp->next != NULL) {
  prev = temp;
  temp = temp->next;
 }
 
 ret_value = temp->pointer; //Salvo il puntatore da restituire
 
 if (prev == NULL) {
  list->list = NULL;
 }
 else {
  prev->next = NULL;
 }
 
 free(temp); //Libero la memoria
 list->count--; //Decremento il numero degli elementi
 
 return ret_value; //Nessun errore
}


int adtlist_compare(void *a, void *b) {

 int ar = *((int *) a);
 int br = *((int *) b);

 if (ar < br)
  return -1;
 
 if (ar > br)
  return 1;
 
 return 0;
}


int adtlist_insert(adtlist_t *list, void *pointer, compare_t func) {
 
 nodo_t *temp = NULL;
 nodo_t *prev = NULL;
 nodo_t *new = NULL;
 int compare_ok = 0;
 compare_t lcompare = compare;
 
 if (list == NULL)
  return 1;
 
 //Verifico la funzione di ordinamento
 if (func != NULL)
  lcompare = func;
 
 //Alloco spazio per il nuovo nodo
 new = alloca_nodo();
 if (new == NULL)
  return 2; //Impossibile allocare la memoria
 new->pointer = pointer;
 new->next = NULL;
 
 if (list->list == NULL) { //Se la lista è vuota
  list->list = new;
 }
 else {
  temp = list->list;
  
  while ((temp != NULL) && ((*lcompare)(pointer, temp->pointer) == 1)) {
   prev = temp;
   temp = temp->next;
  }
  
  if (prev == NULL) {
   list->list = new;
   new->next = temp;
  }
  else {
   prev->next = new;
   new->next = temp;
  }
 }
 
 list->count++;

 return 0; //Nessun errore
}


int adtlist_del(adtlist_t *list, void *pointer) {

	nodo_t *temp = NULL;
	nodo_t *prev = NULL;
	
	if (list == NULL)
		return 1; //Mi prendi in giro?
	
	if (list->count == 0) {
		return 2; //Nessun elemento nella lista
	}
		
	if (list->list == NULL) {
		return 3; //Lista spezzata?
	}
	
	temp = list->list;
	while (temp->pointer != pointer) {
		if (temp->next == NULL) { //La lista è finita senza trovare l'elemento
			return 4;
		}
		prev = temp;
		temp = temp->next;
	}
	
	if (prev == NULL) {
		list->list = list->list->next;
	}
	else {
		prev->next = temp->next;
	}
	
	free(temp); //Libero la memoria
	list->count--; //Decremento il numero degli elementi
	
	return 0; //Nessun errore
}



/*@********************************************
* MAIN PROGRAM PER TESTATRE LA LIBRERIA
**********************************************/
#ifdef _ADTLIST_DEBUG_



#define MAX 9


int personal_compare(void *a, void *b) {

 int ar = *((int *) a);
 int br = *((int *) b);

 if (ar > br)
  return -1;
 
 if (ar < br)
  return 1;
 
 return 0;
}


void plist(adtlist_t *list) {
 int i;
 int *temp;
 
 printf("list>>");
 for (i=0 ; i<adtlist_numelem(list) ; i++) {
  temp = (int *) adtlist_get(list, i);
  printf("  [%d]%p|%d", i, temp, *temp);
 }
 printf("\n");
}


int main (int argc, const char * argv[]) {
    
 adtlist_t list;
 int i;
 int *elem;
 
 // Creo la lista
 if (adtlist_new(&list) != 0)
     printf("[ERRORE] impossibile creare la lista\n");
 else
  printf("Lista creata\n");
 
 printf("PROVA STACK\n");
 for (i=0 ; i<MAX ; i++) {
  elem = (int *) malloc(sizeof(int));
  printf("[IN] %p\n", elem);
  if (adtlist_push(&list, (void *) elem) != 0)
   printf("ERRORE adtlist_push!!!\n");
  plist(&list);
 }
 
 while ((elem = (int *) adtlist_pop(&list)) != NULL) {
  printf("[OUT] %p\n", elem);
  plist(&list);
  free(elem);
 }
 
 printf("PROVA CODA\n");
 for (i=0 ; i<MAX ; i++) {
  elem = (int *) malloc(sizeof(int));
  printf("[IN] %p\n", elem);
  if (adtlist_totail(&list, (void *) elem) != 0)
   printf("ERRORE adtlist_totail!!!\n");
  plist(&list);
 }
 
 while ((elem = (int *) adtlist_fromtail(&list)) != NULL) {
  printf("[OUT] %p\n", elem);
  plist(&list);
  free(elem);
 }
 
 printf("PROVA INSERIMENTO CRESCENTE\n");
 for (i=0 ; i<MAX ; i++) {
  elem = (int *) malloc(sizeof(int));
  *elem = rand() % 11;
  printf("[IN] %p %d\n", elem, *elem);
  if (adtlist_insert(&list, (void *) elem, personal_compare) != 0)
   printf("ERRORE adtlist_insert!!!\n");
  plist(&list);
 }
 
 while ((elem = (int *) adtlist_fromtail(&list)) != NULL) {
  printf("[OUT] %p\n", elem);
  plist(&list);
  free(elem);
 }
 
 // Cancello la lista
 if (adtlist_delete(&list) != 0)
  printf("[ERRORE] impossibile cancellare la lista\n");
 else
  printf("Lista canellata\n");

    return 0;
}



#endif
