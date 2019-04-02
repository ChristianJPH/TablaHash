#include "fexploracionlineal.h"

fexploracionlineal::fexploracionlineal(int tam): fexploracionbase(tam){}

int fexploracionlineal::operator()( const DNI& key,int i){
return((i+1)%tam);
}
