#include "fdispersionmodulo.h"

fdispersionmodulo::fdispersionmodulo(int tam): fdispersionbase(tam){}

int fdispersionmodulo::operator()( const DNI& key){

  //std::cout << "El tamaño es: " << tam << "\n";
  int mod = key%tam;
  //std::cout << "El modulo es: " << mod << "\n";

return (mod);
}
