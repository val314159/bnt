#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RIPEMD160.h"
const char nonce_fname[]="~~~nonce~~~";
ripemd160_state self0,self2;
int Verbose=1;
void hashdir(FILE*f){
  static char path[PATH_MAX]="";
  for(;fgets(path,PATH_MAX,f);){
    path[strlen(path)-1]=0;
    if(strcmp(path,nonce_fname)){
      ripemd160_updatef(&self2,path);
      if(Verbose){FILE*f=stdout;stdout=stderr;
	printf(". "),ripemd160_xdump(&self2),printf("[%s]\n", path);
	stderr=f;}}}}
static inline int xbits(int diff,uint8_t*b){ switch(diff){
  case 0:return 1;        case 1:return!(*b&0x80);case 2:return!(*b&0xC0);
  case 3:return!(*b&0xE0);case 4:return!(*b&0xF0);case 5:return!(*b&0xF8);
  case 6:return!(*b&0xFC);case 7:return!(*b&0xFE);case 8:return!*b;
  default:return!*b&&xbits(diff-8,b+1);}}
int bits(int diff){uint8_t b[20];ripemd160_digest(&self0,b);return xbits(diff,b);}
int findnonce(int diff){ uint8_t x;
  hashdir(stdin); fprintf(stderr,">> Solving for difficulty %d...\n", diff);
  for(int n=0;;++n){
    for(self0=self2,x=0;x<5;x++) ripemd160_updatei(&self0,n);
    if(bits(diff)) return n;
    if(!((n+1)%1000000)){ FILE*f=stdout; stdout=stderr;
      printf(">> Tried %2dM hashes.\n",(n+1)/1000000); stdout=f;}}}
void minedir(int diff){
  self2=ripemd160_init(&self0);
  for(int nonce=findnonce(diff);;){
    FILE*f=fopen(nonce_fname,"w+");if(!f)perror(nonce_fname),exit(1);
    for(uint8_t x=0;x<5;x++) putw(nonce,f); fclose(f);
    if(Verbose)printf(". "),ripemd160_xdump(&self0),printf("[%s]\n", nonce_fname);
    ripemd160_dump(&self0); break;}}
int main(int argc,char**argv){
  if(!strcmp(argv[1],"-q")) Verbose=0,++argv;
  minedir(argv[1]?atoi(argv[1]):0);}
