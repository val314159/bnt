CFLAGS=-Wall
BINS=prs
all: clean $(BINS) test
depend: ; makedepend *.c
test: $(BINS) out.xx ; diff out.xx tst/p.xp
out.xx: $(BINS) ; ./prs<tst/p.c>out.xx
clean: ; rm -fr *.o *~ *.bak *.xx $(BINS)
# DO NOT DELETE

prs.o: prog.h crules.h pio.h arr.h
