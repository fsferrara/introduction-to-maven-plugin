#ifndef CODA_H
#define CODA_H


#include <iostream>
#include "utente2.h"

using namespace std;


const int DIM=3;
typedef struct Coda {
   Utente LISTA[DIM];
   int t;         // indice che punta alla testa
   int c;         // indice che punta alla coda
   int nelem;     // numero di elementi in coda
};
    
void inizializza_Coda(Coda &); 
bool inserisci(Coda &, const Utente);
bool elimina(Coda &, Utente &);
bool empty(const Coda &);
bool full(const Coda &);

#endif    
             



