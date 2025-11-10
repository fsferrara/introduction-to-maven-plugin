
#include "utente2.h"

void inserisci_datiUtente(Utente & U){

   char nome[SIZE];
   char cognome[SIZE]; 
   cout << "\n inserisci il nome: ";
   cin.getline(U.nome,SIZE-1);
   cout << "inserisci il cognome: ";
   cin.getline(U.cognome,SIZE-1);
}   





