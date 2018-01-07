#ifndef _PPROG_H__
#define _PPROG_H__
#include"crules.h"
#define RET_P1() return pushv(pv,cparr(v)),1; trimv(v,olen); S(p)
#define RET__1() return                    1; trimv(v,olen); S(p)
int blk(void*pv);
int dir(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||dir"}; int olen=*(long*)v;
  if(s(v,"#")&&alnum(v)&&dqstr(v)) RET_P1();
  if(s(v,"#")&&alnum(v)&&alnum(v)) RET_P1();
  if(s(v,"#")&&alnum(v)&&idstr(v)) RET_P1();
  if(s(v,"#")&&alnum(v)&&eof(v))   RET_P1();
  return 0;}
int atom(void*pv){ int p=T(); void**v=pv; int olen=*(long*)v;
  if(alnum(v)) RET_P1();
  if(dqstr(v)) RET_P1();
  return 0;}
int expr(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||expr"}; int olen=*(long*)v;
  if(alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")"))RET_P1();
  if(s(v,"!")&&expr(v))                     RET_P1();
  if(s(v,"++")&&expr(v))                    RET_P1();
  if(alnum(v)&&s(v,"=")&&expr(v))           RET_P1();
  if(atom(v))                               RET_P1();
  return 0;}
int exprs(void*pv){ while(expr(pv)&&(s(pv,",")||1)){} return 1;}
int parm(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||parm"}; int olen=*(long*)v;
  if(alnum(v)&&alnum(v)) RET_P1();
  return 0;}
int parms(void*pv){ while(parm(pv)&&(s(pv,",")||1)){} return 1; }
int func(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||func"}; int olen=*(long*)v;
  if(alnum(v)&&alnum(v)&&s(v,"(")&&parms(v)&&s(v,")")&&blk(v)) RET_P1();
  return 0;}
int prot(void*pv){ int p=T(); void*v[1024]={(void*)1,"||||prot"}; int olen=*(long*)v;
  if(alnum(v)&&alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")")&&
     s(v,";")) RET_P1();
  return 0;}
int typ(void*pv){ int p=T();  void*v[1024]={(void*)1,"||||typ"}; int olen=*(long*)v;
  if(alnum(v)&&alnum(v)&&s(v,"=")&&expr(v)&&s(v,";"))RET_P1();
  if(alnum(v)&&alnum(v)&&s(v,";"))                   RET_P1();
  return 0;}
int decl(void*pv){ int p=T(); void**v=pv; int olen=*(long*)v;
  if(dir(v))   RET__1();
  if(prot(v))  RET__1();
  if(func(v))  RET__1();
  if(typ(v))   RET__1();
  return 0;}
int decls(void*pv){ while(decl(pv)){} return 1; }
int stmt(void*pv){ int p=T(); void**v=pv; int olen=*(long*)v;
  if(blk(v))                          RET__1();
  if(s(v,"return")&&expr(v)&&s(v,";"))RET__1();
  if(s(v,"if")&&expr(v)&&stmt(v)&&
     s(v,"else")&&stmt(v))            RET__1();
  if(s(v,"if")&&expr(v)&&stmt(v))     RET__1();
  if(s(v,"for(;;)")&&stmt(v))         RET__1();
  if(decl(v))                         RET__1();
  if(expr(v)&&s(v,";"))               RET__1();
  return 0;} 
int stmts(void*pv){ while(stmt(pv)){} return 1; }
int blk(void*pv){ int p=T(); void**v=pv; int olen=*(long*)v;
  if(s(v,"{")&&stmts(v)&&s(v,"}"))    RET__1();
  return 0;}
int prog(){ int p=T(); void*v[1024]={(void*)1,"||||prog"};
  int _=decls(v)&&eof(v);
  printf(" _ = %d\n", _);
  plistln(v); return _;}
#endif
