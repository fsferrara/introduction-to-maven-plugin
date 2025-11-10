#include "codacircolare.h"

void inizializza_Coda(Coda & Q) {
   Q.nelem=0;
   Q.t=-1; 
   Q.c=-1;
}

bool empty(const Coda & Q) {
    return Q.nelem==0;
}    

bool full(const Coda & Q) {
  return Q.nelem==DIM;  
}    

bool inserisci(Coda & Q, const Utente U) {
      if(!full(Q)) {
        Q.c=((Q.c+1)%DIM);
        Q.nelem++;
        Q.LISTA[Q.c]= U;
        return true;
     }        
    else return false;
}  

bool elimina(Coda & Q, Utente & U) {
    if(!empty(Q)) {
        Q.t=((Q.t+1)%DIM);
        U=Q.LISTA[Q.t];
        Q.nelem--;
        return true;
   }        
   else return false;
} 

      

