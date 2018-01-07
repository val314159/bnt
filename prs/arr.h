#ifndef _ARR_H__
#define _ARR_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pushv(void**v,void*d){if(v)v[++*(long*)v]=d;return 1;}
int trimv(void*v,int z){if(v)*(long*)v=z;return 1;}
int lenv(void*v){ return *(long*)v; }
void* zero=0; char *s1 = "~~~~"; char *s2 = "||||";
int plist(void**vec){
  for(int x=(printf("["),0);++x<=(int)vec[0];)
    if(                      !vec[x])printf("[<null>]");
    else if(*(int*)s1==*(int*)vec[x])printf("[%s]",vec[x]);
    else if(*(int*)s2==*(int*)vec[x])printf("[%s]",vec[x]);
    else plist(vec[x]);
  return printf("]"), 1;}
int plistln(void**vec){ plist(vec); puts(""); return 1; }
void*clonearr(void*v,int s,int s2){
  return memcpy(malloc((s+1)*sizeof(long)),v,(s2+1)*sizeof(long));}
void*mkarr(int sz){return clonearr(&zero,sz,1);}
void*cparr(void*vec){return clonearr(vec,*(long*)vec,*(long*)vec);}
#endif
