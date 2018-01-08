#include"RIPEMD160.h"

int main(){
  ripemd160_state self0;
  ripemd160_state self;
  
  self0 = ripemd160_init(0);
  self = ripemd160_init(&self);

  self = self0;
  
  unsigned char s[]="Rosetta Codex";
  ripemd160_updates(&self,s);
  ripemd160_dump(&self);
  ripemd160_save(&self,"out.xx");

  ripemd160_state self2;
  ripemd160_load("out.xx",&self2);
  ripemd160_dump(&self2);
}
