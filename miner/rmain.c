#include"RIPEMD160.h"
#include<stdio.h>

int main(){
  ripemd160_state self0 = ripemd160_init(0);
  ripemd160_state self  = self0;
  
  char s[]="Rosetta Code";
  ripemd160_updates(&self,s);
  ripemd160_updatec(&self,'x');
  ripemd160_dump(&self);
  ripemd160_save(&self,"out.xx");

  ripemd160_state self2;
  ripemd160_load("out.xx",&self2);
  ripemd160_dump(&self2);

  ripemd160_state self3;
  ripemd160_init(&self3);
  ripemd160_updatef(&self3,"xx");
  ripemd160_dump(&self3);
}
