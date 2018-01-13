/*
 * Modified in 2018 by Joel M Ward "@val314159" <jmward@gmail.com>
 */
/*
 *
 *  RIPEMD160.c : RIPEMD-160 implementation
 *
 * Written in 2008 by Dwayne C. Litzenberger <dlitz@dlitz.net>
 *
 * ===================================================================
 * The contents of this file are dedicated to the public domain.  To
 * the extent that dedication to the public domain is not available,
 * everyone is granted a worldwide, perpetual, royalty-free,
 * non-exclusive license to exercise all rights associated with the
 * contents of this file for any purpose whatsoever.
 * No rights are reserved.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * ===================================================================
 *
 * Country of origin: Canada
 *
 * This implementation (written in C) is based on an implementation the author
 * wrote in Python.
 *
 * This implementation was written with reference to the RIPEMD-160
 * specification, which is available at:
 * http://homes.esat.kuleuven.be/~cosicart/pdf/AB-9601/
 *
 * It is also documented in the _Handbook of Applied Cryptography_, as
 * Algorithm 9.55.  It's on page 30 of the following PDF file:
 * http://www.cacr.math.uwaterloo.ca/hac/about/chap9.pdf
 *
 * The RIPEMD-160 specification doesn't really tell us how to do padding, but
 * since RIPEMD-160 is inspired by MD4, you can use the padding algorithm from
 * RFC 1320.
 *
 * According to http://www.users.zetnet.co.uk/hopwood/crypto/scan/md.html:
 *   "RIPEMD-160 is big-bit-endian, little-byte-endian, and left-justified."
 */

#include "RIPEMD160.h"

#include <stdint.h>
#include <assert.h>
#include <string.h>

/* cyclic left-shift the 32-bit word n left by s bits */
#define ROL(s, n) (((n) << (s)) | ((n) >> (32-(s))))

/* Initial values for the chaining variables.
 * This is just 0123456789ABCDEFFEDCBA9876543210F0E1D2C3 in little-endian. */
static const uint32_t initial_h[5] = { 0x67452301u, 0xEFCDAB89u, 0x98BADCFEu, 0x10325476u, 0xC3D2E1F0u };

/* Ordering of message words.  Based on the permutations rho(i) and pi(i), defined as follows:
 *
 *  rho(i) := { 7, 4, 13, 1, 10, 6, 15, 3, 12, 0, 9, 5, 2, 14, 11, 8 }[i]  0 <= i <= 15
 *
 *  pi(i) := 9*i + 5 (mod 16)
 *
 *  Line  |  Round 1  |  Round 2  |  Round 3  |  Round 4  |  Round 5
 * -------+-----------+-----------+-----------+-----------+-----------
 *  left  |    id     |    rho    |   rho^2   |   rho^3   |   rho^4
 *  right |    pi     |   rho pi  |  rho^2 pi |  rho^3 pi |  rho^4 pi
 */

/* Left line */
static const uint8_t RL[5][16] = {
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },   /* Round 1: id */
    { 7, 4, 13, 1, 10, 6, 15, 3, 12, 0, 9, 5, 2, 14, 11, 8 },   /* Round 2: rho */
    { 3, 10, 14, 4, 9, 15, 8, 1, 2, 7, 0, 6, 13, 11, 5, 12 },   /* Round 3: rho^2 */
    { 1, 9, 11, 10, 0, 8, 12, 4, 13, 3, 7, 15, 14, 5, 6, 2 },   /* Round 4: rho^3 */
    { 4, 0, 5, 9, 7, 12, 2, 10, 14, 1, 3, 8, 11, 6, 15, 13 }    /* Round 5: rho^4 */
};

