#ifndef VEICOLO_H
#define VEICOLO_H

const int size = 30;

class Veicolo {

private:
	char* Targa;
	char* Modello;

public:
	Veicolo(const char* T = "", const char* M = "");
	virtual ~Veicolo() {
		delete[] Targa;
		delete[] Modello;
	}
	;
	virtual void calcola_pedaggio()=0;
	virtual void inserisci_dati();
	virtual void stampa_dati();
};

class MezzoLeggero: public Veicolo {
private:
	int Cilindrata;

public:
	MezzoLeggero(const char* T = "", const char* M = "", const int C = 0);

	virtual void inserisci_dati();
	virtual void stampa_dati();
	virtual void calcola_pedaggio();
};

class MezzoPesante: public Veicolo {
private:
	int num_assi;
	int peso;
public:
	MezzoPesante(const char* T = "", const char* M = "", const int NA = 0,
			const int P = 0);
	virtual void inserisci_dati();
	virtual void stampa_dati();
	virtual void calcola_pedaggio();
};
#endif
