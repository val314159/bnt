#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dostr(char*const path,int len){
  printf("%d:%s\n", len, path);
}

int listdir(char*const path){
  static char ep[PATH_MAX]="";
  int op=0,np=0;
  FILE*f=fopen(path,"r");
  if(!f)perror(path),exit(1);
  for(;f&&fgets(ep,PATH_MAX,f);(op=np)){
    if((np=ftell(f))>0)ep[np-++op]=0;
    dostr(ep,np-op);}
  return fclose(f);}

int main(int argc,char*argv[]){
  int k,rval;
  for (rval = 0, k = 1; k < argc; k++)
    if (listdir(argv[k]) != 0)
      rval = 1;
  return rval;}