/* Right line */
static const uint8_t RR[5][16] = {
    { 5, 14, 7, 0, 9, 2, 11, 4, 13, 6, 15, 8, 1, 10, 3, 12 },   /* Round 1: pi */
    { 6, 11, 3, 7, 0, 13, 5, 10, 14, 15, 8, 12, 4, 9, 1, 2 },   /* Round 2: rho pi */
    { 15, 5, 1, 3, 7, 14, 6, 9, 11, 8, 12, 2, 10, 0, 4, 13 },   /* Round 3: rho^2 pi */
    { 8, 6, 4, 1, 3, 11, 15, 0, 5, 12, 2, 13, 9, 7, 10, 14 },   /* Round 4: rho^3 pi */
    { 12, 15, 10, 4, 1, 5, 8, 7, 6, 2, 13, 14, 0, 3, 9, 11 }    /* Round 5: rho^4 pi */
};

/*
 * Shifts - Since we don't actually re-order the message words according to
 * the permutations above (we could, but it would be slower), these tables
 * come with the permutations pre-applied.
 */

/* Shifts, left line */
static const uint8_t SL[5][16] = {
    { 11, 14, 15, 12, 5, 8, 7, 9, 11, 13, 14, 15, 6, 7, 9, 8 }, /* Round 1 */
    { 7, 6, 8, 13, 11, 9, 7, 15, 7, 12, 15, 9, 11, 7, 13, 12 }, /* Round 2 */
    { 11, 13, 6, 7, 14, 9, 13, 15, 14, 8, 13, 6, 5, 12, 7, 5 }, /* Round 3 */
    { 11, 12, 14, 15, 14, 15, 9, 8, 9, 14, 5, 6, 8, 6, 5, 12 }, /* Round 4 */
    { 9, 15, 5, 11, 6, 8, 13, 12, 5, 12, 13, 14, 11, 8, 5, 6 }  /* Round 5 */
};

/* Shifts, right line */
static const uint8_t SR[5][16] = {
    { 8, 9, 9, 11, 13, 15, 15, 5, 7, 7, 8, 11, 14, 14, 12, 6 }, /* Round 1 */
    { 9, 13, 15, 7, 12, 8, 9, 11, 7, 7, 12, 7, 6, 15, 13, 11 }, /* Round 2 */
    { 9, 7, 15, 11, 8, 6, 6, 14, 12, 13, 5, 14, 13, 13, 7, 5 }, /* Round 3 */
    { 15, 5, 8, 11, 14, 14, 6, 14, 6, 9, 12, 9, 12, 5, 15, 8 }, /* Round 4 */
    { 8, 5, 12, 9, 12, 5, 14, 6, 8, 13, 6, 5, 15, 13, 11, 11 }  /* Round 5 */
};

/* Boolean functions */
#define F1(x, y, z) ((x) ^ (y) ^ (z))
#define F2(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define F3(x, y, z) (((x) | ~(y)) ^ (z))
#define F4(x, y, z) (((x) & (z)) | ((y) & ~(z)))
#define F5(x, y, z) ((x) ^ ((y) | ~(z)))

/* Round constants, left line */
static const uint32_t KL[5] = {
    0x00000000u,    /* Round 1: 0 */
    0x5A827999u,    /* Round 2: floor(2**30 * sqrt(2)) */
    0x6ED9EBA1u,    /* Round 3: floor(2**30 * sqrt(3)) */
    0x8F1BBCDCu,    /* Round 4: floor(2**30 * sqrt(5)) */
    0xA953FD4Eu     /* Round 5: floor(2**30 * sqrt(7)) */
};

/* Round constants, right line */
static const uint32_t KR[5] = {
    0x50A28BE6u,    /* Round 1: floor(2**30 * cubert(2)) */
    0x5C4DD124u,    /* Round 2: floor(2**30 * cubert(3)) */
    0x6D703EF3u,    /* Round 3: floor(2**30 * cubert(5)) */
    0x7A6D76E9u,    /* Round 4: floor(2**30 * cubert(7)) */
    0x00000000u     /* Round 5: 0 */
};

ripemd160_state ripemd160_init(ripemd160_state *self){
  ripemd160_state bak; self=self?:&bak;
  memcpy(self->h, initial_h, RIPEMD160_DIGEST_SIZE);
  memset(&self->buf, 0, sizeof(self->buf));
  self->length = 0; self->bufpos = 0; return *self;}
