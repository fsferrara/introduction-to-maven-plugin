//---------------------------------------------------------------------------

#ifndef OggettoH
#define OggettoH


#undef OggettoDebug

#include <iostream.h>

class Oggetto {

	int id;
	int peso;
	int profitto;

	public:



		// COSTRUTTORE
		Oggetto(int id, int peso, int profitto);

		// DISTRUTTORE
		~Oggetto();



		// getters and setters

		void setPeso(int value) { peso = value; }
		int getPeso() { return peso; }

		void setProfitto(int value) { profitto = value; }
		int getProfitto() { return profitto; }

		void setId(int value) { id = value; }
		int getId() { return id; }



		// DEBUG
		void dump(char *msg = "");
};

//---------------------------------------------------------------------------
#endif
