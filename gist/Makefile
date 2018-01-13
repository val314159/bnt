RUN=run --rm --name dev --env-file=main.env
CFLAGS=-Wall
BINS=rmain minedir
all: pytest mkchain
pytest:
	python pycrypto_test.py test
	python pycrypto_test.py keys
	python pycrypto_test.py sign   env.sh
	python pycrypto_test.py verify env.sh
mkchain: $(BINS)
	rm -fr c
	. env.sh;mkchain  c
	. env.sh;mineblk  c
	. env.sh;mineblk  c
	. env.sh;mineblk  c
	. env.sh;mineblk  c
	. env.sh;mineblk  c
	. env.sh;mineblk  c
	. env.sh;mineblk  c
	. env.sh;mineblk  c
	tree -a c
build: ;bash -lc 'docker build   -t dev .'
drun:  ;bash -lc "docker ${RUN}  -d dev sleep 1000000000"
irun:  ;bash -lc "docker ${RUN} -it dev"
exec:  ;bash -lc "docker exec   -it dev bash"
delete:;bash -lc "docker rm      -f dev"||echo
clean1:;rm -fr *~ *.pyc c
clean2:;rm -fr *.o *~ *.bak $(BINS) chain tmp *.pem my.* *.sig
clean: clean1 clean2
minedir: minedir.o RIPEMD160.o
rmain: rmain.o RIPEMD160.o
depend: ; makedepend *.c
# DO NOT DELETE

RIPEMD160.o: RIPEMD160.h
minedir.o: RIPEMD160.h
rmain.o: RIPEMD160.h