static void ripemd160_compress(ripemd160_state *s){ uint8_t w;
  uint32_t T, AR=s->h[0],AL=AR,BR=s->h[1],BL=BR,
    CR=s->h[2],CL=CR,DR=s->h[3],DL=DR,ER=s->h[4],EL=ER;
#define ROUND(r,X,Y);							\
  for(w=0;w<16;w++)T=ROL(SL[r][w],AL+X(BL,CL,DL)+s->buf.w[RL[r][w]]+KL[r])+EL,AL=EL,EL=DL,DL=ROL(10,CL),CL=BL,BL=T; \
  for(w=0;w<16;w++)T=ROL(SR[r][w],AR+Y(BR,CR,DR)+s->buf.w[RR[r][w]]+KR[r])+ER,AR=ER,ER=DR,DR=ROL(10,CR),CR=BR,BR=T;
  ROUND(0,F1,F5);
  ROUND(1,F2,F4);
  ROUND(2,F3,F3);
  ROUND(3,F4,F2);
  ROUND(4,F5,F1);
  T      =s->h[1]+CL+DR; s->h[1]=s->h[2]+DL+ER; s->h[2]=s->h[3]+EL+AR;
  s->h[3]=s->h[4]+AL+BR; s->h[4]=s->h[0]+BL+CR; s->h[0]=T;  s->bufpos=0;}
void ripemd160_update(ripemd160_state *self, const uint8_t *p, int length){
  for(unsigned bytes_needed=64-self->bufpos; length>0; bytes_needed=64-self->bufpos){
    if((unsigned)length<bytes_needed) bytes_needed=length;
    memcpy(&self->buf.b[self->bufpos],p,bytes_needed);
    self->bufpos+=bytes_needed; self->length+=bytes_needed<<3;	  
    if((unsigned)length==bytes_needed) break;
    p+=bytes_needed; ripemd160_compress(self); length-=bytes_needed;}}
    
int ripemd160_digest(const ripemd160_state *self, uint8_t *out){
    ripemd160_state tmp = *self;
    tmp.buf.b[tmp.bufpos++] = 0x80;
    if (tmp.bufpos > 56) { tmp.bufpos = 64; ripemd160_compress(&tmp); }
    tmp.buf.w[14] = (uint32_t) (tmp.length & 0xFFFFffffu);
    tmp.buf.w[15] = (uint32_t) ((tmp.length >> 32) & 0xFFFFffffu);
    tmp.bufpos = 64;
    ripemd160_compress(&tmp);
    memcpy(out, &tmp.h, RIPEMD160_DIGEST_SIZE);
    return 1;}

#include<stdio.h>

void ripemd160_load(const char*filename,ripemd160_state *source){
  FILE*f = fopen(filename,"r");
  if(f)printf("fread  = %ld\n", fread(source,1,sizeof(*source),f)),fclose(f);}

void ripemd160_save(const ripemd160_state *dest,const char*filename){
  FILE*f = fopen(filename,"w");
  if(f)printf("fwrite = %ld\n", fwrite(dest,1,sizeof(*dest),f)),fclose(f);}

void ripemd160_xdump(const ripemd160_state*self){
  uint8_t buf[10240]; ripemd160_digest(self,buf);
  for(int n=0;n<20;n++) printf("%02x", buf[n]);}
void ripemd160_dump(const ripemd160_state*self){
  uint8_t buf[10240]; ripemd160_digest(self,buf);
  for(int n=0;n<20;n++) printf("%02x", buf[n]); printf("\n");}

void ripemd160_updatef(ripemd160_state *self, const char*filename){
  int sz = 64; uint8_t buf[sz]; FILE*f=fopen(filename,"r"); if(!f)return;
  while((sz=fread(buf,1,sz,f))>0) ripemd160_update(self,buf,sz); fclose(f);}
