#include "fexploraciondispersiondoble.h"

fexploraciondispersiondoble::fexploraciondispersiondoble(char* fdispersio,int tam): fexploracionbase(tam){
if(std::string(fdispersio) == "suma"){
fdispersion = new fdispersionsuma(tam);
} else if (std::string(fdispersio) == "modulo"){
fdispersion = new fdispersionsuma(tam);
} else if (std::string(fdispersio) == "aleatoria"){
fdispersion = new fdispersionaleatoria(tam);
}else
fdispersion = new fdispersionsuma(tam);

}

int fexploraciondispersiondoble::operator()( const DNI& key,int i){
return ((i +(*fdispersion)(key))%tam);
}
