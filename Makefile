CFLAGS=-Wall
BINS=prs rmain
all: clean $(BINS) test
rmain: rmain.o RIPEMD160.o
depend: ; makedepend *.c
test: $(BINS) ; ./prs<tst/p.c ; ./rmain
clean: ; rm -fr *.o *~ *.bak *.xx $(BINS)
# DO NOT DELETE

prs.o: prog.h crules.h pio.h arr.h
rmain.o: RIPEMD160.h
