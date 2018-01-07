#ifndef _PPROG_H__
#define _PPROG_H__
#include"crules.h"
#define SET_P1(x) int p=T(); void*v[1024]={(void*)1,"||||"x}; int olen=*(long*)v;
#define SET__1()  int p=T(); void**v=pv; int olen=*(long*)v;
#define __FUNC_P1(t,n,a) t n a { int p=T(); void*v[1024]={(void*)1,"||||"x}; int olen=*(long*)v;
#define __FUNC__1(t,n,a) t n a { int p=T(); void**v=pv; int olen=*(long*)v;
#define RET_P1()  return pushv(pv,cparr(v)),1; trimv(v,olen); S(p)
#define RET__1()  return                    1; trimv(v,olen); S(p)
#define MATCHP1(x) if(x)return pushv(pv,cparr(v)),1; trimv(v,olen); S(p)
#define MATCH_1(x) if(x)return                    1; trimv(v,olen); S(p)
#define MATLOOP(x) while(x){} return 1;
#define ___ {
#define __ return 0;}
int blk(void*pv);
int dir(void*pv){ SET_P1("dir");
  if(s(v,"#")&&alnum(v)&&dqstr(v)) RET_P1();
  if(s(v,"#")&&alnum(v)&&alnum(v)) RET_P1();
  if(s(v,"#")&&alnum(v)&&idstr(v)) RET_P1();
  if(s(v,"#")&&alnum(v)&&eof(v))   RET_P1();
  return 0;}
int atom(void*pv){ SET__1();
  if(alnum(v)) RET_P1();
  if(dqstr(v)) RET_P1();
  return 0;}
int exprs(void*pv){
  MATLOOP(expr(pv)&&(s(pv,",")||1)); }
__FUNC_P1(int,parm,(void*pv)){
  MATCHP1(alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")"));
  MATCHP1(s(v,"!")&&expr(v));
  MATCHP1(s(v,"++")&&expr(v));                  
  MATCHP1(alnum(v)&&s(v,"=")&&expr(v));
  MATCHP1(atom(v));__}
__FUNC_P1(int,expr){
  MATCH_1(alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")"));
  MATCH_1(s(v,"!")&&expr(v));
  MATCH_1(s(v,"++")&&expr(v));                  
  MATCH_1(alnum(v)&&s(v,"=")&&expr(v));
  MATCH_1(atom(v));__}
int parm(void*pv){___ SET_P1("parm");
  if(alnum(v)&&alnum(v)) RET_P1();__}
int parms(void*pv){ MATLOOP(parm(pv)&&(s(pv,",")||1)); }
int func(void*pv){___ SET_P1("func");
  MATCH_P1(alnum(v)&&alnum(v)&&s(v,"(")&&parms(v)&&s(v,")")&&blk(v)); __}
int prot(void*pv){ SET_P1("prot");
  if(alnum(v)&&alnum(v)&&s(v,"(")&&exprs(v)&&s(v,")")&&
     s(v,";")) RET_P1();
  return 0;}
int typ(void*pv){ SET_P1("typ");
  if(alnum(v)&&alnum(v)&&s(v,"=")&&expr(v)&&s(v,";"))RET_P1();
  if(alnum(v)&&alnum(v)&&s(v,";"))                   RET_P1();
  return 0;}
int decl(void*pv){ SET__1();
  if(dir(v))   RET__1();
  if(prot(v))  RET__1();
  if(func(v))  RET__1();
  if(typ(v))   RET__1();
  return 0;}
int decls(void*pv){ while(decl(pv)){} return 1; }
int stmt(void*pv){ SET__1();
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
int blk(void*pv){ SET__1();
  if(s(v,"{")&&stmts(v)&&s(v,"}"))    RET__1();
  return 0;}
int prog(){ SET_P1("prog");
  int _=decls(v)&&eof(v);
  printf(" _ = %d\n", _);
  plistln(v); return _;}
#endif
