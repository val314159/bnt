CFLAGS=-Wall
BINS=rmain minedir
all: clean $(BINS) test
minedir: minedir.o RIPEMD160.o
rmain: rmain.o RIPEMD160.o
depend: ; makedepend *.c
genesis: 0.sig
nextblk: genesis
	@expr `ls tst/chain/b/ | sort -rn | head -1` + 0 | tee last.blk >/dev/null
	@expr `ls tst/chain/b/ | sort -rn | head -1` + 1 | tee next.blk >/dev/null
	@ls tst/chain/b/`cat last.blk`|sort|head -1|tee last.sig >/dev/null
	@echo Prev: `cat last.sig` |tee tst/chain/t/Prev
	@echo BlockNo: `cat next.blk` |tee tst/chain/t/BlockNo
	@echo |tee tst/chain/t/_
	@make t.sig
	@rm t.sig
t.sig: $(BINS)
	@cd tst/chain/t;ls|../../../minedir -q 8 >.sig
	@cp tst/chain/t/.sig t.sig
	@mkdir -p tst/chain/b/`cat next.blk`
	@mv tst/chain/t tst/chain/b/`cat next.blk`/`cat t.sig`
	@mkdir -p tst/chain/t
0.sig:
	@echo 0|tee next.blk
	@mkdir -p tst/chain/t
	@make t.sig
	@mv t.sig 0.sig
test: $(BINS)
	./rmain
	python xx.py
	make clean
	make genesis
	make nextblk
	make nextblk
	make nextblk
clean: ; rm -fr *.o *~ *.bak *.xx $(BINS) tst/0* *.sig *.blk chain
# DO NOT DELETE

RIPEMD160.o: RIPEMD160.h
minedir.o: RIPEMD160.h
rmain.o: RIPEMD160.h
