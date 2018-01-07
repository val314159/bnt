#ifndef _PIO_H__
#define _PIO_H__
#include<ctype.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<strings.h>
int ch;int buflen=3;char buf[1024]="~~~~";
int G(){ch=getc(stdin);if(ch!=EOF)buf[++buflen]=ch;return ch;}
int U(){if(ch!=EOF)ungetc(ch,stdin),--buflen;return 0;}
int S(int p){fseek(stdin,p,0);return 0;}
int W(){for(;;){if(!isspace(G()))return U(),buflen=3,1;}}
int T(){int p=ftell(stdin);W();return p;}
int C(){return buf[++buflen]=0;}
#endif
