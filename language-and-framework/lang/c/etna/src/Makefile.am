bin_PROGRAMS = etna
etna_SOURCES = etna.c adtlist.c trasmissione.c elaborazione.c wrapper.c

# set the include path found by configure
INCLUDES= $(all_includes)

# the library search path.
etna_LDFLAGS = $(all_libraries) 
noinst_HEADERS = etna.h config.h trasmissione.h elaborazione.h wrapper.h
etna_LDADD = -lpthread
