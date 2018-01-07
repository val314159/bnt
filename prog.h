#ifndef _PROG_H__
#define _PROG_H__
#include"crules.h"
int decl(void*pv);
int block(void*pv);
int expr(void*pv);
int exprs(void*pv){ while(expr(pv)&&(s(pv,",")||1)){} return 1;}
int dir(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||dir"}; int olen=lenv(v);
  if(s(v,"#")&&alnum(v)&&dqstr(v))return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(s(v,"#")&&alnum(v)&&alnum(v))return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(s(v,"#")&&alnum(v)&&idstr(v))return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(s(v,"#")&&alnum(v)&&eof(v))  return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);  return 0;}
int parm(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||parm"}; int olen=lenv(v);
  if(alnum(v)&&alnum(v))return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);  return 0;}
int parms(void*pv){ while(parm(pv)&&(s(pv,",")||1)){} return 1; }
int prot(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||prot"}; int olen=lenv(v);
  if(alnum(v)&&alnum(v)&&s(v,"(")&&parms(v)&&s(v,")")&&
     s(v,";")) return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);  return 0;}
int func(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||func"}; int olen=lenv(v);
  if(alnum(v)&&alnum(v)&&s(v,"(")&&parms(v)&&s(v,")")&&
     block(v)) return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);  return 0;}
int typ(void*pv){ int p=T();  void*v[1024]={(void*)1,"||||typ"}; int olen=lenv(v);
  if(alnum(v)&&alnum(v)&&s(v,"=")&&
     expr(v)&&s(v,";"))           return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(alnum(v)&&alnum(v)&&s(v,";"))return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);  return 0;}
int decl(void*pv){ int p=T(); void**v=pv; int olen=lenv(v);
  if(dir(v)) return 1; trimv(v,olen); S(p);
  if(prot(v))return 1; trimv(v,olen); S(p);
  if(func(v))return 1; trimv(v,olen); S(p);
  if(typ(v)) return 1; trimv(v,olen); S(p);  return 0;}
int decls(void*pv){ while(decl(pv)){} return 1; }
int stmt(void*pv){ int p=T(); void**v=pv; int olen=lenv(v);
  if(block(v))                        return 1; trimv(v,olen); S(p);
  if(s(v,"return")&&expr(v)&&s(v,";"))return 1; trimv(v,olen); S(p);
  if(s(v,"if")&&expr(v)&&stmt(v)&&s(v,"else")&&stmt(v))return 1; trimv(v,olen); S(p);
  if(s(v,"if")&&expr(v)&&stmt(v))     return 1; trimv(v,olen); S(p);
  if(s(v,"for(;;)")&&stmt(v))         return 1; trimv(v,olen); S(p);
  if(decl(v))                         return 1; trimv(v,olen); S(p);
  if(expr(v)&&s(v,";"))               return 1; trimv(v,olen); S(p);  return 0;}
int stmts(void*pv){ while(stmt(pv)){} return 1; }
int block(void*pv){ int p=T(); void**v=pv; int olen=lenv(v);
  if(s(v,"{")&&stmts(v)&&s(v,"}"))return 1; trimv(v,olen); S(p);  return 0;}
int funcall(void*pv){ int p=T(); void**v=pv; int olen=lenv(v);
  if(alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")"))return 1; trimv(v,olen); S(p);  return 0;}
int atom(void*pv){ int p=T(); void**v=pv; int olen=lenv(v);
  if(alnum(v)) return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(dqstr(v)) return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);  return 0;}
int expr(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||expr"}; int olen=lenv(v);
  if(funcall(v))         return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(s(v,"!")&&expr(v))  return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(s(v,"++")&&expr(v)) return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(s(v,"(")&&funcall(v)&&
     s(v,")"))           return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(alnum(v)&&s(v,"=")&&
     expr(v))            return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);
  if(atom(v))            return pushv(pv,cparr(v)),1; trimv(v,olen); S(p);  return 0;}
int prog(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||prog"}; int olen=lenv(v);
  if(decls(v)&&eof(v)) return pushv(pv,cparr(v)),plistln(v),1; trimv(v,olen); S(p);  return 0;}
#endif
