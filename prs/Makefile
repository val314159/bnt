CFLAGS=-Wall
BINS=prs
all: clean $(BINS) test
depend: ; makedepend *.c
test: $(BINS) ; ./prs<tst/p.c
clean: ; rm -fr *.o *~ *.bak *.xx $(BINS)
# DO NOT DELETE

prs.o: prog.h crules.h pio.h arr.h
