#include"RIPEMD160.h"

void ripemd160_updates(ripemd160_state*self,const char*s){
  ripemd160_update(self,(const unsigned char*)s,strlen(s));
}
void ripemd160_updatec(ripemd160_state*self,unsigned char c){
  ripemd160_update(self,&c,1);
}
void ripemd160_updatei(ripemd160_state*self,int i){
  ripemd160_update(self,(const unsigned char*)&i,sizeof(int));
}

int main(){
  ripemd160_state self0;
  ripemd160_state self;
  
  self0 = ripemd160_init(0);
  self = ripemd160_init(&self);

  self = self0;
  
  char s[]="Rosetta Codex";
  ripemd160_updates(&self,s);
  ripemd160_dump(&self);
  ripemd160_save(&self,"out.xx");

  ripemd160_state self2;
  ripemd160_load("out.xx",&self2);
  ripemd160_dump(&self2);
}
