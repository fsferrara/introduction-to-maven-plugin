#include <iostream>
#include <stdlib.h>
#include "codacircolare.h"
#include "utente.h"

using namespace std;

int main(int argc, char *argv[])
{
  Coda C;
  Utente U;
  inizializza_Coda(C); 
  
  inserisci_datiUtente(U);
  if(inserisci(C,U)) cout << "inserimento effettuato!";
  else cout << "\n impossibile effettuare l'inserimento. Coda Piena.";
  
  inserisci_datiUtente(U);
  if(inserisci(C,U))  cout << "inserimento effettuato!";
  else cout << "\n impossibile effettuare l'inserimento. Coda Piena.";
  
  inserisci_datiUtente(U);
  if(inserisci(C,U)) cout << "inserimento effettuato!";
  else cout << "\n impossibile effettuare l'inserimento. Coda Piena.";
  
  if(elimina(C,U)) {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  inserisci_datiUtente(U);
  if(inserisci(C,U)) cout << "inserimento effettuato!";
  else cout << "\n impossibile effettuare l'inserimento. Coda Piena.";
  
  inserisci_datiUtente(U);
  if(inserisci(C,U)) cout << "inserimento effettuato!";
  else cout << "\n impossibile effettuare l'inserimento. Coda Piena.";
 
  if(elimina(C,U)) {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  if(elimina(C,U))  {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  if(elimina(C,U))  {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  if(elimina(C,U)) {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  //cin.ignore();
  inserisci_datiUtente(U);
  if(inserisci(C,U)) cout << "inserimento effettuato!";
  else cout << "\n impossibile effettuare l'inserimento. Coda Piena.";
  
  inserisci_datiUtente(U);
  if(inserisci(C,U)) cout << "inserimento effettuato!";
  else cout << "\n impossibile effettuare l'inserimento. Coda Piena.";
  
  inserisci_datiUtente(U);
  if(inserisci(C,U)) cout << "inserimento effettuato!";
  else cout << "\n impossibile effettuare l'inserimento. Coda Piena.";
  
  if(elimina(C,U)) {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  if(elimina(C,U)) {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  if(elimina(C,U)) {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  if(elimina(C,U)) {
      cout << "\n Utente servito: " << U.cognome << " " << U.nome;
  }    
  else cout << "\n impossibile effettuare la cancellazione. Coda Vuota.";
  
  system("PAUSE");	
  return 0;
}


