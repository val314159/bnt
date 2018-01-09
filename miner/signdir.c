#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RIPEMD160.h"

ripemd160_state self0;
ripemd160_state self2;

void dostr(char*const path){
  ripemd160_updatef(&self2,path); printf(". ");
  ripemd160_xdump(&self2);        printf("[%s]\n", path);}

int listdir(FILE*f){
  int op=0,np=0; static char ep[PATH_MAX]="";
  for(;f&&fgets(ep,PATH_MAX,f);(op=np))
    ep[strlen(ep)-1]=0, dostr(ep);
  return fclose(f);}

static inline
int xbits(int d,uint8_t*b){
  switch(d){
  case 0: return 1;
  case 1: return!(*b&0x80);
  case 2: return!(*b&0xC0);
  case 3: return!(*b&0xE0);
  case 4: return!(*b&0xF0);
  case 5: return!(*b&0xF8);
  case 6: return!(*b&0xFC);
  case 7: return!(*b&0xFE);
  case 8: return!*b;
  default:return!*b&&xbits(d-8,b+1);}}

int bits(int diff){
  uint8_t buf[160];
  ripemd160_digest(&self0,buf);
  return xbits(diff,buf);}

void dumpnonce(int nonce){
  printf("%09d) ",nonce),ripemd160_dump(&self0);}

int findnonce(int diff){
  int n=1;
  for(;;++n){
    self0 = self2;
    for(uint8_t x=0;x<5;x++) ripemd160_updatei(&self0,n);
    if(bits(diff)) return n; // self0;
    if(!(n%100000)) dumpnonce(n);}
  return 0;}

void signdir(){
  self0 = self2 = ripemd160_init(0);
  //ripemd160_xdump(&self2);printf("[]\n");
  listdir(stdin);
  //printf("^ "); ripemd160_dump(&self2);
}

const char nonce_fname[]="~~~nonce~~~";

int xdumpnonce(int nonce){
  printf(". ");
  ripemd160_xdump(&self0);
  printf("[%s]\n= %d\n", nonce_fname, nonce);
  return 0;}

int savenonce(int nonce){
  FILE*f=fopen(nonce_fname,"w+");
  if(!f)return 0;
  for(uint8_t x=0;x<5;x++) putw(nonce,f);
  fclose(f);
  return 1;}

int main(int argc,char*argv[]){
  int diff = 0;
  if(argv[1]) diff=atoi(argv[1]);
  printf(">> Solve for diff %d\n", diff);
  signdir();
  int nonce=findnonce(diff);
  if(nonce){
    if(savenonce(nonce))
      return xdumpnonce(nonce);
    perror(nonce_fname); exit(1);}}
