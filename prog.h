#ifndef _PROG_H__
#define _PROG_H__
#include"crules.h"
int expr(void*pv);
int stmt(void*pv);
int dir(void*pv){ int p=T(); int olen=*(long*)pv;
  void*v[1024]={(void*)1,"~~~~##"};
  if(halnum(v)&&dqstr(v))return pushv(pv,cparr(v)),1;
  trimv(pv,olen); return S(p);}
int parms(void*pv){ while(alnum(pv)&&alnum(pv)&&(s(pv,",")||1)){} return 1;}
int exprs(void*pv){ while(expr(pv)&&(s(pv,",")||1)){} return 1;}
int stmts(void*pv){ while(stmt(pv)){} return 1; }
int func(void*pv){ int p=T(); int olen=*(long*)pv;
  void*v[1024]={(void*)1,"~~~~@@"};
  if(alnum(v)&&alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")")&&
     s(v,"{")&&stmts(v)&&s(v,"}"))
    return pushv(pv,cparr(v)),1;
  trimv(pv,olen); return S(p);}
int decl(void*pv){ int p=T(); int olen=*(long*)pv;
  void**v=pv;
  if(dir(v)) return 1;
  trimv(pv,olen); S(p);
  if(func(v)) return 1;
  trimv(pv,olen); return S(p);}
int decls(void*pv){ while(decl(pv)){} return 1; }
int stmt(void*pv){ int p=T(); int olen=*(long*)pv;
  void**v=pv;
  if(expr(v)&&s(v,";"))return 1;
  trimv(pv,olen); return S(p);}
int expr(void*pv){ int p=T(); int olen=*(long*)pv;
  void*v[1024]={(void*)1,"~~~~XX"};
  if(alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")"))return pushv(pv,cparr(v)),1;
  trimv(pv,olen); S(p);
  if(alnum(v))return pushv(pv,cparr(v)),1;
  trimv(pv,olen); return S(p);}
int prog(){ int _,p=T();
  void*v[1024]={(void*)1,"~~~~PP"};
  _=decls(v)&&eof(v);
  printf(" _ = %d\n", _);
  plistln(v);
  return _;}
#endif//_PROG_H__
