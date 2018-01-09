CFLAGS=-Wall
BINS=rmain signdir
all: clean $(BINS) test
signdir: signdir.o RIPEMD160.o
rmain: rmain.o RIPEMD160.o
depend: ; makedepend *.c
test: $(BINS) ; ./rmain ; python xx.py ; ls|./signdir 12
clean: ; rm -fr *.o *~ *.bak *.xx $(BINS)
# DO NOT DELETE

RIPEMD160.o: RIPEMD160.h
rmain.o: RIPEMD160.h
signdir.o: RIPEMD160.h
