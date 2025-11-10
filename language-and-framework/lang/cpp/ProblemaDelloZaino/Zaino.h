//---------------------------------------------------------------------------

#ifndef ZainoH
#define ZainoH
//---------------------------------------------------------------------------

#undef ZainoDebug


#include "Oggetto.h"

class Zaino {

private:
	int n; // number of objects
	int m; // max lenght of the solution

	Oggetto **oggetti;



public:
	Zaino(int maxLenght);
	~Zaino();

	void addObj(Oggetto *oggetto);

	int getObjPeso(int posizione);
	int getObjProfitto(int posizione);
	

	// DEBUG
	void dump(char *msg = "");

};

#endif

