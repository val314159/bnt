#ifndef _ARR_H__
#define _ARR_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SZ sizeof(void*)
int pushv(void**v,void*d){v[++*(long*)v]=d;return 1;}
int trimv(void*v,int z){return *(long*)v=z;}
void* zero=0; char *s1 = "~~~~"; char *s2 = "||||";
int plist(void**vec){
  for(int x=(printf("["),0);++x<=(int)vec[0];)
    if(                      !vec[x])printf("[<null>]");
    else if(*(int*)s1==*(int*)vec[x])printf("[%s]",vec[x]);
    else if(*(int*)s2==*(int*)vec[x])printf("[%s]",vec[x]);
    else plist(vec[x]);
  return printf("]"), 0;}
int plistln(void**vec){ plist(vec); puts(""); return 0; }
void*clonearr(void*src,int sz,int sz2){
  return memcpy(malloc((sz+1)*SZ),src,(sz2+1)*SZ);}
void*mkarr(int sz){return clonearr(&zero,sz,1);}
void*cparr(void*vec){return clonearr(vec,*(long*)vec,*(long*)vec);}
#endif
