CFLAGS=-Wall
all: Makefile clean test
Makefile: *.c *.h ; make depend
depend: ; makedepend *.c
test: prs ; ./prs<tst/p.c
clean: ; rm -fr *.o prs *~ *.bak
# DO NOT DELETE

prs.o: prog.h crules.h pio.h arr.h
