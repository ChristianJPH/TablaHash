#include "fdispersionsuma.h"

fdispersionsuma::fdispersionsuma(int tam): fdispersionbase(tam){}

int fdispersionsuma::operator()( const DNI& key){
//std::cout << "tam: "<<tam << "\n";
//key.ver();
  long d = 0 ;
  unsigned long x = key;
///std::cout << "x: "<< x << "\n";
  while(x > 0){
  long y= x %10;
  d = d +y;
  x = x /10;
  }
  return(d%tam);
  }
