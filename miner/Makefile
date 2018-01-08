CFLAGS=-Wall
BINS=rmain
all: clean $(BINS) test
rmain: rmain.o RIPEMD160.o
depend: ; makedepend *.c
test: $(BINS) ; ./rmain ; python xx.py
clean: ; rm -fr *.o *~ *.bak *.xx $(BINS)
# DO NOT DELETE

rmain.o: RIPEMD160.h
