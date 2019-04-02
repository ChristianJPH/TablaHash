#include "fdispersionaleatoria.h"

fdispersionaleatoria::fdispersionaleatoria(int tam): fdispersionbase(tam) {}

int fdispersionaleatoria::operator()( const DNI& key){
srand(key);
return (rand()%tam);
}
