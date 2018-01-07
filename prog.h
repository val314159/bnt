#ifndef _PROG_H__
#define _PROG_H__
#include"crules.h"
int func(void*pv);
int prot(void*pv);
int expr(void*pv);
int stmt(void*pv);
int dir(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||dir"}; int olen=*(long*)v;
  if(s(v,"#")&&alnum(v)&&dqstr(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p);
  if(s(v,"#")&&alnum(v)&&alnum(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p);
  if(s(v,"#")&&alnum(v)&&idstr(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p);
  if(s(v,"#")&&alnum(v)&&eof(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p); return 0;}
int parm(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||parm"}; int olen=*(long*)v;
  if(alnum(v)&&alnum(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p); return 0;}
int parms(void*pv){ while(parm(pv)&&(s(pv,",")||1)){} return 1; }
int typ(void*pv){ int p=T();  void*v[1024]={(void*)1,"||||typ"}; int olen=*(long*)v;
  if(alnum(v)&&alnum(v)&&s(v,"=")&&expr(v)&&s(v,";"))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p);
  if(alnum(v)&&alnum(v)&&s(v,";"))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p); return 0;}
int decl(void*pv){ int p=T(); void**v=pv; int olen=*(long*)v;
  if(dir(v))return 1;
  trimv(v,olen); S(p);
  if(prot(v))return 1;
  trimv(v,olen); S(p);
  if(func(v))return 1;
  trimv(v,olen); S(p);
  if(typ(v))return 1;
  trimv(v,olen); S(p); return 0;}
int decls(void*pv){ while(decl(pv)){} return 1; }
int stmts(void*pv){ while(stmt(pv)){} return 1; }
int stmt(void*pv){ int p=T(); void**v=pv; int olen=*(long*)v;
  if(s(v,"{")&&stmts(v)&&s(v,"}"))return 1;
  trimv(v,olen); S(p);
  if(s(v,"return")&&expr(v)&&s(v,";"))return 1;
  trimv(v,olen); S(p);
  if(s(v,"if")&&expr(v)&&stmt(v)&&s(v,"else")&&stmt(v))return 1;
  trimv(v,olen); S(p);
  if(s(v,"if")&&expr(v)&&stmt(v))return 1;
  trimv(v,olen); S(p);
  if(s(v,"for(;;)")&&stmt(v))return 1;
  trimv(v,olen); S(p);
  if(decl(v))return 1;
  trimv(v,olen); S(p);
  if(expr(v)&&s(v,";"))return 1;
  trimv(v,olen); S(p); return 0;}
int exprs(void*pv){ while(expr(pv)&&(s(pv,",")||1)){} return 1;}
int expr(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||expr"}; int olen=*(long*)v;
  if(alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")"))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p);
  if(s(v,"!")&&expr(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p);
  if(s(v,"++")&&expr(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p);
  if(alnum(v)&&s(v,"=")&&expr(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p);
  if(alnum(v))return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p); return 0;}
int func(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||func"}; int olen=*(long*)v;
  if(alnum(v)&&alnum(v)&&s(v,"(")&&parms(v)&&s(v,")")&&
     s(v,"{")&&stmts(v)&&s(v,"}")) return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p); return 0;}
int prot(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||prot"}; int olen=*(long*)v;
  if(alnum(v)&&alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")")&&
     s(v,";")) return pushv(pv,cparr(v)),1;
  trimv(v,olen); S(p); return 0;}
int prog(){ int p=T(); void*v[1024]={(void*)1,"||||prog"};
  int _=decls(v)&&eof(v);
  printf(" _ = %d\n", _);
  plistln(v); return _;}
#endif
