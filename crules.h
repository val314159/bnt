#ifndef _CRULES_H__
#define _CRULES_H__
#include"pio.h"
#include"arr.h"
int P(void*v){return C(),pushv(v,strdup(buf));}
int eof(void*v){int p=T();if(ch!=EOF)return S(p);
  return strcpy(buf,"||||<<eof>>"),buflen=strlen(buf),P(v);}
int alnum(void*v){int p=T();if(!isalnum(G()))return S(p);
  for(;;){if(!isalnum(G()))return U(),P(v);}}
int dqstr(void*v){int p=T();if('"'!=G())return S(p);
  for(;;){if(EOF==G())return S(p);if(ch== '"')return P(v);}}
int sqstr(void*v){int p=T();if('\''!=G())return S(p);
  for(;;){if(EOF==G())return S(p);if(ch=='\'')return P(v);}}
int idstr(void*v){int p=T();if('<'!=G())return S(p);
  for(;;){if(EOF==G())return S(p);if(ch=='>')return P(v);}}
int s(void*v,char*x){int p=T();
  for(;;){if(!*x)return P(v);if(G()!=*x)return S(p);++x;}}
#endif
