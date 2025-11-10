#ifndef UTENTE_H
#define UTENTE_H


#include <iostream>
#include <string.h>
const int SIZE=20;

using namespace std;

typedef struct Utente {
    char nome[SIZE];
    char cognome[SIZE];
};       

void inserisci_datiUtente(Utente &);
#endif    
         
