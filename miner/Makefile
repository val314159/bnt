CFLAGS=-Wall
BINS=rmain minedir
all: clean $(BINS) test
minedir: minedir.o RIPEMD160.o
rmain: rmain.o RIPEMD160.o
depend: ; makedepend *.c
genesis: tmp/0.sig
nextblk: genesis
	@expr `ls chain/b/ | sort -rn | head -1` + 0 | tee tmp/last.blk >/dev/null
	@expr `ls chain/b/ | sort -rn | head -1` + 1 | tee tmp/next.blk >/dev/null
	@ls    chain/b/`cat tmp/last.blk`|sort|head -1|tee tmp/last.sig >/dev/null
	@echo Prev:    `cat tmp/last.sig`|tee chain/t/Prev
	@echo BlockNo: `cat tmp/next.blk`|tee chain/t/BlockNo
	@echo |tee chain/t/_
	@make tmp/t.sig
	@rm tmp/t.sig
tmp/t.sig: $(BINS)
	@cd chain/t;ls|../../minedir -q 8 >.sig
	@cp chain/t/.sig tmp/t.sig
	@mkdir  -p  chain/b/`cat tmp/next.blk`
	@mv chain/t chain/b/`cat tmp/next.blk`/`cat tmp/t.sig`
	@mkdir -p chain/t
tmp/0.sig:
	@echo 0|tee tmp/next.blk
	@mkdir -p chain/t
	@make tmp/t.sig
	@mv   tmp/t.sig tmp/0.sig
tmp/in.xx:
	@mkdir tmp
	@echo -n Rosetta Codex >$@
pytest:
	python pycrypto_test.py sign
	python pycrypto_test.py vrfy
test: $(BINS) tmp/in.xx pytest
	./rmain
	python xx.py
	make genesis
	make nextblk
	make nextblk
	make nextblk
clean: ; rm -fr *.o *~ *.bak $(BINS) chain tmp *.pem my.* *.sig
# DO NOT DELETE

RIPEMD160.o: RIPEMD160.h
minedir.o: RIPEMD160.h
rmain.o: RIPEMD160.h
