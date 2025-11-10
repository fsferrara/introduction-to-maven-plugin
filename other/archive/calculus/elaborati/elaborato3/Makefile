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
#             di default di quando si chiama il comando make senza argomenti. Se si
#             vuole compilare il progetto basta chiamare make in questo modo:
#             make DEBUG=yes.
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
#       run - Manda in esecuzione il progetto. Si avrà uno strano errore stampato
#             a video se il progetto termina restituiendoalla shell un valore
#             diverso da 0.
#
#     debug - Avvia il debug del programma. Se si sceglie questa modalita' bisogna
#             aver compilato in precedenza il programma con informazioni per il
#             debug
#
#     clear - Cancella i fastidiosi file temporanei che terminano con il
#             carattere '~´ creati da alcuni editor di testo.
#
###################################################################################




# Path delle librerie
PATH_LIB = -L/usr/lib/
LIB = -lg2c -ldfftpack -lfftw3 


# Decommentare la prossima riga per scegliere un altro compilatore
# CC = gcc


# Nome del file eseguibile da creare
MAIN = eseguibile


# Compilare con 'make DEBUG=yes` se si vogliono aggiungere informazioni per il
# debug all'eseguibile
ifeq ($(DEBUG), yes)
	CFLAG := $(CFLAG) -g
endif


# File sorgenti (.c) e i rispettivi file oggetto (.o)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)


# Comando per cancellare i file usato durante il target "clean"
DEL = rm -rf


# File momentaneo usato per ricavarsi le dipendenze dei file
DIPENDENZE = .depend


# Comando usato per fare il debug del programma
GDB = gdb

# Target "all" è il target principale.
all : $(DIPENDENZE) $(MAIN)
	

# Calcolo delle dipendenze per tutti i file dorgenti. Per fare questo si usa
# l'opzione -M del compilatore che produce un output direttamente in formato
# Makefile
$(DIPENDENZE) :
	$(CC) $(CFLAG) -M $(SOURCES) >> $(DIPENDENZE)

# Questo "if" serve a far includere il file con le dipendenze solo quando
# esso è stato effettivamente creato
ifeq ($wildcard $(DIPENDENZE), $(DIPENDENZE))
	include $(DIPENDENZE)
endif

# Linkaggio per avere il file eseguibile
$(MAIN) : $(OBJECTS)
	$(CC) $(CFLAG) -o $(MAIN) *.o $(PATH_LIB) $(LIB)


# Definisco i target PHONY (target che non corrispondono a file)
.PHONY: clean clean_exe clean_dip clean_obj clear run debug
	

# Pulisce i file dopo la compilazione
clean: clean_exe clean_dip clean_obj
	

clean_exe:
	$(DEL) $(MAIN)

clean_dip:
	$(DEL) $(DIPENDENZE)

clean_obj:
	$(DEL) *.o


# Cancella i fastidiosi file temporanei che terminano con il carattere '~´
# creati da alcuni editor di testo.
clear:
	$(DEL) *~


# Manda in esecucione il programma
run:
	./$(MAIN)


# Avvia il debug del programma (se si sceglie questa modalita' bisogna aver
# compilato in precedenza il programma con informazioni per il debug)
debug:
	$(GDB) $(MAIN)
