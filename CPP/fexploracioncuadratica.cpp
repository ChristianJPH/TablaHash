#include "fexploracioncuadratica.h"

fexploracioncuadratica::fexploracioncuadratica(int tam): fexploracionbase(tam){}

int fexploracioncuadratica::operator()( const DNI& key,int i){
int k = pow(i,2);
return(k%tam);
}
