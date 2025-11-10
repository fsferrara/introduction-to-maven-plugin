###################################################################################
#                                                                                 #
#                      LABORATORIO DI CALCOLO SCIENTIFICO                         #
#                               A.A. 2004/2005                                    #
#                                                                                 #
#                          Ferrara Francesco Saverio                              #
#                              Matricola: 566/811                                 #
#                          fsterrar@studenti.unina.it                             #
#                                                                                 #
###################################################################################
#
# I target definiti in questo Makefile sono:
# 
#       all - Il target principale che serve a compilare il progetto. Esso è il target
#             di default di quando si chiama il comando make senza argomenti.
#
#     clean - Pulisce la directory da tutti i file creati.
#
# clean_exe - Cancella il file eseguibile del progetto.
#
# clean_obj - Cancella tutti i file oggetto creati.
#
# clean_dip - Cancella il file delle dipendenze. Questa opzione non porta a
#             nessun danno in quanto il file viene creato automaticamente se non
#             esiste.
#
#     clear - Cancella i fastidiosi file temporanei che terminano con il
#             carattere '~´ creati da alcuni editor di testo.
#
###################################################################################



# Decommentare la prossima riga per scegliere un altro compilatore
# CC = gcc


# Opzioni passate al compilatore
CFLAG = -funroll-loops


# Nome del file eseguibile da creare
MAIN1 = eseguibile1
MAIN2 = eseguibile2
MAIN3 = eseguibile3


# File sorgenti (.c) e i rispettivi file oggetto (.o)
SOURCES1 = esercizio1.c
OBJECTS1 = $(SOURCES1:.c=.o)
SOURCES2 = esercizio2.c
OBJECTS2 = $(SOURCES2:.c=.o)
SOURCES3 = esercizio3.c
OBJECTS3 = $(SOURCES3:.c=.o)





# Comando per cancellare i file usato durante il target "clean"
DEL = rm -rf


# File momentaneo usato per ricavarsi le dipendenze dei file
DIPENDENZE1 = .d1
DIPENDENZE2 = .d2
DIPENDENZE3 = .d3



# Target "all" è il target principale.
all : 
	@echo -e "usare 'make esercizio1' oppure 'make esercizio2' oppure 'make esercizio3'\n"

esercizio1 : $(DIPENDENZE1) $(MAIN1)
	

esercizio2 : $(DIPENDENZE2) $(MAIN2)
	

esercizio3 : $(DIPENDENZE3) $(MAIN3)
	



# Calcolo delle dipendenze per tutti i file dorgenti. Per fare questo si usa
# l'opzione -M del compilatore che produce un output direttamente in formato
# Makefile

$(DIPENDENZE1) :
	$(CC) $(CFLAG) -M $(SOURCES1) >> $(DIPENDENZE1)

$(DIPENDENZE2) :
	$(CC) $(CFLAG) -M $(SOURCES2) >> $(DIPENDENZE2)

$(DIPENDENZE3) :
	$(CC) $(CFLAG) -M $(SOURCES3) >> $(DIPENDENZE3)



# Questo "if" serve a far includere il file con le dipendenze solo quando
# esso è stato effettivamente creato

ifeq ($wildcard $(DIPENDENZE1), $(DIPENDENZE1))
	include $(DIPENDENZE1)
endif

ifeq ($wildcard $(DIPENDENZE2), $(DIPENDENZE2))
	include $(DIPENDENZE2)
endif

ifeq ($wildcard $(DIPENDENZE3), $(DIPENDENZE3))
	include $(DIPENDENZE3)
endif



# Linkaggio per avere il file eseguibile

$(MAIN1) : $(OBJECTS1)
	$(CC) $(CFLAG) -o $(MAIN1) $(OBJECTS1) -lblas -lg2c

$(MAIN2) : $(OBJECTS2)
	$(CC) $(CFLAG) -o $(MAIN2) $(OBJECTS2) -llapack

$(MAIN3) : $(OBJECTS3)
	$(CC) $(CFLAG) -o $(MAIN3) $(OBJECTS3) -lg2c -lfftw3



# Definisco i target PHONY (target che non corrispondono a file)

.PHONY: clean clean_exe clean_dip clean_obj clear 
	

# Pulisce i file dopo la compilazione

clean: clean_exe clean_dip clean_obj
	

clean_exe:
	$(DEL) $(MAIN1) $(MAIN2) $(MAIN3)

clean_dip:
	$(DEL) $(DIPENDENZE1) $(DIPENDENZE2) $(DIPENDENZE3)

clean_obj:
	$(DEL) *.o


# Cancella i fastidiosi file temporanei che terminano con il carattere '~´
# creati da alcuni editor di testo.

clear:
	$(DEL) *~

